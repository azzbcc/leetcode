// 给你一个下标从 0 开始长度为 n 的数组 nums 。
//
// 每一秒，你可以对数组执行以下操作：
//
//
// 对于范围在 [0, n - 1] 内的每一个下标 i ，将 nums[i] 替换成 nums[i] ，
// nums[(i - 1 + n) % n] 或者 nums[(i + 1) % n] 三者之一。
//
//
// 注意，所有元素会被同时替换。
//
// 请你返回将数组 nums 中所有元素变成相等元素所需要的 最少 秒数。
//
//
//
// 示例 1：
//
// 输入：nums = [1,2,1,2]
// 输出：1
// 解释：我们可以在 1 秒内将数组变成相等元素：
// - 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2] 。
//
// 1 秒是将数组变成相等元素所需要的最少秒数。
//
//
// 示例 2：
//
// 输入：nums = [2,1,3,3,2]
// 输出：2
// 解释：我们可以在 2 秒内将数组变成相等元素：
// - 第 1 秒，将每个位置的元素分别变为 [nums[0],nums[2],nums[2],nums[2],nums[3]] 。变化后，nums = [2,3,3,3,3] 。
// - 第 2 秒，将每个位置的元素分别变为 [nums[1],nums[1],nums[2],nums[3],nums[4]] 。变化后，nums = [3,3,3,3,3] 。
// 2 秒是将数组变成相等元素所需要的最少秒数。
//
//
// 示例 3：
//
// 输入：nums = [5,5,5,5]
// 输出：0
// 解释：不需要执行任何操作，因为一开始数组中的元素已经全部相等。
//
//
//
//
// 提示：
//
//
// 1 <= n == nums.length <= 10⁵
// 1 <= nums[i] <= 10⁹
//
//
// Related Topics 数组 哈希表 👍 46 👎 0

typedef struct {
    int key, last, dist;
    UT_hash_handle hh;
} hash_t;
int minimumSeconds(int *nums, int size) {
    int ans = INT32_MAX;
    hash_t nodes[size], *cur, *next, *hash = NULL;
    for (int i = 0; i < size * 2; ++i) {
        HASH_FIND_INT(hash, &nums[i % size], cur);
        if (cur) {
            cur->dist = fmax(cur->dist, i - cur->last);
            cur->last = i;
        } else {
            nodes[i] = (hash_t) { nums[i % size], i };
            HASH_ADD_INT(hash, key, &nodes[i]);
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        ans = fmin(ans, cur->dist / 2);
    }
    HASH_CLEAR(hh, hash);
    return ans;
}