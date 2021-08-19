// 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
//
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
//
//
//
// 示例 1：
//
//
// 输入：s = "hello"
// 输出："holle"
//
//
// 示例 2：
//
//
// 输入：s = "leetcode"
// 输出："leotcede"
//
//
//
// 提示：
//
//
// 1 <= s.length <= 3 * 10⁵
// s 由 可打印的 ASCII 字符组成
//
// Related Topics 双指针 字符串 👍 197 👎 0

static bool isVowel(int ch) {
    bool flag[0x100] = { ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true,
                         ['A'] = true, ['E'] = true, ['I'] = true, ['O'] = true, ['U'] = true };
    return flag[ch];
}
char *reverseVowels(char *s) {
    for (int l = 0, r = strlen(s) - 1; l < r; l++, r--) {
        for (; l < r && !isVowel(s[l]); l++) {}
        for (; l < r && !isVowel(s[r]); r--) {}
        for (int t = s[l]; l < r && t != s[r]; s[l] = s[r], s[r] = t) {}
    }
    return s;
}