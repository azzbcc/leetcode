// 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
//
//
//
// 示例 1:
//
//
// 输入: nums = [0,1]
// 输出: 2
// 说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
//
// 示例 2:
//
//
// 输入: nums = [0,1,0]
// 输出: 2
// 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// nums[i] 不是 0 就是 1
//
// Related Topics 哈希表
// 👍 359 👎 0

typedef struct {
    int key, index;
    UT_hash_handle hh;
} * hash_t;
int findMaxLength(int *nums, int size) {
    int ans     = 0;
    hash_t hash = NULL, cur = malloc(sizeof(*cur)), next;

    cur->key = 0, cur->index = -1;
    HASH_ADD_INT(hash, key, cur);
    for (int i = 0, diff = 0; i < size; ++i) {
        diff += nums[i] * 2 - 1;
        HASH_FIND_INT(hash, &diff, cur);
        if (cur) {
            ans = fmax(ans, i - cur->index);
        } else {
            cur = malloc(sizeof(*cur)), cur->key = diff, cur->index = i;
            HASH_ADD_INT(hash, key, cur);
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
