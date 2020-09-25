// 根据一棵树的中序遍历与后序遍历构造二叉树。
//
// 注意:
// 你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
//
// 返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
// Related Topics 树 深度优先搜索 数组
// 👍 327 👎 0

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (!inorderSize) return NULL;

    int pos;
    for (pos = 0; pos < inorderSize; ++pos) {
        if (inorder[pos] == postorder[inorderSize - 1]) break;
    }
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));

    root->val   = inorder[pos];
    root->left  = buildTree(inorder, pos, postorder, pos);
    root->right = buildTree(inorder + pos + 1, inorderSize - pos - 1, postorder + pos, inorderSize - pos - 1);
    return root;
}
