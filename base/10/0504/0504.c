// 给定一个整数，将其转化为7进制，并以字符串形式输出。
//
// 示例 1:
//
//
// 输入: 100
// 输出: "202"
//
//
// 示例 2:
//
//
// 输入: -7
// 输出: "-10"
//
//
// 注意: 输入范围是 [-1e7, 1e7] 。
// 👍 56 👎 0

char *convertToBase7(int num) {
    int pos             = 10;
    bool sign           = num < 0;
    static char str[11] = { '\0' };

    if (sign) num = -num;
    while (num) {
        str[--pos] = (num % 7) + '0', num /= 7;
    }
    if (pos == 10) str[--pos] = '0';
    if (sign) str[--pos] = '-';

    return &str[pos];
}