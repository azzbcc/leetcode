// 统计所有小于非负整数 n 的质数的数量。
//
//
//
// 示例 1：
//
// 输入：n = 10
// 输出：4
// 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
//
//
// 示例 2：
//
// 输入：n = 0
// 输出：0
//
//
// 示例 3：
//
// 输入：n = 1
// 输出：0
//
//
//
//
// 提示：
//
//
// 0 <= n <= 5 * 106
//
// Related Topics 哈希表 数学
// 👍 532 👎 0

#define MAXN 5000000

int prime[350000], c = 0;
bool flag[MAXN + 1] = { false };

void euler() {
    if (c) return;
    for (int i = 2; i <= MAXN; i++) {
        if (!flag[i]) prime[c++] = i;

        for (int j = 0; j < c && i * prime[j] <= MAXN; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int countPrimes(int n) {
    int ans = 0;

    euler();
    for (int mid, end = c - 1; ans <= end;) {
        mid = (ans + end) / 2;
        if (prime[mid] < n) {
            ans = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}
