// 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
//
// 您想要拼写出给定的字符串
// target，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
//
// 返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。
//
// 注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，并且 target
// 被选择为两个随机单词的连接。
//
//
//
//  示例 1：
//
//
// 输入： stickers = ["with","example","science"], target = "thehat"
// 输出：3
// 解释：
// 我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
// 把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
// 此外，这是形成目标字符串所需的最小贴纸数量。
//
//
//  示例 2:
//
//
// 输入：stickers = ["notice","possible"], target = "basicbasic"
// 输出：-1
// 解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
//
//
//
//  提示:
//
//
//  n == stickers.length
//  1 <= n <= 50
//  1 <= stickers[i].length <= 10
//  1 <= target <= 15
//  stickers[i] 和 target 由小写英文单词组成
//
//  Related Topics 位运算 动态规划 回溯 状态压缩 👍 188 👎 0

#define WIDTH 26
typedef struct {
    int count[WIDTH];
} cs_t;
cs_t parse_str(char *str) {
    cs_t cs = { 0 };
    for (char *p = str; *p; cs.count[*p++ - 'a']++) {}
    return cs;
}
int dfs(int dp[], int mask, cs_t cs[], int size, char *target, int len) {
    if (dp[mask] != -1) return dp[mask];
    dp[mask] = len + 1;
    for (int i = 0; i < size; ++i) {
        int left = mask;
        cs_t cnt = cs[i];
        for (int j = 0; j < len; ++j) {
            if ((mask >> j & 1) == 0) continue;
            if (!cnt.count[target[j] - 'a']) continue;
            cnt.count[target[j] - 'a']--, left ^= 1 << j;
        }
        if (left == mask) continue;
        dp[mask] = fmin(dp[mask], dfs(dp, left, cs, size, target, len) + 1);
    }
    return dp[mask];
}
int minStickers(char **stickers, int size, char *target) {
    cs_t ss[size];
    size_t len = strlen(target);
    int dp[1 << len];
    memset(dp, -1, sizeof(dp)), dp[0] = 0;
    for (int i = 0; i < size; ++i) {
        ss[i] = parse_str(stickers[i]);
    }
    int ans = dfs(dp, (1 << len) - 1, ss, size, target, len);
    return ans > len ? -1 : ans;
}
