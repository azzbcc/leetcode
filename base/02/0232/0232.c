// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
// 实现 MyQueue 类：
//
//
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//
// 说明：
//
//
// 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//
//
//
//
// 示例 1：
//
//
// 输入：
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// 输出：
// [null, null, null, 1, 1, false]
//
// 解释：
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false
//
//
//
//
//
//
//
// 提示：
//
//
// 1 <= x <= 9
// 最多调用 100 次 push、pop、peek 和 empty
// 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
//
//
//
//
// 进阶：
//
//
// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n)
// ，即使其中一个操作可能花费较长时间。
//
//
// Related Topics 栈 设计 队列 👍 1068 👎 0

typedef struct stack_node *stack_t;
struct stack_node {
    int val;
    stack_t next;
};
static stack_t stack_new(int val, stack_t next) {
    stack_t s = malloc(sizeof(*s));
    s->val = val, s->next = next;
    return s;
}
bool stack_empty(stack_t s) {
    return s == NULL;
}
void stack_push(stack_t *s, int val) {
    *s = stack_new(val, *s);
}
int stack_peak(stack_t s) {
    return s ? s->val : -1;
}
int stack_pop(stack_t *s) {
    int val = stack_peak(*s);
    if (stack_empty(*s)) return val;

    stack_t next = (*s)->next;
    free(*s);
    *s = next;
    return val;
}
void stack_destroy(stack_t *s) {
    for (stack_t now = *s, next; now; now = next) {
        next = now->next;
        free(now);
    }
    *s = NULL;
}
typedef struct {
    stack_t in, out;
} MyQueue;
static void queue_migrate(MyQueue *q) {
    if (!stack_empty(q->out)) return;
    for (; !stack_empty(q->in);) {
        stack_push(&q->out, stack_pop(&q->in));
    }
}
MyQueue *myQueueCreate() {
    return calloc(1, sizeof(MyQueue));
}
void myQueuePush(MyQueue *q, int x) {
    stack_push(&q->in, x);
}
int myQueuePop(MyQueue *q) {
    queue_migrate(q);
    return stack_pop(&q->out);
}
int myQueuePeek(MyQueue *q) {
    queue_migrate(q);
    return stack_peak(q->out);
}
bool myQueueEmpty(MyQueue *q) {
    return stack_empty(q->in) && stack_empty(q->out);
}
void myQueueFree(MyQueue *q) {
    stack_destroy(&q->out);
    stack_destroy(&q->in);
    free(q);
}