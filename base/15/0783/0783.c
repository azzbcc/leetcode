// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//
// 注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同
//
//
//
//
//
// 示例 1：
//
//
// 输入：root = [4,2,6,1,3]
// 输出：1
//
//
// 示例 2：
//
//
// 输入：root = [1,0,48,null,null,12,49]
// 输出：1
//
//
//
//
// 提示：
//
//
// 树中节点数目在范围 [2, 100] 内
// 0 <= Node.val <= 105
//
//
//
// Related Topics 树 深度优先搜索 递归
// 👍 151 👎 0

int minDiffInBST(struct TreeNode *root) {
    int ans = INT32_MAX;
    for (struct TreeNode *prev = NULL, *cur = root; cur;) {
        if (cur->left) {
            struct TreeNode *morris_prev = cur->left;
            while (morris_prev->right && morris_prev->right != cur) {
                morris_prev = morris_prev->right;
            }
            if (morris_prev->right) {
                morris_prev->right = NULL;
            } else {
                morris_prev->right = cur, cur = cur->left;
                continue;
            }
        }
        if (prev) ans = fmin(ans, cur->val - prev->val);
        prev = cur, cur = cur->right;
    }
    return ans;
}