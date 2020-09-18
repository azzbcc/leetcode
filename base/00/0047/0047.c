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
typedef struct node_t {
    int val, count;
    struct node_t *next;
} node_t;
int *help[MAXN] = { NULL }, help_len = 0;
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void dfs(node_t *list, int size, int res[], int pos) {
    if (pos >= size) {
        assert(help_len < MAXN);
        help[help_len] = calloc(size, sizeof(int));
        memcpy(help[help_len++], res, size * sizeof(int));
    }
    for (node_t *pre = list, *cur = pre->next; cur; pre = cur, cur = cur->next) {
        cur->count -= 1, res[pos] = cur->val;
        if (!cur->count) pre->next = cur->next;
        dfs(list, size, res, pos + 1);
        cur->count += 1, pre->next = cur;
    }
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int res[numsSize], **ans;
    node_t nodes[numsSize + 1];

    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0, len = 0; i < numsSize; ++i) {
        if (len && nums[i] == nodes[len].val) {
            nodes[len].count++;
        } else {
            len += 1;
            nodes[len].val = nums[i], nodes[len].count = 1;
            nodes[len].next = NULL, nodes[len - 1].next = &nodes[len];
        }
    }

    help_len = 0;
    dfs(nodes, numsSize, res, 0);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; (*returnColumnSizes)[i++] = numsSize) {}

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
