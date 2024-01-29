// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//
// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//
//
//
// 示例 1：
//
//
// 输入：num1 = "11", num2 = "123"
// 输出："134"
//
//
// 示例 2：
//
//
// 输入：num1 = "456", num2 = "77"
// 输出："533"
//
//
// 示例 3：
//
//
// 输入：num1 = "0", num2 = "0"
// 输出："0"
//
//
//
//
//
//
// 提示：
//
//
// 1 <= num1.length, num2.length <= 10⁴
// num1 和num2 都只包含数字 0-9
// num1 和num2 都不包含任何前导零
//
//
// Related Topics 数学 字符串 模拟 👍 811 👎 0

#define MAX 10000
char *addStrings(char *n1, char *n2) {
    static char str[MAX + 2] = { '\0' };

    int pos = MAX + 1;
    for (int c = 0, l1 = strlen(n1), l2 = strlen(n2); c || l1 || l2; c /= 10) {
        if (l1) c += n1[--l1] - '0';
        if (l2) c += n2[--l2] - '0';
        str[--pos] = c % 10 + '0';
    }
    return &str[pos];
}
