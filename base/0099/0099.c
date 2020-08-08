// 二叉搜索树中的两个节点被错误地交换。
//
// 请在不改变其结构的情况下，恢复这棵树。
//
// 示例 1:
//
// 输入: [1,3,null,null,2]
//
//   1
//  /
// 3
//  \
//   2
//
// 输出: [3,1,null,null,2]
//
//   3
//  /
// 1
//  \
//   2
//
//
// 示例 2:
//
// 输入: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//   /
//  2
//
// 输出: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//   /
//  3
//
// 进阶:
//
//
// 使用 O(n) 空间复杂度的解法很容易实现。
// 你能想出一个只使用常数空间的解决方案吗？
//
// Related Topics 树 深度优先搜索
// 👍 284 👎 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool findFirstDown(struct TreeNode *root, struct TreeNode **prev) {
    if (!root) return false;
    if (findFirstDown(root->left, prev)) return true;

    if (*prev && (*prev)->val > root->val) return true;
    *prev = root;

    return findFirstDown(root->right, prev);
}
bool findLastDown(struct TreeNode *root, struct TreeNode **prev) {
    if (!root) return false;
    if (findLastDown(root->right, prev)) return true;

    if (*prev && (*prev)->val < root->val) return true;
    *prev = root;

    return findLastDown(root->left, prev);
}
void recoverTree(struct TreeNode *root) {
    if (!root) return;

    int tmp;
    struct TreeNode *first = NULL, *last = NULL;

    findFirstDown(root, &first);
    findLastDown(root, &last);

    tmp = first->val, first->val = last->val, last->val = tmp;
}
