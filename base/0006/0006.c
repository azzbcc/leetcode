// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
//
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
//
// L   C   I   R
// E T O E S I I G
// E   D   H   N
//
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
//
// 请你实现这个将字符串进行指定行数变换的函数：
//
// string convert(string s, int numRows);
//
// 示例 1:
//
// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"
//
//
// 示例 2:
//
// 输入: s = "LEETCODEISHIRING", numRows = 4
// 输出:"LDREOEIIECIHNTSG"
// 解释:
//
// L     D     R
// E   O E   I I
// E C   I H   N
// T     S     G
// Related Topics 字符串
// 👍 768 👎 0
char *convert(char *s, int numRows) {
    static char ans[1024] = { 0 };
    int len = strlen(s), step = numRows - 1, pos = 0;

    if (!len || !step) return s;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < len && j + i < len; j += step * 2) {
            ans[pos++] = s[j + i];
            if (0 == i % step) continue;
            if (j + step * 2 - i < len) {
                ans[pos++] = s[j + step * 2 - i];
            }
        }
    }

    ans[pos] = '\0';

    return ans;
}