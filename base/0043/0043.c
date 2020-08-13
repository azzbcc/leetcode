// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
// 示例 1:
//
// 输入: num1 = "2", num2 = "3"
// 输出: "6"
//
// 示例 2:
//
// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
//
// 说明：
//
//
// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//
// Related Topics 数学 字符串
// 👍 425 👎 0

#define MAXN      219
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
char *multiply(char *num1, char *num2) {
    static char ans[MAXN] = { 0 };
    if (*num1 == '0' || *num2 == '0') {
        ans[0] = '0', ans[1] = '\0';
        return ans;
    }

    int len1 = strlen(num1), len2 = strlen(num2), pos = len1 + len2;

    ans[pos--] = '\0';
    for (int ret = 0; pos >= 0; ret /= 10) {
        for (int pos1 = MIN(len1, pos) - 1; pos1 >= 0; --pos1) {
            int pos2 = pos - pos1 - 1;
            if (pos2 < 0 || pos2 >= len2) break;

            ret += (num1[pos1] - '0') * (num2[pos2] - '0');
        }

        ans[pos--] = '0' + ret % 10;
    }

    if (ans[++pos] == '0') ++pos;

    return &ans[pos];
}
