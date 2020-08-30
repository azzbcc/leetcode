// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//
//
// 示例：
//
// 输入："Let's take LeetCode contest"
// 输出："s'teL ekat edoCteeL tsetnoc"
//
//
//
//
// 提示：
//
//
// 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
//
// Related Topics 字符串
// 👍 234 👎 0

void reverse(char *s, int beg, int end) {
    for (char tmp; beg < end; beg++, end--) {
        tmp = s[beg], s[beg] = s[end], s[end] = tmp;
    }
}
char *reverseWords(char *s) {
    for (int i = 0, last = 0; s[i]; ++i) {
        if (s[i + 1] == ' ' || s[i + 1] == '\0') {
            reverse(s, last, i);
            last = i + 2;
        }
    }
    return s;
}
