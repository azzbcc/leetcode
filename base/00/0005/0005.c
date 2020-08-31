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
char *longestPalindrome_1(char *str) {
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

int min(int a, int b) {
    return a < b ? a : b;
}
char *expand(char *s, int *len) {
    static char str[MAX * 2 + 2] = { '#' };

    *len = 1;
    while (*s) {
        str[(*len)++] = *s++;
        str[(*len)++] = '#';
    }
    str[*len] = '\0';
    return str;
}
char *longestPalindrome_2(char *str) {
    int len = 0, max = 0, B[MAX * 2 + 1] = { 0 };
    char *tmp = str, *S = expand(str, &len);

    for (int P = 0, C = 0, R = 0; P < len; ++P) {
        if (R > P) {
            int P_ = 2 * C - P;
            B[P]   = min(B[P_], R - P);
            if (R - P != B[P_]) continue;
        } else {
            R = P;
        }
        C = P;

        int R_ = 2 * C - R;
        while (R_ > 0 && R + 1 < len && S[R_ - 1] == S[R + 1]) {
            B[P]++, R_--, R++;
        }

        if (max < B[P]) max = B[P], tmp = str + (P - B[P]) / 2;
    }

    char *ans = calloc(max + 1, sizeof(char));
    memcpy(ans, tmp, max);
    ans[max] = '\0';

    return ans;
}

char *(*longestPalindrome)(char *) = longestPalindrome_2;
