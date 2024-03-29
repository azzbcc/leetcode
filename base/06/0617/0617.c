// 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
//
// 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
// 的节点将直接作为新二叉树的节点。
//
// 示例 1:
//
//
// 输入:
// Tree 1                     Tree 2
//          1                         2
//         / \                       / \
//        3   2                     1   3
//       /                           \   \
//      5                             4   7
// 输出:
// 合并后的树:
//       3
//      / \
//     4   5
//    / \   \
//   5   4   7
//
//
// 注意: 合并必须从两个树的根节点开始。
// Related Topics 树
// 👍 501 👎 0

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2) {
    if (!t1 && !t2) return NULL;
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));

    root->val   = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
    root->left  = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    root->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);

    return root;
}
