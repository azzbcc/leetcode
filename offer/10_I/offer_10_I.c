// 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
//
//
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
//
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
//
//
//
// 示例 1：
//
//
// 输入：n = 2
// 输出：1
//
//
// 示例 2：
//
//
// 输入：n = 5
// 输出：5
//
//
//
//
// 提示：
//
//
// 0 <= n <= 100
//
// Related Topics 记忆化搜索 数学 动态规划 👍 223 👎 0

#if 0
#define MOD 1000000007
int fib(int n) {
    int a = 0, b = 1;
    if (n < 2) return n;
    for (int i = 1, t; i < n; ++i) {
        t = (a + b) % MOD, a = b, b = t;
    }
    return b;
}
#else
#define MOD 1000000007
typedef struct {
    int row, col;
    long data[2][2];
} matrix_t;
matrix_t mul(matrix_t a, matrix_t b) {
    matrix_t result = { a.row, b.col };
    for (int i = 0; i < a.row; ++i) {
        for (int j = 0; j < b.col; ++j) {
            for (int k = 0; k < a.col; ++k) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] %= MOD;
        }
    }
    return result;
}
int fib(int n) {
    if (n < 2) return n;
    matrix_t ans  = { 1, 2, .data[0][0] = 1 };
    matrix_t base = { 2, 2, { { 1, 1 }, { 1, 0 } } };

    for (n--; n > 0; n /= 2) {
        if (n & 1) ans = mul(ans, base);
        base = mul(base, base);
    }
    return ans.data[0][0];
}
#endif