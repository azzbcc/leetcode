//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
// 注意：
//
//
// num1 和num2 的长度都小于 5100.
// num1 和num2 都只包含数字 0-9.
// num1 和num2 都不包含任何前导零。
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
//
// Related Topics 字符串
// 👍 211 👎 0

#define MAX 5100
char *addStrings(char *num1, char *num2) {
    static char ans[MAX + 1] = { 0 };
    int carry = 0, l1 = strlen(num1), l2 = strlen(num2), la = MAX;

    while (l1 || l2 || carry) {
        if (l1) carry += num1[l1 - 1] - '0';
        if (l2) carry += num2[l2 - 1] - '0';

        ans[--la] = '0' + carry % 10;

        if (l1) l1 -= 1;
        if (l2) l2 -= 1;
        carry /= 10;
    }

    return &ans[la];
}
