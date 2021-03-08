// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
//
// 返回符合要求的 最少分割次数 。
//
//
//
//
//
// 示例 1：
//
//
// 输入：s = "aab"
// 输出：1
// 解释：只需一次分割就可将s 分割成 ["aa","b"] 这样两个回文子串。
//
//
// 示例 2：
//
//
// 输入：s = "a"
// 输出：0
//
//
// 示例 3：
//
//
// 输入：s = "ab"
// 输出：1
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 2000
// s 仅由小写英文字母组成
//
//
//
// Related Topics 动态规划
// 👍 312 👎 0

#define MAXN      2000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int manacher[2 * MAXN + 1];
bool check(int beg, int len) {
    return manacher[beg * 2 + len] >= len;
}
void init(char *s, size_t len) {
    char str[len * 2 + 2];

    str[0] = '#', str[len * 2 + 1] = '\0';
    for (char *ps = str, *ts = s; (*++ps = *ts++);) {
        *++ps = '#';
    }

    for (int mid = 0, end = 0, i = 0; str[i]; i++) {
        if (i < end) {
            manacher[i] = MIN(manacher[mid * 2 - i], end - i);
            if (manacher[mid * 2 - i] != end - i) continue;
        } else {
            end = i;
        }

        mid = i;
        for (int beg = mid * 2 - end; beg > 0 && str[--beg] == str[end + 1]; end++) {}
        manacher[i] = end - mid;
    }
}

int minCut(char *s) {
    size_t len = strlen(s);
    int dp[len + 1];

    dp[len] = -1, init(s, len);
    for (int i = len - 1; i >= 0; --i) {
        int min = dp[i + 1] + 1;
        for (int l = 2; i + l <= len; ++l) {
            if (!check(i, l)) continue;
            if (min > dp[i + l] + 1) min = dp[i + l] + 1;
        }
        dp[i] = min;
    }

    return dp[0];
}