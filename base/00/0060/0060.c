// 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
//
// 给定 n 和 k，返回第 k 个排列。
//
// 说明：
//
//
// 给定 n 的范围是 [1, 9]。
// 给定 k 的范围是[1, n!]。
//
//
// 示例 1:
//
// 输入: n = 3, k = 3
// 输出: "213"
//
//
// 示例 2:
//
// 输入: n = 4, k = 9
// 输出: "2314"
//
// Related Topics 数学 回溯算法
// 👍 371 👎 0

static int help[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
char* getPermutation(int n, int k) {
    bool visited[n + 1];
    static char str[10] = { '\0' };
    for (int i = 1; i <= n; visited[i++] = false) {}

    k -= 1;
    for (int i = 0, c; i < n; ++i) {
        int nth = k / help[n - i - 1];
        k = k % help[n - i - 1];
        for (c = 1; c <= n; ++c) {
            if (visited[c]) continue;
            if (nth-- == 0) break;
        }
        visited[c] = true, str[i] = c + '0';
    }
    str[n] = '\0';

    return str;
}
