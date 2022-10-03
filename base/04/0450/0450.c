// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
// 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
// 一般来说，删除节点可分为两个步骤：
//
//
// 首先找到需要删除的节点；
// 如果找到了，删除它。
//
//
//
//
// 示例 1:
//
//
//
//
// 输入：root = [5,3,6,2,4,null,7], key = 3
// 输出：[5,4,6,2,null,null,7]
// 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
// 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
// 另一个正确答案是 [5,2,6,null,4,null,7]。
//
//
//
//
// 示例 2:
//
//
// 输入: root = [5,3,6,2,4,null,7], key = 0
// 输出: [5,3,6,2,4,null,7]
// 解释: 二叉树不包含值为 0 的节点
//
//
// 示例 3:
//
//
// 输入: root = [], key = 0
// 输出: []
//
//
//
// 提示:
//
//
// 节点数的范围 [0, 10⁴].
// -10⁵ <= Node.val <= 10⁵
// 节点值唯一
// root 是合法的二叉搜索树
// -10⁵ <= key <= 10⁵
//
//
//
//
// 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
// Related Topics 树 二叉搜索树 二叉树 👍 801 👎 0

struct TreeNode *deleteCurrent(struct TreeNode *root) {
    if (!root) return root;
    if (!root->left || !root->right) {
        struct TreeNode *left = root->left, *right = root->right;
        free(root);
        return left ? left : right;
    }

    struct TreeNode *next = root->right, *parent = root;
    for (; next->left; parent = next, next = next->left) {}
    if (parent == root) {
        parent->right = next->right;
    } else {
        parent->left = next->right;
    }
    root->val = next->val;
    free(next);
    return root;
}
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (!root) return root;
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        root = deleteCurrent(root);
    }
    return root;
}
