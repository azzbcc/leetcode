// 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//
// 示例：
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
// 输出：
// 1
//
// 解释：
// 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
//
//
//
//
// 提示：
//
//
// 树中至少有 2 个节点。
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
//
// Related Topics 树
// 👍 162 👎 0

int getMinimumDifference(struct TreeNode *root) {
    int ans               = INT32_MAX;
    struct TreeNode *prev = NULL;
    while (root) {
        if (root->left) {
            struct TreeNode *morris_prev = root->left;
            while (morris_prev->right && morris_prev->right != root) {
                morris_prev = morris_prev->right;
            }

            if (morris_prev->right) {
                morris_prev->right = NULL;
            } else {
                morris_prev->right = root, root = root->left;
                continue;
            }
        }
        if (prev && ans > root->val - prev->val) ans = root->val - prev->val;
        prev = root, root = root->right;
    }
    return ans;
}
