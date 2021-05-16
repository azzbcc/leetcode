// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
//
// 进阶：你可以在 O(n) 的时间解决这个问题吗？
//
//
//
//
//
// 示例 1：
//
//
// 输入：nums = [3,10,5,25,2,8]
// 输出：28
// 解释：最大运算结果是 5 XOR 25 = 28.
//
// 示例 2：
//
//
// 输入：nums = [0]
// 输出：0
//
//
// 示例 3：
//
//
// 输入：nums = [2,4]
// 输出：6
//
//
// 示例 4：
//
//
// 输入：nums = [8,10,2]
// 输出：10
//
//
// 示例 5：
//
//
// 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// 输出：127
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 104
// 0 <= nums[i] <= 231 - 1
//
//
//
// Related Topics 位运算 字典树
// 👍 327 👎 0

#define WIDTH 2

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_record(trie_t t, int maxl, int num) {
    trie_t cur = t;
    while (maxl--) {
        int bit = (num >> maxl) & 1;
        if (!cur->next[bit]) cur->next[bit] = trie_create();
        cur = cur->next[bit];
    }
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
int findMax(trie_t t, int maxl, int num) {
    int ans    = 0;
    trie_t cur = t;
    while (maxl--) {
        int bit = (num >> maxl) & 1;
        if (cur->next[1 - bit]) {
            ans |= 1 << maxl;
            cur = cur->next[1 - bit];
        } else {
            cur = cur->next[bit];
        }
    }
    return ans;
}
int maxLen(int num) {
    int ans = 0;
    while (num) {
        num >>= 1, ans++;
    }
    return ans;
}
int findMaximumXOR(int *nums, int size) {
    int ans = 0, max = 0, maxl = 0;
    trie_t t = trie_create();
    for (int i = 0; i < size; ++i) {
        max = fmax(max, nums[i]);
    }
    maxl = maxLen(max);
    for (int i = 0; i < size; ++i) {
        trie_record(t, maxl, nums[i]);
        ans = fmax(ans, findMax(t, maxl, nums[i]));
    }
    trie_free(t);
    return ans;
}