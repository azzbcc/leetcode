// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//
//
// 返回:
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]
//
// Related Topics 树 深度优先搜索
// 👍 338 👎 0
#define MAXN 0x1000

int *help[MAXN], help_len, help_col[MAXN];
void dfs(struct TreeNode *root, int sum, int res[], int now) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (sum == root->val) {
            res[now++] = root->val;
            assert(help_len < MAXN);
            help_col[help_len] = now, help[help_len] = calloc(now, sizeof(int));
            memcpy(help[help_len++], res, now * sizeof(int));
        }
        return;
    }
    res[now] = root->val;
    dfs(root->left, sum - root->val, res, now + 1);
    dfs(root->right, sum - root->val, res, now + 1);
}
int **pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes) {
    int res[MAXN], **ans;

    help_len = 0;
    dfs(root, sum, res, 0);

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; ++i) {
        (*returnColumnSizes)[i] = help_col[i];
    }

    ans = calloc(help_len, sizeof(int *));
    memcpy(ans, help, help_len * sizeof(int *));

    return ans;
}
