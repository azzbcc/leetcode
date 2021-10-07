// 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
//
// 如果小数部分为循环小数，则将循环的部分括在括号内。
//
// 如果存在多个答案，只需返回 任意一个 。
//
// 对于所有给定的输入，保证 答案字符串的长度小于 10⁴ 。
//
//
//
// 示例 1：
//
//
// 输入：numerator = 1, denominator = 2
// 输出："0.5"
//
//
// 示例 2：
//
//
// 输入：numerator = 2, denominator = 1
// 输出："2"
//
//
// 示例 3：
//
//
// 输入：numerator = 2, denominator = 3
// 输出："0.(6)"
//
//
// 示例 4：
//
//
// 输入：numerator = 4, denominator = 333
// 输出："0.(012)"
//
//
// 示例 5：
//
//
// 输入：numerator = 1, denominator = 5
// 输出："0.2"
//
//
//
//
// 提示：
//
//
// -2³¹ <= numerator, denominator <= 2³¹ - 1
// denominator != 0
//
// Related Topics 哈希表 数学 字符串 👍 263 👎 0

#define MAXN 1024
typedef struct {
    long now, index;
    long div, mod;
    UT_hash_handle hh;
} * hash_t;
char *fractionToDecimal(int numerator, int denominator) {
    static char str[MAXN];
    char decimal[MAXN] = { '\0' }, *ss = str;

    long a = numerator, b = denominator;
    if (b < 0) a *= -1, b *= -1;
    if (a < 0) *ss++ = '-', a *= -1;
    long digit = a / b, mod = a % b;

    if (!mod) return sprintf(ss, "%ld", digit), str;
    hash_t data = NULL, cur, next;
    for (long now = mod * 10, i = 0; now; now = cur->mod * 10, ++i) {
        HASH_FIND_INT(data, &now, cur);
        if (cur) break;
        cur = malloc(sizeof(*cur)), decimal[i] = '0' + now / b;
        cur->now = now, cur->index = i, cur->div = now / b, cur->mod = now % b;
        HASH_ADD_INT(data, now, cur);
    }
    int offset = cur->index, end = cur->mod;
    HASH_ITER(hh, data, cur, next) {
        HASH_DEL(data, cur);
        free(cur);
    }
    if (end) {
        sprintf(ss, "%ld.%.*s(%s)", digit, offset, decimal, decimal + offset);
    } else {
        sprintf(ss, "%ld.%s", digit, decimal);
    }
    return str;
}