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
typedef struct {
    int val, count;
} node_t;
int *help[MAXN] = { NULL }, help_len = 0;
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void dfs(node_t map[], int size, int len, int res[], int pos) {
    if (pos >= size) {
        assert(help_len < MAXN);
        help[help_len] = calloc(size, sizeof(int));
        memcpy(help[help_len++], res, size * sizeof(int));
        return;
    }
    for (int i = 0; i < len; ++i) {
        if (!map[i].count) continue;
        map[i].count -= 1, res[pos] = map[i].val;
        dfs(map, size, len, res, pos + 1);
        map[i].count += 1;
    }
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    node_t nodes[numsSize];
    int len = 0, res[numsSize], **ans;

    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; ++i) {
        if (len && nums[i] == nodes[len - 1].val) {
            nodes[len - 1].count++;
        } else {
            nodes[len].val = nums[i], nodes[len].count = 1, len += 1;
        }
    }

    help_len = 0;
    dfs(nodes, numsSize, len, res, 0);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; (*returnColumnSizes)[i++] = numsSize) {}

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
