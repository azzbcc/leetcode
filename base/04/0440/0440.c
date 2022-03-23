// 给定整数 n 和 k，返回 [1, n] 中字典序第 k 小的数字。
//
//
//
// 示例 1:
//
//
// 输入: n = 13, k = 2
// 输出: 10
// 解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
//
//
// 示例 2:
//
//
// 输入: n = 1, k = 1
// 输出: 1
//
//
//
//
// 提示:
//
//
// 1 <= k <= n <= 10⁹
//
// Related Topics 字典树 👍 330 👎 0

int findKthNumber(int n, int k) {
    int ans = 1;
    for (k--; k;) {
        int step = 0;
        for (long first = ans, last = ans + 1; first <= n;
             step += last - first, first *= 10, last = fmin(last * 10, n + 1)) {}
        if (k >= step) {
            ans += 1, k -= step;
        } else {
            ans *= 10, k -= 1;
        }
    }
    return ans;
}
