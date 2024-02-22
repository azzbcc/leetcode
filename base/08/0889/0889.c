// 给定两个整数数组，preorder 和 postorder ，
// 其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。
//
// 如果存在多个答案，您可以返回其中 任何 一个。
//
//
//
// 示例 1：
//
//
//
//
// 输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// 输出：[1,2,3,4,5,6,7]
//
//
// 示例 2:
//
//
// 输入: preorder = [1], postorder = [1]
// 输出: [1]
//
//
//
//
// 提示：
//
//
// 1 <= preorder.length <= 30
// 1 <= preorder[i] <= preorder.length
// preorder 中所有值都 不同
// postorder.length == preorder.length
// 1 <= postorder[i] <= postorder.length
// postorder 中所有值都 不同
// 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
//
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 350 👎 0

struct TreeNode *constructFromPrePost(int *preorder, int size, int *postorder, int pSize) {
    if (!size) return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    if (node->val = preorder[0], size == 1) {
        node->left = node->right = NULL;
    } else {
        int len;
        for (len = 0; len < size && postorder[len] != preorder[1]; ++len) {}
        node->left  = constructFromPrePost(preorder + 1, len + 1, postorder, len + 1);
        node->right = constructFromPrePost(preorder + len + 2, size - len - 2, postorder + len + 1, size - len - 1);
    }
    return node;
}