// 给定一个二叉树，返回它的 前序 遍历。
//
// 示例:
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
// 输出: [1,2,3]
//
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树
// 👍 413 👎 0

#define MAXN 0x1000
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int help[MAXN], len = 0, *ans = NULL;

    while (root) {
        if (root->left) {
            struct TreeNode *morris_prev = root->left;
            while (morris_prev->right && morris_prev->right != root) {
                morris_prev = morris_prev->right;
            }
            if (morris_prev->right) {
                morris_prev->right = NULL;
            } else {
                help[len++]        = root->val;
                morris_prev->right = root, root = root->left;
                continue;
            }
        } else {
            help[len++] = root->val;
        }
        root = root->right;
    }

    *returnSize = len, ans = calloc(len, sizeof(int));
    memcpy(ans, help, len * sizeof(int));

    return ans;
}
