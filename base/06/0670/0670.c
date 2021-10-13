// 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
//
// 示例 1 :
//
//
// 输入: 2736
// 输出: 7236
// 解释: 交换数字2和数字7。
//
//
// 示例 2 :
//
//
// 输入: 9973
// 输出: 9973
// 解释: 不需要交换。
//
//
// 注意:
//
//
// 给定数字的范围是 [0, 10⁸]
//
// Related Topics 贪心 数学 👍 194 👎 0

#define MAXN 10
int maximumSwap(int num) {
    char digit[MAXN], last[MAXN], len;

    sprintf(digit, "%d", num);
    memset(last, -1, sizeof(last));
    for (len = 0; digit[len]; len++) {
        last[digit[len] - '0'] = len;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = MAXN - 1; j > digit[i] - '0'; --j) {
            if (last[j] < i) continue;
            int ans = 0, tmp = digit[i];
            digit[i] = digit[last[j]], digit[last[j]] = tmp;
            for (int k = 0; k < len; ++k) {
                ans *= 10, ans += digit[k] - '0';
            }
            return ans;
        }
    }
    return num;
}