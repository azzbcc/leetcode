//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//
// 示例 1:
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
//
//
// 示例 2:
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
//
// Related Topics 字符串 动态规划
// 👍 1020 👎 0

int longestValidParentheses(char *s) {
    size_t len = strlen(s);
    if (!len) return 0;

    int sa[len], ans = 0;
    memset(sa, 0, sizeof(sa));

    for (int i = 1; i < len; ++i) {
        if (s[i] == '(') continue;
        int left = i - sa[i - 1] - 1;
        if (left >= 0 && s[left] == '(') {
            sa[i] = sa[i - 1] + 2;
            if (left > 0) sa[i] += sa[left - 1];
            if (ans < sa[i]) ans = sa[i];
        }
    }

    return ans;
}
