// 将非负整数 num 转换为其对应的英文表示。
//
//
//
// 示例 1：
//
//
// 输入：num = 123
// 输出："One Hundred Twenty Three"
//
//
// 示例 2：
//
//
// 输入：num = 12345
// 输出："Twelve Thousand Three Hundred Forty Five"
//
//
// 示例 3：
//
//
// 输入：num = 1234567
// 输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//
//
// 示例 4：
//
//
// 输入：num = 1234567891
// 输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
//
//
//
//
// 提示：
//
//
// 0 <= num <= 2³¹ - 1
//
// Related Topics 递归 数学 字符串 👍 189 👎 0

#define MAXN 0x100
char *d1[] = { "Zero",     "One",     "Two",     "Three",     "Four",     "Five",     "Six",
               "Seven",    "Eight",   "Nine",    "Ten",       "Eleven",   "Twelve",   "Thirteen",
               "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty" };
char *d2[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
char *numberToWords1000(int num) {
    if (num <= 20) return d1[num];
    static char str[MAXN];
    char *p = str;

    if (num >= 100) {
        p += sprintf(p, "%s Hundred", d1[num / 100]);
        if (num %= 100, num) *p++ = ' ';
    }
    if (num > 20) {
        p += sprintf(p, "%s", d2[num / 10]);
        if (num %= 10, num) *p++ = ' ';
    }
    if (num) sprintf(p, "%s", d1[num]);

    return str;
}
char *numberToWords(int num) {
    if (num <= 20) return d1[num];
    static char str[MAXN];
    char *p = str;

    if (num >= 1000000000) {
        p += sprintf(p, "%s Billion", numberToWords1000(num / 1000000000));
        if (num %= 1000000000, num) *p++ = ' ';
    }
    if (num >= 1000000) {
        p += sprintf(p, "%s Million", numberToWords1000(num / 1000000));
        if (num %= 1000000, num) *p++ = ' ';
    }
    if (num >= 1000) {
        p += sprintf(p, "%s Thousand", numberToWords1000(num / 1000));
        if (num %= 1000, num) *p++ = ' ';
    }
    if (num) sprintf(p, "%s", numberToWords1000(num));
    return str;
}