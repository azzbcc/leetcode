// 实现 int sqrt(int x) 函数。
//
// 计算并返回 x 的平方根，其中 x 是非负整数。
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
// 示例 1:
//
// 输入: 4
// 输出: 2
//
//
// 示例 2:
//
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842...,
//    由于返回类型是整数，小数部分将被舍去。
//
// Related Topics 数学 二分查找
// 👍 489 👎 0

int mySqrt_1(int x) {
    int m = x, n = 1;
    while (m > n) {
        m = n + (m - n) / 2, n = x / m;
    }
    return m;
}

int my_sqrt(int x, int *mod) {
    int tmp = 0, n = 1;
    if (x >= 100) tmp = my_sqrt(x / 100, mod);
    for (*mod = *mod * 100 + x % 100; n < 10 && n * (20 * tmp + n) <= *mod; n++) {}
    n -= 1, *mod = *mod - n * (20 * tmp + n);
    return tmp * 10 + n;
}
int mySqrt_2(int x) {
    int mod = 0;
    return my_sqrt(x, &mod);
}

int (*mySqrt)(int x) = mySqrt_2;
