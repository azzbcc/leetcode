// 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
//
//
//
// 示例 1：
//
//
// 输入：x = 4
// 输出：2
//
//
// 示例 2：
//
//
// 输入：x = 8
// 输出：2
// 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
//
//
//
//
// 提示：
//
//
// 0 <= x <= 2³¹ - 1
//
//
// Related Topics 数学 二分查找 👍 1448 👎 0

#if 0
int mySqrt(int x) {
    for (int a = x, b = 1; x > b; x = b + (x - b) / 2, b = a / x) {}
    return x;
}
#else
typedef struct {
    int a, b;
} data_t;
data_t my_sqrt(int x) {
    data_t ans = { 0 };
    if (x >= 100) ans = my_sqrt(x / 100);

    int n = 1;
    for (ans.b = ans.b * 100 + x % 100; n < 10 && n * (20 * ans.a + n) <= ans.b; ++n) {}
    n--, ans.b = ans.b - n * (20 * ans.a + n), ans.a = ans.a * 10 + n;
    return ans;
}
int mySqrt(int x) {
    return my_sqrt(x).a;
}
#endif
