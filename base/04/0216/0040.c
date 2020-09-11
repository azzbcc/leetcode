// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
// 说明：
//
//
// 所有数字都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: k = 3, n = 7
// 输出: [[1,2,4]]
//
//
// 示例 2:
//
// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]
//
// Related Topics 数组 回溯算法
// 👍 184 👎 0

int *help[12], help_len = 0;
static void dfs(int k, int n, int res[], int len) {
    if (k > 1) {
        int min = (len ? res[len - 1] : 0) + 1, max = 10 - k, left = (k - 1) * (20 - k) / 2;
        if (min + left < n) min = n - left;
        if (max + left > n) max = (n - (k * k - k) / 2) / k;
        for (int i = min; i <= max; ++i) {
            res[len] = i;
            dfs(k - 1, n - i, res, len + 1);
        }
    } else {
        res[len++] = n, help[help_len] = calloc(len, sizeof(int));
        memcpy(help[help_len++], res, len * sizeof(int));
    }
}
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes) {
    int res[k], **ans = NULL;

    if ((k * (1 + k)) > 2 * n || (k * (19 - k)) < 2 * n) {
        *returnSize = 0, *returnColumnSizes = NULL;
        return NULL;
    }

    help_len = 0;
    dfs(k, n, res, 0);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; ++i) {
        (*returnColumnSizes)[i] = k;
    }
    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * (sizeof(int *)));

    return ans;
}
