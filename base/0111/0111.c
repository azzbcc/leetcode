//给定一个二叉树，找出其最小深度。
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
//
// 给定二叉树 [3,9,20,null,null,15,7],
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// 返回它的最小深度 2.
// Related Topics 树 深度优先搜索 广度优先搜索
// 👍 337 👎 0

int minDepth(struct TreeNode *root) {
    if (!root) return 0;

    struct TreeNode *stack[2][0x100] = { root };
    struct TreeNode **cur = stack[0], **next = stack[1], **tmp;
    for (int i = 1;; ++i) {
        for (int j = 0, k = 0; cur[j]; ++j) {
            struct TreeNode *now = cur[j];
            if (!now->left && !now->right) return i;
            if (now->left) next[k++] = now->left;
            if (now->right) next[k++] = now->right;
        }
        tmp = cur, cur = next, next = tmp;
    }
}
