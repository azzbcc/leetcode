// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
// 示例:
//
// 输入: [1,2,3]
// 输出:
// [
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
// ]
// Related Topics 回溯算法
// 👍 962 👎 0

#define MAXN 0x10000
typedef struct node_t {
    int val;
    struct node_t *next;
} node_t;
int *help[MAXN] = { NULL }, help_len = 0;

void dfs(node_t *list, int size, int res[], int pos) {
    if (pos >= size) {
        assert(help_len < MAXN);
        help[help_len] = calloc(size, sizeof(int));
        memcpy(help[help_len++], res, size * sizeof(int));
    }
    for (node_t *pre = list, *cur = pre->next; cur; pre = cur, cur = cur->next) {
        res[pos] = cur->val, pre->next = cur->next;
        dfs(list, size, res, pos + 1);
        pre->next = cur;
    }
}
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int res[numsSize], **ans;
    node_t nodes[numsSize + 1];

    for (int i = 0; i < numsSize; ++i) {
        nodes[i].next = &nodes[i + 1], nodes[i + 1].val = nums[i];
    }
    nodes[numsSize].next = NULL;

    help_len = 0;
    dfs(nodes, numsSize, res, 0);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; (*returnColumnSizes)[i++] = numsSize) {}

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
