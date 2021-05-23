// 给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。
//
// 第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j]
// XOR xi) ， 其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。
//
// 返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。
//
//
//
// 示例 1：
//
// 输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
// 输出：[3,3,7]
// 解释：
// 1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
// 2) 1 XOR 2 = 3.
// 3) 5 XOR 2 = 7.
//
//
// 示例 2：
//
// 输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
// 输出：[15,-1,5]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length, queries.length <= 105
// queries[i].length == 2
// 0 <= nums[j], xi, mi <= 109
//
// Related Topics 位运算 字典树
// 👍 57 👎 0

#define WIDTH 2
#define MAXN  30

typedef struct trie_node_t {
    int min;
    struct trie_node_t *next[WIDTH];
} * trie_t;
trie_t trie_create() {
    trie_t t = malloc(sizeof(struct trie_node_t));
    t->min = INT32_MAX, t->next[0] = t->next[1] = NULL;
    return t;
}
void trie_record(trie_t t, int num) {
    trie_t cur = t;
    cur->min   = fmin(cur->min, num);
    for (int maxl = MAXN; maxl--;) {
        int bit = (num >> maxl) & 1;
        if (!cur->next[bit]) cur->next[bit] = trie_create();
        cur      = cur->next[bit];
        cur->min = fmin(cur->min, num);
    }
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
int findMax(trie_t t, int num, int limit) {
    int ans = 0, maxl = MAXN;
    if (t->min > limit) return -1;
    for (trie_t cur = t; maxl--;) {
        int bit = (num >> maxl) & 1;
        if (cur->next[1 ^ bit] && cur->next[1 ^ bit]->min <= limit) ans |= 1 << maxl, bit ^= 1;
        cur = cur->next[bit];
    }
    return ans;
}
int *maximizeXor(int *nums, int size, int **queries, int qSize, int *qColSize, int *returnSize) {
    trie_t t = trie_create();
    int *ans = malloc((*returnSize = qSize) * sizeof(int));

    for (int i = 0; i < size; trie_record(t, nums[i++])) {}
    for (int i = 0; i < qSize; ++i) {
        ans[i] = findMax(t, queries[i][0], queries[i][1]);
    }
    trie_free(t);
    return ans;
}