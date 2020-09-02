// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"012
// 3"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
//
//
// Related Topics 数学
// 👍 66 👎 0

bool isNumber(char *s) {
    bool digit_need = false;

    // skip blank on the front
    while (isblank(*s)) s++;

    // skip sign operator
    if (*s == '+' || *s == '-') s++;

    // check Integer part
    if (isdigit(*s)) {
        while (isdigit(*s)) s++;
    } else if (*s != '.') {
        return false;
    } else {
        digit_need = true;
    }

    // check fractional part
    if (*s == '.') {
        s++;
        if (digit_need && !isdigit(*s)) return false;
        while (isdigit(*s)) s++;
    }

    // check exponential part
    if (*s == 'E' || *s == 'e') {
        if (*++s == '+' || *s == '-') s++;
        if (!isdigit(*s)) return false;
        while (isdigit(*s)) s++;
    }

    // skip blank on the rear
    while (isblank(*s)) s++;
    return !*s;
}
