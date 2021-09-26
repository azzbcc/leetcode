//求解一个给定的方程，将x以字符串"x=#value"的形式返回。该方程仅包含'+'，' - '操作，变量 x 和其对应系数。
//
// 如果方程没有解，请返回“No solution”。
//
// 如果方程有无限解，则返回“Infinite solutions”。
//
// 如果方程中只有一个解，要保证返回值 x 是一个整数。
//
// 示例 1：
//
// 输入: "x+5-3+x=6+x-2"
// 输出: "x=2"
//
//
// 示例 2:
//
// 输入: "x=x"
// 输出: "Infinite solutions"
//
//
// 示例 3:
//
// 输入: "2x=x"
// 输出: "x=0"
//
//
// 示例 4:
//
// 输入: "2x+3x-6x=x+2"
// 输出: "x=-1"
//
//
// 示例 5:
//
// 输入: "x=x+2"
// 输出: "No solution"
//
// Related Topics 数学 字符串 模拟 👍 78 👎 0

char *solveEquation(char *equation) {
    int cur = 0, base = 1;
    static char str[0x400];
    int ss[2] = { 0 }, pos = 0;
    bool equal = false, exist = false;
    for (char *p = equation; *p; ++p) {
        if (isdigit(*p)) {
            cur *= 10, cur += *p - '0', exist = true;
        } else if (*p == 'x') {
            if (!exist) cur = 1;
            pos = 1;
        } else if (*p == '+') {
            ss[pos] += base * cur, cur = pos = 0, base = equal ? -1 : 1, exist = false;
        } else if (*p == '-') {
            ss[pos] += base * cur, cur = pos = 0, base = equal ? 1 : -1, exist = false;
        } else if (*p == '=') {
            ss[pos] += base * cur, cur = pos = 0, base = -1, equal = true, exist = false;
        }
    }
    ss[pos] += base * cur;
    if (!ss[1]) return ss[0] ? "No solution" : "Infinite solutions";

    sprintf(str, "x=%d", -1 * ss[0] / ss[1]);
    return str;
}
