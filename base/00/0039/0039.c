// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的数字可以无限制重复被选取。
//
// 说明：
//
//
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1：
//
// 输入：candidates = [2,3,6,7], target = 7,
// 所求解集为：
// [
//   [7],
//   [2,2,3]
// ]
//
//
// 示例 2：
//
// 输入：candidates = [2,3,5], target = 8,
// 所求解集为：
// [
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
// ]
//
//
//
// 提示：
//
//
// 1 <= candidates.length <= 30
// 1 <= candidates[i] <= 200
// candidate 中的每个元素都是独一无二的。
// 1 <= target <= 500
//
// Related Topics 数组 回溯算法
// 👍 873 👎 0
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
        res[len] = candidates[i];
        dfs(candidates + i, candidatesSize - i, res, len + 1, target - candidates[i]);
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    int result[MAXN], **ans;

    help_len = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(candidates, candidatesSize, result, 0, target);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
