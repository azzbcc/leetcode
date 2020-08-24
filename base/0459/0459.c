// 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
//
// 示例 1:
//
//
// 输入: "abab"
//
// 输出: True
//
// 解释: 可由子字符串 "ab" 重复两次构成。
//
//
// 示例 2:
//
//
// 输入: "aba"
//
// 输出: False
//
//
// 示例 3:
//
//
// 输入: "abcabcabcabc"
//
// 输出: True
//
// 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
//
// Related Topics 字符串
// 👍 286 👎 0

bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    for (int repeat = 1, pos; repeat <= len / 2; ++repeat) {
        if (len % repeat) continue;
        for (pos = repeat; pos < len; ++pos) {
            if (s[pos] != s[pos % repeat]) break;
        }
        if (pos == len) return true;
    }
    return false;
}
