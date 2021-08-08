//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
// 例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回其自底向上的层次遍历为：
//
// [
//  [15,7],
//  [9,20],
//  [3]
//]
//
// Related Topics 树 广度优先搜索
// 👍 309 👎 0
#define MAXN 0x1000
int help[MAXN][MAXN], help_col[MAXN], help_len;
void dfs(struct TreeNode *root, int depth) {
    if (!root) {
        if (help_len < depth) help_len = depth;
        return;
    }

    help[depth][help_col[depth]++] = root->val;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    help_len = 0;
    memset(help_col, 0, sizeof(help_col));
    dfs(root, 0);

    int **ans   = calloc(help_len, sizeof(int *));
    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0, pos; i < help_len; ++i) {
        pos                     = help_len - i - 1;
        ans[i]                  = calloc(help_col[pos], sizeof(int));
        (*returnColumnSizes)[i] = help_col[pos];
        memcpy(ans[i], help[pos], (*returnColumnSizes)[i] * sizeof(int));
    }

    return ans;
}
