// 请你帮忙设计一个程序，用来找出第 n 个丑数。
//
// 丑数是可以被 a 或 b 或 c 整除的 正整数。
//
//
//
// 示例 1：
//
// 输入：n = 3, a = 2, b = 3, c = 5
// 输出：4
// 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
//
// 示例 2：
//
// 输入：n = 4, a = 2, b = 3, c = 4
// 输出：6
// 解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
//
//
// 示例 3：
//
// 输入：n = 5, a = 2, b = 11, c = 13
// 输出：10
// 解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
//
//
// 示例 4：
//
// 输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
// 输出：1999999984
//
//
//
//
// 提示：
//
//
// 1 <= n, a, b, c <= 10^9
// 1 <= a * b * c <= 10^18
// 本题结果在 [1, 2 * 10^9] 的范围内
//
// Related Topics 数学 二分查找
// 👍 54 👎 0
long lcm(long a, long b) {
    long gcd = a;
    for (long t1, t2 = b; t2; t1 = gcd % t2, gcd = t2, t2 = t1) {}
    return a / gcd * b;
}
long countUgly(long n, long l, long ab, long ac, long bc, int a, int b, int c) {
    return n / a + n / b + n / c - n / ab - n / ac - n / bc + n / l;
}
int nthUglyNumber(int n, int a, int b, int c) {
    long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), l = lcm(ab, ac);
    long count = countUgly(l, l, ab, ac, bc, a, b, c);
    long base  = n / count * l, end = l;

    n %= count;
    for (long beg = 0, mid, tc; beg < end;) {
        mid = (beg + end) / 2, tc = countUgly(mid, l, ab, ac, bc, a, b, c);
        if (n > tc) {
            beg = mid + 1;
        } else {
            end = mid;
        }
    }

    return base + end;
}
