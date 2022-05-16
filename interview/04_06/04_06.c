// 设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
//
// 如果指定节点没有对应的“下一个”节点，则返回null。
//
// 示例 1:
//
// 输入: root = [2,1,3], p = 1
//
//   2
//  / \
// 1   3
//
// 输出: 2
//
// 示例 2:
//
// 输入: root = [5,3,6,2,4,null,null,1], p = 6
//
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//
// 输出: null
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 143 👎 0

struct TreeNode *inorderSuccessor(struct TreeNode *root, struct TreeNode *p) {
    struct TreeNode *ans = p->right;
    if (ans) {
        for (; ans->left; ans = ans->left) {}
        return ans;
    }
    for (; root;) {
        if (root->val > p->val) {
            ans = root, root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
