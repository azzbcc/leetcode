// 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// 输出：15
//
//
// 示例 2：
//
//
// 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// 输出：19
//
//
//
//
// 提示：
//
//
// 树中节点数目在范围 [1, 10⁴] 之间。
// 1 <= Node.val <= 100
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 113 👎 0

void dfs(struct TreeNode *root, int cur, int *sum, int *max_depth) {
    if (!root) return;
    dfs(root->left, cur + 1, sum, max_depth);
    dfs(root->right, cur + 1, sum, max_depth);
    if (root->left || root->right) return;
    if (*max_depth < cur) {
        *max_depth = cur, *sum = root->val;
    } else if (*max_depth == cur) {
        *sum += root->val;
    }
}
int deepestLeavesSum(struct TreeNode *root) {
    int sum = 0, max_depth = -1;
    dfs(root, 0, &sum, &max_depth);
    return sum;
}
