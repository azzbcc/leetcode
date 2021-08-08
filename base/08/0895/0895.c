// 实现 FreqStack，模拟类似栈的数据结构的操作的一个类。
//
// FreqStack 有两个函数：
//
//
// push(int x)，将整数 x 推入栈中。
// pop()，它移除并返回栈中出现最频繁的元素。
//
// 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
//
//
//
//
//
//
// 示例：
//
// 输入：
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// 输出：[null,null,null,null,null,null,null,5,7,5,4]
// 解释：
// 执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：
//
// pop() -> 返回 5，因为 5 是出现频率最高的。
// 栈变成 [5,7,5,7,4]。
//
// pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
// 栈变成 [5,7,5,4]。
//
// pop() -> 返回 5 。
// 栈变成 [5,7,4]。
//
// pop() -> 返回 4 。
// 栈变成 [5,7]。
//
//
//
//
// 提示：
//
//
// 对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
// 如果栈的元素数目为零，则保证不会调用 FreqStack.pop()。
// 单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
// 单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
// 所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。
//
//
//
// Related Topics 栈 哈希表
// 👍 95 👎 0
#define HASH_MAX_SIZE  9997
#define MAX_STACK_SIZE 10001

typedef struct list_node {
    int val;
    struct list_node *next;
} * list_t;
static list_t list_new(int val) {
    list_t l = calloc(1, sizeof(struct list_node));
    l->val = val, l->next = NULL;
    return l;
}
static void stack_push(list_t s, int val) {
    list_t l = list_new(val);
    l->next = s->next, s->next = l;
}
static int stack_pop(list_t s) {
    int val;
    list_t l = NULL;
    if (!s->next) return -1;
    l = s->next, val = l->val, s->next = s->next->next;
    free(l);
    return val;
}
static void list_free(list_t l) {
    if (l->next) list_free(l->next);
    free(l);
}
typedef struct hash_node {
    int val;
    int count;
    struct hash_node *next;
} * hash_node_t, *hash_t[HASH_MAX_SIZE];
static uint32_t h(int val) {
    return val % HASH_MAX_SIZE;
}
static hash_node_t hash_find(hash_t t, int val) {
    hash_node_t cur = t[h(val)];
    while (cur && cur->val < val) {
        cur = cur->next;
    }
    if (!cur || cur->val > val) return NULL;
    return cur;
}
static hash_node_t hash_node_new(int val) {
    hash_node_t n = calloc(1, sizeof(struct hash_node));
    n->val = val, n->count = 1, n->next = NULL;
    return n;
}
static hash_node_t hash_add(hash_t t, int val) {
    hash_node_t n, cur = hash_find(t, val);
    if (cur) {
        cur->count += 1;
        return cur;
    }
    cur = t[h(val)], n = hash_node_new(val);
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        n->next = cur->next, cur->next = n;
    }
    return n;
}
static void hash_node_free(hash_node_t n) {
    if (!n) return;
    if (n->next) hash_node_free(n->next);
    free(n);
}
static void hash_free(hash_t t) {
    for (int i = 0; i < HASH_MAX_SIZE; hash_node_free(t[i++])) {}
}
typedef struct {
    int max_count;
    list_t stacks[MAX_STACK_SIZE];
    hash_t count_map;
} FreqStack;

FreqStack *freqStackCreate() {
    FreqStack *stack = calloc(1, sizeof(*stack));

    stack->max_count = 0;
    memset(stack->stacks, 0, sizeof(stack->stacks));
    memset(stack->count_map, 0, sizeof(stack->count_map));

    return stack;
}

void freqStackPush(FreqStack *stack, int x) {
    hash_node_t node = hash_add(stack->count_map, x);

    if (stack->max_count < node->count) stack->max_count = node->count;
    if (!stack->stacks[node->count]) stack->stacks[node->count] = list_new(0);

    stack_push(stack->stacks[node->count], x);
}

int freqStackPop(FreqStack *stack) {
    int val = stack_pop(stack->stacks[stack->max_count]);

    hash_find(stack->count_map, val)->count--;
    if (!stack->stacks[stack->max_count]->next) stack->max_count--;

    return val;
}

void freqStackFree(FreqStack *stack) {
    for (int i = 1; stack->stacks[i]; list_free(stack->stacks[i++])) {}
    hash_free(stack->count_map);
    free(stack);
}
