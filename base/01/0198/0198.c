// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//
//
//
// 示例 1：
//
//
// 输入：[1,2,3,1]
// 输出：4
// 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。
//
// 示例 2：
//
//
// 输入：[2,7,9,3,1]
// 输出：12
// 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
//
// Related Topics 数组 动态规划 👍 1674 👎 0

#if 0
int rob(int *nums, int size) {
    if (!size) return 0;
    int cur = 0, dp[2][2] = { *nums };

    for (int i = 1; i < size; ++i, cur = 1 - cur) {
        dp[1 - cur][1] = fmax(dp[cur][0], dp[cur][1]);
        dp[1 - cur][0] = dp[cur][1] + nums[i];
    }
    return fmax(dp[cur][0], dp[cur][1]);
}
#else
int rob(int *nums, int size) {
    if (!size) return 0;
    if (size == 1) return *nums;
    int a = nums[0], b = fmax(a, nums[1]);
    for (int i = 2, t; i < size; ++i) {
        t = fmax(a + nums[i], b), a = b, b = t;
    }
    return b;
}
#endif