// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//
//
// 示例 1:
//
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
//
//
// 示例 2:
//
// 输入: nums = [1], k = 1
// 输出: [1]
//
//
//
// 提示：
//
//
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
// 你可以按任意顺序返回答案。
//
// Related Topics 堆 哈希表
// 👍 464 👎 0
#define SIZE 9973

typedef struct node {
    int val;
    int count;
    struct node *next;
} * node_t;
typedef node_t hash_t[SIZE];
static uint32_t h(int val) {
    val %= SIZE;
    if (val < 0) val += SIZE;
    return val;
}
static bool hash_add(hash_t t, node_t n) {
    node_t cur = t[h(n->val)];
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else if (cur->val == n->val) {
        cur->count++;
        return false;
    } else {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        if (cur->next && cur->next->val == n->val) {
            cur->next->count++;
            return false;
        } else {
            n->next = cur->next, cur->next = n;
        }
    }
    return true;
}
static bool gt(int a, int b) {
    return a > b;
}
static bool lt(int a, int b) {
    return a < b;
}
void heap_adjust(node_t nodes[], int now, int len, bool (*operator)(int, int)) {
    node_t tmp = nodes[now];
    int l = 2 * now + 1, r = l + 1, max_pos = now;

    if (l < len && operator(nodes[l]->count, nodes[max_pos]->count)) max_pos = l;
    if (r < len && operator(nodes[r]->count, nodes[max_pos]->count)) max_pos = r;
    if (max_pos != now) {
        nodes[now] = nodes[max_pos], nodes[max_pos] = tmp;
        heap_adjust(nodes, max_pos, len, operator);
    }
}
int *topKFrequent_1(int *nums, int numsSize, int k, int *returnSize) {
    int *ans, len = 0;
    hash_t hash = { NULL };
    node_t nodes[numsSize], tmp;
    struct node stack[numsSize];

    for (int i = 0; i < numsSize; ++i) {
        stack[i].val = nums[i], stack[i].count = 1, stack[i].next = NULL;
        if (hash_add(hash, &stack[i])) nodes[len++] = &stack[i];
    }

    if (k < len) {
        for (int i = len / 2 - 1; i >= 0; heap_adjust(nodes, i--, len, gt)) {}

        for (int i = 0; i < k; ++i) {
            tmp = nodes[0], nodes[0] = nodes[len - i - 1], nodes[len - i - 1] = tmp;
            heap_adjust(nodes, 0, len - i - 1, gt);
        }
    }

    ans = calloc(k, sizeof(int)), *returnSize = k;
    for (int i = 0; i < k; ++i) {
        ans[i] = nodes[len - i - 1]->val;
    }

    return ans;
}
int *topKFrequent_2(int *nums, int numsSize, int k, int *returnSize) {
    int *ans, len = 0;
    hash_t hash = { NULL };
    node_t nodes[numsSize];
    struct node stack[numsSize];

    for (int i = 0; i < numsSize; ++i) {
        stack[i].val = nums[i], stack[i].count = 1, stack[i].next = NULL;
        if (hash_add(hash, &stack[i])) nodes[len++] = &stack[i];
    }

    if (k < len) {
        for (int i = k / 2 - 1; i >= 0; heap_adjust(nodes, i--, k, lt)) {}

        for (int i = k; i < len; ++i) {
            if (nodes[i]->count < nodes[0]->count) continue;
            nodes[0] = nodes[i], heap_adjust(nodes, 0, k, lt);
        }
    }

    ans = calloc(k, sizeof(int)), *returnSize = k;
    for (int i = 0; i < k; ++i) {
        ans[i] = nodes[i]->val;
    }

    return ans;
}

int *(*topKFrequent)(int *, int, int, int *) = topKFrequent_1;