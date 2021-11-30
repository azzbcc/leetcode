// 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位数字。
//
//
//
// 示例 1：
//
//
// 输入：n = 3
// 输出：3
//
//
// 示例 2：
//
//
// 输入：n = 11
// 输出：0
// 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 2³¹ - 1
//
// Related Topics 数学 二分查找 👍 225 👎 0

#define MAXN 9
int findNthDigit(int n) {
    int c = 1, next = 1, cc[MAXN] = { 0 };
    for (n--; c < MAXN; ++c, next *= 10) {
        cc[c] = cc[c - 1] + MAXN * c * next;
        if (cc[c] >= n) break;
    }
    n -= cc[c - 1], next += n / c, n %= c;
    for (c = MAXN; next; cc[--c] = next % 10, next /= 10) {}
    return cc[c + n];
}