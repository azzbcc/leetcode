// 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
//
// 如果字符串的长度为 1 ，算法停止
// 如果字符串的长度 > 1 ，执行下述步骤：
//
// 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s
// = x + y 。 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是
// s = x + y 或者 s = y + x 。 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
//
//
//
//
// 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
//
// 输入：s1 = "great", s2 = "rgeat"
// 输出：true
// 解释：s1 上可能发生的一种情形是：
// "great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
// "gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
// "gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
// "g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
// "r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
// "r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」算法终止，结果字符串和 s2 相同，都是
// "rgeat" 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true
//
//
// 示例 2：
//
//
// 输入：s1 = "abcde", s2 = "caebd"
// 输出：false
//
//
// 示例 3：
//
//
// 输入：s1 = "a", s2 = "a"
// 输出：true
//
//
//
//
// 提示：
//
//
// s1.length == s2.length
// 1 <= s1.length <= 30
// s1 和 s2 由小写英文字母组成
//
// Related Topics 字符串 动态规划
// 👍 292 👎 0

#define WIDTH 26

bool isSimilar(const char *s1, const char *s2, size_t len) {
    int c1[WIDTH] = { 0 }, c2[WIDTH] = { 0 };
    for (int i = 0; i < len; ++i) {
        c1[s1[i] - 'a']++, c2[s2[i] - 'a']++;
    }
    for (int i = 0; i < WIDTH; ++i) {
        if (c1[i] != c2[i]) return false;
    }
    return true;
}
bool isScrambleLen(size_t n, int dp[n][n][n + 1], const char *s1, size_t p1, const char *s2, size_t p2, size_t len) {
    if (len < 2) return dp[p1][p2][len] = len ? s1[p1] == s2[p2] : true;
    if (dp[p1][p2][len] != -1) return dp[p1][p2][len];
    if (!isSimilar(s1 + p1, s2 + p2, len)) return dp[p1][p2][len] = false;

    for (int l = 1; l < len; ++l) {
        if (isScrambleLen(n, dp, s1, p1, s2, p2, l) && isScrambleLen(n, dp, s1, p1 + l, s2, p2 + l, len - l)) {
            return dp[p1][p2][len] = true;
        }
        if (isScrambleLen(n, dp, s1, p1, s2, p2 + len - l, l) && isScrambleLen(n, dp, s1, p1 + l, s2, p2, len - l)) {
            return dp[p1][p2][len] = true;
        }
    }
    return dp[p1][p2][len] = false;
}
bool isScramble(char *s1, char *s2) {
    size_t l1 = strlen(s1), l2 = strlen(s2);
    if (l1 != l2) return false;

    int dp[l1][l1][l1 + 1];
    memset(dp, -1, sizeof(dp));

    return isScrambleLen(l1, dp, s1, 0, s2, 0, l1);
}