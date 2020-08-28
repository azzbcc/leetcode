// 给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k
// 的倍数，即总和为 n*k，其 中 n 也是一个整数。
//
//
//
// 示例 1：
//
// 输入：[23,2,4,6,7], k = 6
// 输出：True
// 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6。
//
//
// 示例 2：
//
// 输入：[23,2,6,4,7], k = 6
// 输出：True
// 解释：[23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
//
//
//
//
// 说明：
//
//
// 数组的长度不会超过 10,000 。
// 你可以认为所有数字总和在 32 位有符号整数范围内。
//
// Related Topics 数学 动态规划
// 👍 149 👎 0
#define SIZE 9973

typedef struct node {
    int val;
    struct node *next;
} * node_t;
typedef node_t hash_t[SIZE];

static uint32_t h(int val) {
    return val %= SIZE;
}
static void hash_record(hash_t t, node_t n) {
    node_t cur = t[h(n->val)];
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else if (cur->val < n->val) {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        if (!cur->next || cur->next->val > n->val) { n->next = cur->next, cur->next = n; }
    }
}
static bool hash_exist(hash_t t, int val) {
    node_t cur = t[h(val)];
    while (cur && cur->val < val) {
        cur = cur->next;
    }
    return cur && cur->val == val;
}
bool checkSubarraySum(int *nums, int numsSize, int k) {
    hash_t t = { 0 };
    struct node nodes[numsSize], zero = { 0 };

    if (k < 0) k = -k;
    for (int i = 0; i < numsSize; ++i) {
        nodes[i].val = nums[i], nodes[i].next = NULL;
        if (i) nodes[i].val += nodes[i - 1].val;
        if (k) nodes[i].val %= k;

        if (hash_exist(t, nodes[i].val)) return true;
        hash_record(t, i ? &nodes[i - 1] : &zero);
    }

    return false;
}
