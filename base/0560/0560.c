// 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
// 示例 1 :
//
//
// 输入:nums = [1,1,1], k = 2
// 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//
//
// 说明 :
//
//
// 数组的长度为 [1, 20,000]。
// 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
//
// Related Topics 数组 哈希表
// 👍 568 👎 0
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
static void hash_add(hash_t t, node_t n) {
    node_t cur = t[h(n->val)];
    if (!cur || cur->val > n->val) {
        n->next = cur, t[h(n->val)] = n;
    } else if (cur->val == n->val) {
        cur->count++;
    } else {
        while (cur->next && cur->next->val < n->val) {
            cur = cur->next;
        }
        if (cur->next && cur->next->val == n->val) {
            cur->next->count++;
        } else {
            n->next = cur->next, cur->next = n;
        }
    }
}
static int hash_count(hash_t t, int val) {
    node_t cur = t[h(val)];
    while (cur && cur->val < val) {
        cur = cur->next;
    }
    if (cur && cur->val == val) return cur->count;
    return 0;
}
int subarraySum(int *nums, int numsSize, int k) {
    int ans  = 0;
    hash_t t = { 0 };
    struct node nodes[numsSize], zero = { .count = 1 };

    hash_add(t, &zero);

    for (int i = 0; i < numsSize; ++i) {
        nodes[i].val = nums[i], nodes[i].count = 1, nodes[i].next = NULL;
        if (i) nodes[i].val += nodes[i - 1].val;

        ans += hash_count(t, nodes[i].val - k);
        hash_add(t, &nodes[i]);
    }

    return ans;
}