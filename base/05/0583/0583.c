// 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
//
//
//
// 示例：
//
// 输入: "sea", "eat"
// 输出: 2
// 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
//
//
//
//
// 提示：
//
//
// 给定单词的长度不超过500。
// 给定单词中的字符只含有小写字母。
//
// Related Topics 字符串 动态规划 👍 297 👎 0

int minDistance(char *word1, char *word2) {
    size_t l1 = strlen(word1), l2 = strlen(word2);
    int dp[l1 + 1][l2 + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= l1; ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= l2; ++i) {
        dp[0][i] = i;
    }
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            if (word1[i] == word2[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else {
                dp[i + 1][j + 1] = 1 + fmin(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[l1][l2];
}
