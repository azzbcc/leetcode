// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//
// 你可以认为每种硬币的数量是无限的。
//
//
//
// 示例 1：
//
//
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3
// 解释：11 = 5 + 5 + 1
//
// 示例 2：
//
//
// 输入：coins = [2], amount = 3
// 输出：-1
//
// 示例 3：
//
//
// 输入：coins = [1], amount = 0
// 输出：0
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2³¹ - 1
// 0 <= amount <= 10⁴
//
//
// Related Topics 广度优先搜索 数组 动态规划 👍 2789 👎 0

int coinChange(int *coins, int size, int amount) {
    int dp[amount + 1];
    if (!amount) return 0;

    memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
    for (int i = 0; i < amount; ++i) {
        if (dp[i] == 0x3f3f3f3f) continue;
        for (int j = 0; j < size; ++j) {
            if (0L + i + coins[j] > amount) continue;
            dp[i + coins[j]] = fmin(dp[i + coins[j]], dp[i] + 1);
        }
    }
    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
}