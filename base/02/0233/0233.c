// 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
//
//
//
// 示例 1：
//
//
// 输入：n = 13
// 输出：6
//
//
// 示例 2：
//
//
// 输入：n = 0
// 输出：0
//
//
//
//
// 提示：
//
//
// 0 <= n <= 2 * 109
//
// Related Topics 递归 数学 动态规划
// 👍 266 👎 0

int countDigitOne(int n) {
    int ans = 0;
    for (long base = 1; base <= n; base *= 10) {
        int x = n / 10 / base, y = n - x * base * 10;
        ans += x * base + fmax(fmin(y - base + 1, base), 0);
    }
    return ans;
}
