// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
//
// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是
// "ABCDE" 的一个子序列，而 "AEC" 不是）
//
// 题目数据保证答案符合 32 位带符号整数范围。
//
//
//
// 示例 1：
//
//
// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// (上箭头符号 ^ 表示选取的字母)
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// 示例 2：
//
//
// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
// (上箭头符号 ^ 表示选取的字母)
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//
//
// 提示：
//
//
// 0 <= s.length, t.length <= 1000
// s 和 t 由英文字母组成
//
// Related Topics 字符串 动态规划
// 👍 384 👎 0

#if 0
int numDistinct(const char *s, const char *t) {
    if (!*s || !*t) return 0;

    size_t sl = strlen(s);
    long dp[2][sl], cur = 0;

    for (int i = 0, c = 0; i < sl; ++i) {
        dp[cur][i] = c += *t == s[i];
    }
    for (int i = 1; t[i]; ++i, cur = 1 - cur) {
        dp[1 - cur][0] = 0;
        for (int j = 1; j < sl; ++j) {
            dp[1 - cur][j] = dp[1 - cur][j - 1];
            if (t[i] == s[j]) dp[1 - cur][j] += dp[cur][j - 1];
        }
    }

    return dp[cur][sl - 1];
}
#else
int numDistinct(const char *s, const char *t) {
    size_t sl = strlen(s), tl = strlen(t);
    if (!tl || sl < tl) return 0;

    long dp[sl - tl + 1];
    for (int i = 0, c = 0; i <= sl - tl; ++i) {
        dp[i] = c += *t == s[i];
    }
    for (int i = 1; i < tl; ++i) {
        if (s[i] != t[i]) dp[0] = 0;
        for (int j = 1; j <= sl - tl; ++j) {
            if (s[i + j] == t[i]) {
                dp[j] += dp[j - 1];
            } else {
                dp[j] = dp[j - 1];
            }
        }
    }

    return dp[sl - tl];
}
#endif