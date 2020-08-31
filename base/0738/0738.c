//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
//
// 示例 1:
//
// 输入: N = 10
//输出: 9
//
//
// 示例 2:
//
// 输入: N = 1234
//输出: 1234
//
//
// 示例 3:
//
// 输入: N = 332
//输出: 299
//
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。
// Related Topics 贪心算法
// 👍 65 👎 0

int monotoneIncreasingDigits(int N) {
    int sn[10] = { 0 }, len = 0, pos = -1;
    for (int n = N; n; n /= 10) {
        sn[len++] = n % 10;
    }
    for (int i = len - 1; i > 0; --i) {
        if (sn[i] > sn[i - 1]) {
            pos = i;
            break;
        }
    }
    if (pos < 0) return N;
    while (++pos < len && sn[pos] == sn[pos - 1]) {}

    sn[--pos] -= 1;
    for (int i = 0; i < pos; sn[i++] = 9) {}

    int sum = 0;
    while (--len >= 0) {
        sum *= 10, sum += sn[len];
    }

    return sum;
}
