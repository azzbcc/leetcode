// 给定一个二叉树，返回它的中序 遍历。
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
// 输出: [1,3,2]
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树 哈希表
// 👍 687 👎 0
#define MAXN 0x1000
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int result[MAXN], len = 0, *ans;
    while (root) {
        if (root->left) {
            struct TreeNode *morris_prev = root->left;
            while (morris_prev->right && morris_prev->right != root) {
                morris_prev = morris_prev->right;
            }

            if (morris_prev->right) {
                morris_prev->right = NULL;
            } else {
                morris_prev->right = root;
                root               = root->left;
                continue;
            }
        }
        result[len++] = root->val;
        root          = root->right;
    }

    *returnSize = len, ans = calloc(len, sizeof(int));
    memcpy(ans, result, len * sizeof(int));

    return ans;
}
