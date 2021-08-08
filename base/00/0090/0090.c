// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//
//
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
//
//
// 示例 2：
//
//
// 输入：nums = [0]
// 输出：[[],[0]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
//
//
//
// Related Topics 数组 回溯算法
// 👍 481 👎 0

#define MAXN 1024

int help_len, *help[MAXN], help_col[MAXN];
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void dfs(const int nums[], int size, int cur, bool used[], int ans[], int len) {
    {
        help_col[help_len] = len, help[help_len] = malloc(len * sizeof(int));
        memcpy(help[help_len++], ans, len * sizeof(int));
    }
    for (int i = cur; i < size; ++i) {
        if (used[i]) continue;
        if (i && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = true, ans[len] = nums[i];
        dfs(nums, size, i + 1, used, ans, len + 1);
        used[i] = false;
    }
}
int **subsetsWithDup(int *nums, int size, int *returnSize, int **returnColumnSizes) {
    int res[size];
    bool used[size];

    memset(used, 0, sizeof(used));
    qsort(nums, size, sizeof(int), cmp);

    help_len = 0;
    dfs(nums, size, 0, used, res, 0);
    *returnSize = help_len;

    int **ans          = malloc(help_len * sizeof(int **));
    *returnColumnSizes = malloc(help_len * sizeof(int));

    memcpy(ans, help, help_len * sizeof(int **));
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));

    return ans;
}
