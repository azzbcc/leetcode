// 如果长度为 n 的数组 nums 满足下述条件，则认为该数组是一个 漂亮数组 ：
//
//
// nums 是由范围 [1, n] 的整数组成的一个排列。
// 对于每个 0 <= i < j < n ，均不存在下标 k（i < k < j）使得 2 * nums[k] == nums[i] + nums[j] 。
//
//
//
// 给你整数 n ，返回长度为 n 的任一 漂亮数组 。本题保证对于给定的 n 至少存在一个有效答案。
//
//
//
// 示例 1 ：
//
//
// 输入：n = 4
// 输出：[2,1,4,3]
//
//
// 示例 2 ：
//
//
// 输入：n = 5
// 输出：[3,1,2,5,4]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 1000
//
//
//
//
// Related Topics 数组 数学 分治 👍 195 👎 0

#define MAXN 1000
int help[MAXN + 1][MAXN + 1] = { [1] = { 1, 1 } };
void dfs(int n) {
    if (help[n][0]) return;

    help[n][0] = 1;
    dfs((n + 1) / 2), dfs(n / 2);
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        help[n][i] = help[(n + 1) / 2][i] * 2 - 1;
    }
    for (int i = (n + 3) / 2; i <= n; ++i) {
        help[n][i] = help[n / 2][i - (n + 1) / 2] * 2;
    }
}
int *beautifulArray(int n, int *returnSize) {
    dfs(n);

    int *ans = malloc((*returnSize = n) * sizeof(int));
    memcpy(ans, &help[n][1], n * sizeof(int));
    return ans;
}
