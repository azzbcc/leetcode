// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证
// 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
// -characters 相同
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
// 1 <= s.length <= 104
// s 由小写英文字母组成
//
// Related Topics 栈 贪心算法 字符串
// 👍 373 👎 0

#define WIDTH 26

char *removeDuplicateLetters(char *s) {
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
