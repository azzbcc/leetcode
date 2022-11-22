// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
//
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。因为答案可能很大，所以返回答案 对 10⁹ + 7 取模 后的值。
//
// 示例 1：
//
// 输入：n = 1, a = 2, b = 3
// 输出：2
//
//
// 示例 2：
//
// 输入：n = 4, a = 2, b = 3
// 输出：6
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁹
// 2 <= a, b <= 4 * 10⁴
//
//
// Related Topics 数学 二分查找 👍 158 👎 0

#define MOD 1000000007
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int nthMagicalNumber(int n, int a, int b) {
    int base = lcm(a, b), c = base / a + base / b - 1;
    int ans = 1L * (n / c) * base % MOD, l = 0;
    n %= c;
    for (int r = base, mid; l <= r;) {
        mid = l + (r - l) / 2;
        if (mid / a + mid / b >= n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return (ans + l % MOD) % MOD;
}