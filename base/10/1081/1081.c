// 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
//
// 注意：该题与 316 https://leetcode.com/problems/remove-duplicate-letters/ 相同
//
//
//
// 示例 1：
//
//
// 输入：s = "bcabc"
// 输出："abc"
//
//
// 示例 2：
//
//
// 输入：s = "cbacdcbc"
// 输出："acdb"
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s 由小写英文字母组成
//
// Related Topics 栈 贪心 字符串 单调栈 👍 115 👎 0

#define WIDTH 26

char *smallestSubsequence(char *s) {
    bool flags[WIDTH] = { false };
    int at[WIDTH] = { 0 }, top = -1;
    static char str[WIDTH + 1] = { '\0' };

    for (int i = 0; s[i]; at[s[i++] - 'a']++) {}
    for (; *s; at[*s++ - 'a']--) {
        if (flags[*s - 'a']) continue;
        for (; top >= 0 && *s <= str[top] && at[str[top] - 'a']; flags[str[top--] - 'a'] = false) {}
        if (!flags[*s - 'a']) flags[(str[++top] = *s) - 'a'] = true;
    }
    str[top + 1] = '\0';
    return str;
}
