// 给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且 3 * k 项的和最大的子数组，并返回这三个子数组。
//
// 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0
// 开始）。如果有多个结果，返回字典序最小的一个。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,1,2,6,7,5,1], k = 2
// 输出：[0,3,5]
// 解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
// 也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
//
//
// 示例 2：
//
//
// 输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
// 输出：[0,2,4]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 10⁴
// 1 <= nums[i] < 2¹⁶
// 1 <= k <= floor(nums.length / 3)
//
// Related Topics 数组 动态规划 👍 203 👎 0

typedef struct {
    int sum;
    int pos;
} node_t;
int *maxSumOfThreeSubarrays(int *nums, int size, int k, int *returnSize) {
    int sum[size - k + 1];
    sum[0] = 0;
    for (int i = 0; i < k; sum[0] += nums[i++]) {}
    for (int i = 1; i + k <= size; ++i) {
        sum[i] = sum[i - 1] - nums[i - 1] + nums[i + k - 1];
    }

    node_t dp[size + 1][4];
    memset(dp, 0, sizeof(dp));

    for (int i = k; i <= size; ++i) {
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i][j].sum < dp[i - k][j - 1].sum + sum[i - k]) {
                dp[i][j] = (node_t) { dp[i - k][j - 1].sum + sum[i - k], i - k };
            }
        }
    }

    int *ans = malloc((*returnSize = 3) * sizeof(int));
    for (int i = 3, prev = size; i > 0; --i) {
        ans[i - 1] = prev = dp[prev][i].pos;
    }
    return ans;
}