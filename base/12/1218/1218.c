// 给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr
// 中最长等差子序列的长度，该子序列中相邻元素之间的差等于difference 。
//
// 子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。
//
//
//
// 示例 1：
//
//
// 输入：arr = [1,2,3,4], difference = 1
// 输出：4
// 解释：最长的等差子序列是 [1,2,3,4]。
//
// 示例 2：
//
//
// 输入：arr = [1,3,5,7], difference = 1
// 输出：1
// 解释：最长的等差子序列是任意单个元素。
//
//
// 示例 3：
//
//
// 输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
// 输出：4
// 解释：最长的等差子序列是 [7,5,3,1]。
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 10⁵
// -10⁴ <= arr[i], difference <= 10⁴
//
// Related Topics 数组 哈希表 动态规划 👍 128 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, int key, int count) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count = count;
}
int longestSubsequence(int *arr, int size, int diff) {
    int ans = 0;
    hash_t cur, next, hash = NULL;

    for (int i = 0; i < size; ++i) {
        cur = hash_find(hash, arr[i] - diff);
        hash_record(&hash, arr[i], cur ? cur->count + 1 : 1);
    }
    HASH_ITER(hh, hash, cur, next) {
        ans = fmax(ans, cur->count);
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}