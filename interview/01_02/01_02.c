// 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//
// 示例 1：
//
// 输入: s1 = "abc", s2 = "bca"
// 输出: true
//
//
// 示例 2：
//
// 输入: s1 = "abc", s2 = "bad"
// 输出: false
//
//
// 说明：
//
//
// 0 <= len(s1) <= 100
// 0 <= len(s2) <= 100
//
//
// Related Topics 哈希表 字符串 排序 👍 103 👎 0

#define MAX 0x80
bool CheckPermutation(char *s1, char *s2) {
    int sa[MAX] = { 0 }, sb[MAX] = { 0 };
    for (int i = 0; s1[i]; sa[s1[i++]]++) {}
    for (int i = 0; s2[i]; sb[s2[i++]]++) {}
    for (int i = 0; i < MAX; ++i) {
        if (sa[i] != sb[i]) return false;
    }
    return true;
}