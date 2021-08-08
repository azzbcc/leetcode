// 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
//
// 示例:
//
//
// 输入: [4, 6, 7, 7]
// 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
// 说明:
//
//
// 给定数组的长度不会超过15。
// 数组中的整数范围是 [-100,100]。
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
//
// Related Topics 深度优先搜索
// 👍 137 👎 0

#define MAXN 32752

int help[MAXN][15] = { 0 }, help_col[MAXN] = { 0 }, help_len = 0;

void dfs(int *nums, int size, int pos, int result[16]) {
    if (result[0] > 1) {
        help_col[help_len] = result[0];
        memcpy(help[help_len++], result + 1, result[0] * sizeof(int));
    }
    int first[201] = { 0 };
    for (int i = pos; i < size; ++i) {
        if (!first[100 + nums[i]]) first[100 + nums[i]] = i + 1;
    }
    for (int i = pos; i < size; ++i) {
        if (first[100 + nums[i]] <= i) continue;
        if (result[0] && result[result[0]] > nums[i]) continue;

        result[0] += 1;
        result[result[0]] = nums[i];
        dfs(nums, size, i + 1, result);
        result[0] -= 1;
    }
}
int **findSubsequences(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int **ans = NULL, result[16] = { 0 };

    help_len = 0;
    dfs(nums, numsSize, 0, result);

    *returnSize = help_len;
    ans = calloc(help_len, sizeof(int *)), *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; ++i) {
        ans[i] = calloc(help_col[i], sizeof(int));
        memcpy(ans[i], help[i], help_col[i] * sizeof(int));
    }
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));
    return ans;
}
