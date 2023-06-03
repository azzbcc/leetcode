// 如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。
//
// 给你一个字符串
// text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。
//
//
//
// 示例 1：
//
// 输入：text = "ababa"
// 输出：3
//
//
// 示例 2：
//
// 输入：text = "aaabaaa"
// 输出：6
//
//
// 示例 3：
//
// 输入：text = "aaabbaaa"
// 输出：4
//
//
// 示例 4：
//
// 输入：text = "aaaaa"
// 输出：5
//
//
// 示例 5：
//
// 输入：text = "abcdef"
// 输出：1
//
//
//
//
// 提示：
//
//
// 1 <= text.length <= 20000
// text 仅由小写英文字母组成。
//
//
// Related Topics 哈希表 字符串 滑动窗口 👍 142 👎 0

#define WIDTH 26
int maxRepOpt1(char *text) {
    int cc[WIDTH] = { 0 }, ans = 0;
    for (int i = 0; text[i]; cc[text[i++] - 'a']++) {}
    for (int i = 0, c, last2 = 0, last1 = 0; text[i]; last2 = last1, i += last1 = c) {
        for (c = 0; text[i + c] == text[i]; ++c) {}
        if (i > 1 && text[i] == text[i - 2]) {
            ans = fmax(ans, c + last2 + (c + last2 < cc[text[i] - 'a']));
        } else {
            ans = fmax(ans, c + (c < cc[text[i] - 'a']));
        }
    }
    return ans;
}
