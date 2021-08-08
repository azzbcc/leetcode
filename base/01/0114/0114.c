//给定一个二叉树，原地将它展开为一个单链表。
//
//
//
// 例如，给定二叉树
//
//     1
//   / \
//  2   5
//  / \   \
//3   4   6
//
// 将其展开为：
//
// 1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6
// Related Topics 树 深度优先搜索
// 👍 494 👎 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode *root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    if (!root->left) return;

    struct TreeNode *right= root->right;
    root->right = root->left;
    root->left = NULL;

    while (root->right) {
        root = root->right;
    }
    root->right = right;
}