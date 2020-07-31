// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
// 示例 1：
//
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
//
//
// 示例 2：
//
// 输入: "cbbd"
// 输出: "bb"
//
// Related Topics 字符串 动态规划
// 👍 2502 👎 0
#define MAX 1000
char *longestPalindrome(char *str) {
    int max   = 0;
    char *tmp = str, *ans = NULL;
    bool data[MAX][MAX] = { false };

    for (int i = 0; str[i]; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (str[i] == str[j] && (i - j < 2 || data[j + 1][i - 1])) {
                data[j][i] = true;
                if (max < i - j + 1) {
                    max = i - j + 1;
                    tmp = str + j;
                }
            }
        }
    }

    ans = calloc(max + 1, sizeof(char));
    memcpy(ans, tmp, max);
    ans[max] = '\0';

    return ans;
}
