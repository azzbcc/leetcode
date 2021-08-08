// 给定一个二叉树，返回它的 后序 遍历。
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
// 输出: [3,2,1]
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树
// 👍 425 👎 0
#define MAXN 0x1000
struct TreeNode *reverse_tree(struct TreeNode *root) {
    struct TreeNode *prev = NULL;
    for (struct TreeNode *next = NULL; root; prev = root, root = next) {
        next = root->right, root->right = prev;
    }
    return prev;
}
int append_tree_result(struct TreeNode *root, int *res) {
    int len               = 0;
    struct TreeNode *tail = reverse_tree(root);
    for (struct TreeNode *cur = tail; cur; cur = cur->right) {
        res[len++] = cur->val;
    }
    reverse_tree(tail);
    return len;
}
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int result[MAXN], len = 0, *ans;
    for (struct TreeNode *cur = root; cur;) {
        if (cur->left) {
            struct TreeNode *morris_prev = cur->left;
            while (morris_prev->right && morris_prev->right != cur) {
                morris_prev = morris_prev->right;
            }
            if (morris_prev->right) {
                morris_prev->right = NULL;
                len += append_tree_result(cur->left, &result[len]);
            } else {
                morris_prev->right = cur, cur = cur->left;
                continue;
            }
        }
        cur = cur->right;
    }
    len += append_tree_result(root, &result[len]);

    *returnSize = len, ans = calloc(len, sizeof(int));
    memcpy(ans, result, len * sizeof(int));

    return ans;
}
