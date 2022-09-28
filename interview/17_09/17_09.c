// 有些数的素因子只有 3，5，7，请设计一个算法找出第 k
// 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
//
// 示例 1:
//
// 输入: k = 5
//
// 输出: 9
//
//
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 👍 149 👎 0

int getKthMagicNumber(int k) {
    int dp[k], p3 = 0, p5 = 0, p7 = 0;
    dp[0] = 1;
    for (int i = 1; i < k; ++i) {
        int n3 = dp[p3] * 3, n5 = dp[p5] * 5, n7 = dp[p7] * 7;
        dp[i] = fmin(fmin(n3, n5), n7);
        p3 += n3 == dp[i];
        p5 += n5 == dp[i];
        p7 += n7 == dp[i];
    }
    return dp[k - 1];
}
