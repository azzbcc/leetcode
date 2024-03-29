// 对于给定的整数 n, 如果n的k（k>=2）进制数的所有数位全为1，则称 k（k>=2）是 n 的一个好进制。
//
// 以字符串的形式给出 n, 以字符串的形式返回 n 的最小好进制。
//
//
//
// 示例 1：
//
//
// 输入："13"
// 输出："3"
// 解释：13 的 3 进制是 111。
//
//
// 示例 2：
//
//
// 输入："4681"
// 输出："8"
// 解释：4681 的 8 进制是 11111。
//
//
// 示例 3：
//
//
// 输入："1000000000000000000"
// 输出："999999999999999999"
// 解释：1000000000000000000 的 999999999999999999 进制是 11。
//
//
//
//
// 提示：
//
//
// n的取值范围是 [3, 10^18]。
// 输入总是有效且没有前导 0。
//
//
//
// Related Topics 数学 二分查找
// 👍 93 👎 0

char *smallestGoodBase(char *sn) {
    // n = {11...11}k = k^l + k^(l-1) + ... + k^1 + k^0
    // (k+1)^l = k^l + C(l,1)k^(l-1) + ... + C(l,l-1)k^1 + k^0 > n
    // k^l < n < (k+1)^l
    // k < n^(1/l) < k+1
    static char str[0x40];
    long n = atol(sn), ans = n - 1, tn = ans;

    for (int l = log2(n), k; l > 1 && tn; --l) {
        tn = ans, k = pow(n, 1.0 / l);
        for (long i = 0, base = 1; i < l && tn >= 0; ++i, tn -= base *= k) {}
        if (tn == 0) ans = k;
    }
    sprintf(str, "%ld", ans);

    return str;
}
