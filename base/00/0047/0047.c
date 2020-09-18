// 给定一个可包含重复数字的序列，返回所有不重复的全排列。
//
// 示例:
//
// 输入: [1,1,2]
// 输出:
// [
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
// ]
// Related Topics 回溯算法
// 👍 420 👎 0

#define MAXN 0x10000
int *help[MAXN] = { NULL }, help_len = 0;
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void dfs(int *nums, int size, int res[], int pos, bool visited[]) {
    if (pos >= size) {
        assert(help_len < MAXN);
        help[help_len] = calloc(size, sizeof(int));
        memcpy(help[help_len++], res, size * sizeof(int));
        return;
    }
    bool record = false;
    for (int i = 0; i < size; ++i) {
        if (visited[i] || record && nums[i] == res[pos]) continue;
        visited[i] = true, record = true, res[pos] = nums[i];
        dfs(nums, size, res, pos + 1, visited);
        visited[i] = false;
    }
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int res[numsSize], **ans;
    bool visited[numsSize];

    help_len = 0;
    memset(visited, 0, sizeof(visited));
    qsort(nums, numsSize, sizeof(int), cmp);
    dfs(nums, numsSize, res, 0, visited);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; (*returnColumnSizes)[i++] = numsSize) {}

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
