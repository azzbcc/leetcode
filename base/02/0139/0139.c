// 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
// 说明：
//
//
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
//
//
// 示例 1：
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//
//
// 示例 2：
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
//
//
// 示例 3：
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false
//
// Related Topics 动态规划
// 👍 687 👎 0

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    if (wordDictSize <= 0) return false;
    size_t lens[wordDictSize], len = strlen(s);
    for (int i = 0; i < wordDictSize; lens[i] = strlen(wordDict[i]), i++) {}

    bool dp[len + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = true;
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; !dp[i] && j < wordDictSize; ++j) {
            if (i >= lens[j] && dp[i - lens[j]]) dp[i] = !strncmp(s + i - lens[j], wordDict[j], lens[j]);
        }
    }

    return dp[len];
}
