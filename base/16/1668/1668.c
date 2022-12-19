// 给你一个字符串 sequence ，如果字符串 word 连续重复 k 次形成的字符串是 sequence 的一个子字符串，那么单词 word 的
// 重复值为 k 。单词 word 的 最大重复值 是单词 word 在 sequence 中最大的重复值。如果 word 不是 sequence
// 的子串，那么重复值 k为 0 。
//
// 给你一个字符串 sequence 和 word ，请你返回 最大重复值 k 。
//
//
//
// 示例 1：
//
//
// 输入：sequence = "ababc", word = "ab"
// 输出：2
// 解释："abab" 是 "ababc" 的子字符串。
//
//
// 示例 2：
//
//
// 输入：sequence = "ababc", word = "ba"
// 输出：1
// 解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
//
//
// 示例 3：
//
//
// 输入：sequence = "ababc", word = "ac"
// 输出：0
// 解释："ac" 不是 "ababc" 的子字符串。
//
//
//
//
// 提示：
//
//
// 1 <= sequence.length <= 100
// 1 <= word.length <= 100
// sequence 和 word 都只包含小写英文字母。
//
//
// Related Topics 字符串 字符串匹配 👍 80 👎 0

int maxRepeating(char *sequence, char *word) {
    size_t ls = strlen(sequence), lw = strlen(word);
    if (ls < lw) return 0;

    int dp[ls + 1], ans = 0;
    memset(dp, 0, lw * sizeof(int));
    for (int i = lw; i <= ls; ++i) {
        if (!strncmp(sequence + i - lw, word, lw)) {
            ans = fmax(ans, dp[i] = dp[i - lw] + 1);
        } else {
            dp[i] = 0;
        }
    }
    return ans;
}