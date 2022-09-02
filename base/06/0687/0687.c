// 给定一个二叉树的
// root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
//
// 两个节点之间的路径长度 由它们之间的边数表示。
//
//
//
// 示例 1:
//
//
//
//
// 输入：root = [5,4,5,1,1,5]
// 输出：2
//
//
// 示例 2:
//
//
//
//
// 输入：root = [1,4,5,4,4,5]
// 输出：2
//
//
//
//
// 提示:
//
//
// 树的节点数的范围是
// [0, 10⁴]
// -1000 <= Node.val <= 1000
// 树的深度将不超过 1000
//
//
// Related Topics 树 深度优先搜索 二叉树 👍 660 👎 0

int dfs(struct TreeNode *root, int *ans) {
    if (!root) return 0;
    int l = dfs(root->left, ans), r = dfs(root->right, ans);
    l    = root->left && root->val == root->left->val ? l + 1 : 0;
    r    = root->right && root->val == root->right->val ? r + 1 : 0;
    *ans = fmax(*ans, l + r);
    return fmax(l, r);
}
int longestUnivaluePath(struct TreeNode *root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
