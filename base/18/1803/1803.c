// 给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数：low 和 high ，请返回 漂亮数对 的数目。
//
// 漂亮数对 是一个形如 (i, j) 的数对，其中 0 <= i < j < nums.length 且 low <= (nums[i] XOR nums[j]) <= high 。
//
//
//
// 示例 1：
//
// 输入：nums = [1,4,2,7], low = 2, high = 6
// 输出：6
// 解释：所有漂亮数对 (i, j) 列出如下：
//    - (0, 1): nums[0] XOR nums[1] = 5
//    - (0, 2): nums[0] XOR nums[2] = 3
//    - (0, 3): nums[0] XOR nums[3] = 6
//    - (1, 2): nums[1] XOR nums[2] = 6
//    - (1, 3): nums[1] XOR nums[3] = 3
//    - (2, 3): nums[2] XOR nums[3] = 5
//
//
// 示例 2：
//
// 输入：nums = [9,8,4,2,1], low = 5, high = 14
// 输出：8
// 解释：所有漂亮数对 (i, j) 列出如下：
//    - (0, 2): nums[0] XOR nums[2] = 13
//    - (0, 3): nums[0] XOR nums[3] = 11
//    - (0, 4): nums[0] XOR nums[4] = 8
//    - (1, 2): nums[1] XOR nums[2] = 12
//    - (1, 3): nums[1] XOR nums[3] = 10
//    - (1, 4): nums[1] XOR nums[4] = 9
//    - (2, 3): nums[2] XOR nums[3] = 6
//    - (2, 4): nums[2] XOR nums[4] = 5
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 10⁴
// 1 <= nums[i] <= 2 * 10⁴
// 1 <= low <= high <= 2 * 10⁴
//
//
// Related Topics 位运算 字典树 数组 👍 132 👎 0

#define WIDTH 2
#define MAXM  14
typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int count;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_record(trie_t t, int num) {
    trie_t cur = t;
    for (int i = MAXM; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!cur->next[bit]) cur->next[bit] = trie_create();
        cur = cur->next[bit], cur->count += 1;
    }
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
int count(trie_t t, int num, int val) {
    int ans    = 0;
    trie_t cur = t;
    for (int i = MAXM; i >= 0 && cur; --i) {
        int bit = (num >> i) & 1;
        if ((val >> i) & 1) {
            if (cur->next[bit]) ans += cur->next[bit]->count;
            cur = cur->next[bit ^ 1];
        } else {
            cur = cur->next[bit];
        }
    }
    if (cur) ans += cur->count;
    return ans;
}
int countPairs(int *nums, int size, int low, int high) {
    int ans  = 0;
    trie_t t = trie_create();
    for (int i = 1; i < size; ++i) {
        trie_record(t, nums[i - 1]);
        ans += count(t, nums[i], high) - count(t, nums[i], low - 1);
    }
    trie_free(t);
    return ans;
}