// 给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。
//
// 示例 1:
//
// 输入: 5
// 输出: 5
// 解释:
// 下面是带有相应二进制表示的非负整数<= 5：
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// 其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
//
// 说明: 1 <= n <= 10⁹
// Related Topics 动态规划 👍 226 👎 0

#define WIDTH 32
int findIntegers(int n) {
    int ans = 0, dp[WIDTH][2] = { 1 };
    for (int i = 1; i < WIDTH; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    for (int i = WIDTH - 2, prev = 0; i >= 0; --i) {
        if (n & 1 << i) {
            ans += dp[i][0] + dp[i][1];
            if (prev == 1) break;
            prev = 1;
        } else {
            prev = 0;
        }
        if (!i) ans++;
    }
    return ans;
}
