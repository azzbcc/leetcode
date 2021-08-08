// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
// 示例:
//
// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Related Topics 回溯算法
// 👍 353 👎 0
#define MAXN 0x10000
int *help[MAXN] = { NULL }, help_len = 0;
void dfs(int n, int k, int res[], int pos) {
    if (pos >= k) {
        assert(help_len < MAXN);
        help[help_len] = calloc(k, sizeof(int));
        memcpy(help[help_len++], res, k * sizeof(int));
        return;
    }
    for (int i = (pos ? res[pos - 1] : 0) + 1; k - (pos + 1) <= n - i; ++i) {
        res[pos] = i;
        dfs(n, k, res, pos + 1);
    }
}
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    int res[k], **ans;

    help_len = 0;
    dfs(n, k, res, 0);

    *returnSize = help_len;

    *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; (*returnColumnSizes)[i++] = k) {}

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
