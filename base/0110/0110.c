// 给定一个二叉树，判断它是否是高度平衡的二叉树。
//
// 本题中，一棵高度平衡二叉树定义为：
//
//
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//
// 示例 1:
//
// 给定二叉树 [3,9,20,null,null,15,7]
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// 返回 true 。
//
// 示例 2:
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4]
//
//        1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//
//
// 返回 false 。
//
//
// Related Topics 树 深度优先搜索
// 👍 417 👎 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
bool treeBalanceDepth(struct TreeNode *root, int *depth) {
    if (!root) {
        *depth = 0;
        return true;
    }

    int left, right;
    if (!treeBalanceDepth(root->left, &left)) return false;
    if (!treeBalanceDepth(root->right, &right)) return false;
    if ((left - right) * (left - right) >= 2) return false;

    *depth = MAX(left, right) + 1;

    return true;
}

bool isBalanced(struct TreeNode *root) {
    int depth = 0;
    return treeBalanceDepth(root, &depth);
}
