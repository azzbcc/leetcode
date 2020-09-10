// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用一次。
//
// 说明：
//
//
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// 示例 2:
//
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]
// Related Topics 数组 回溯算法
// 👍 373 👎 0
#define MAXN 0x1000
int *help[MAXN] = { NULL }, help_col[MAXN] = { 0 }, help_len = 0;
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
static void dfs(int candidates[], int candidatesSize, int res[], int len, int target) {
    if (!target) {
        assert(help_len < MAXN);
        help_col[help_len] = len, help[help_len] = calloc(len, sizeof(int));
        memcpy(help[help_len++], res, len * sizeof(int));
        return;
    }
    for (int i = 0; i < candidatesSize && candidates[i] <= target; ++i) {
        if (i && candidates[i] == candidates[i - 1]) continue;
        res[len] = candidates[i];
        dfs(candidates + i + 1, candidatesSize - i - 1, res, len + 1, target - candidates[i]);
    }
}
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    int result[candidatesSize], **ans;

    help_len = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(candidates, candidatesSize, result, 0, target);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
