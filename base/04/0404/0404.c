//计算给定二叉树的所有左叶子之和。
//
// 示例：
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//
//
// Related Topics 树
// 👍 222 👎 0
int dfs(struct TreeNode *root, bool isLeft) {
    int sum = 0;
    if (isLeft && !root->left && !root->right) sum += root->val;
    if (root->left) sum += dfs(root->left, true);
    if (root->right) sum += dfs(root->right, false);
    return sum;
}
int sumOfLeftLeaves(struct TreeNode *root) {
    return root ? dfs(root, false) : 0;
}