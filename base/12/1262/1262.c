// 给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
//
//
//
//
//
//
// 示例 1：
//
// 输入：nums = [3,6,5,1,8]
// 输出：18
// 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
//
// 示例 2：
//
// 输入：nums = [4]
// 输出：0
// 解释：4 不能被 3 整除，所以无法选出数字，返回 0。
//
//
// 示例 3：
//
// 输入：nums = [1,2,3,4,4]
// 输出：12
// 解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 4 * 10^4
// 1 <= nums[i] <= 10^4
//
//
// Related Topics 贪心 数组 动态规划 排序 👍 261 👎 0

int maxSumDivThree(int *nums, int size) {
    int dp[3] = { 0, INT32_MIN, INT32_MIN };
    for (int i = 0, tmp[3] = { 0 }; i < size; i++) {
        memcpy(tmp, dp, sizeof(dp));
        for (int j = 0, k; k = (j + nums[i]) % 3, j < 3; j++) {
            tmp[k] = fmax(tmp[k], dp[j] + nums[i]);
        }
        memcpy(dp, tmp, sizeof(dp));
    }
    return dp[0];
}
