// 给定两个整数数组 preorder 和 inorder ，
// 其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
//
//
//
// 示例 1:
//
//
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]
//
//
// 示例 2:
//
//
// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]
//
//
//
//
// 提示:
//
//
// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder 和 inorder 均 无重复 元素
// inorder 均出现在 preorder
// preorder 保证 为二叉树的前序遍历序列
// inorder 保证 为二叉树的中序遍历序列
//
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2230 👎 0

struct TreeNode *buildTree(int *preorder, int size, int *inorder, int iSize) {
    if (!size) return NULL;
    int len;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    for (len = 0, node->val = preorder[len]; len < size && inorder[len] != node->val; ++len) {}
    node->left  = buildTree(preorder + 1, len, inorder, len);
    node->right = buildTree(preorder + len + 1, size - len - 1, inorder + len + 1, size - len - 1);
    return node;
}