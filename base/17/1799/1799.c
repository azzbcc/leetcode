// 给你 nums ，它是一个大小为 2 * n 的正整数数组。你必须对这个数组执行 n 次操作。
//
// 在第 i 次操作时（操作编号从 1 开始），你需要：
//
//
// 选择两个元素 x 和 y 。
// 获得分数 i * gcd(x, y) 。
// 将 x 和 y 从 nums 中删除。
//
//
// 请你返回 n 次操作后你能获得的分数和最大为多少。
//
// 函数 gcd(x, y) 是 x 和 y 的最大公约数。
//
//
//
// 示例 1：
//
// 输入：nums = [1,2]
// 输出：1
// 解释：最优操作是：
// (1 * gcd(1, 2)) = 1
//
//
// 示例 2：
//
// 输入：nums = [3,4,6,8]
// 输出：11
// 解释：最优操作是：
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
//
//
// 示例 3：
//
// 输入：nums = [1,2,3,4,5,6]
// 输出：14
// 解释：最优操作是：
// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
//
//
//
//
// 提示：
//
//
// 1 <= n <= 7
// nums.length == 2 * n
// 1 <= nums[i] <= 10⁶
//
//
// Related Topics 位运算 数组 数学 动态规划 回溯 状态压缩 数论 👍 74 👎 0

int gcd(int a, int b) {
    for (int tmp; b; tmp = a % b, a = b, b = tmp) {}
    return a;
}
int maxScore(int *nums, int size) {
    int dp[1 << size], g[size][size];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            g[i][j] = gcd(nums[i], nums[j]);
        }
    }
    for (int i = 0, c; i < 0x1 << size; ++i) {
        if (c = __builtin_popcount(i), c % 2) continue;
        c = c / 2 + 1;
        for (int j = 0; j < size; ++j) {
            if (i & 0x1 << j) continue;
            for (int k = j + 1; k < size; ++k) {
                if (i & 0x1 << k) continue;
                int next = i | 0x1 << j | 0x1 << k;
                dp[next] = fmax(dp[next], dp[i] + c * g[j][k]);
            }
        }
    }
    return dp[(0x1 << size) - 1];
}