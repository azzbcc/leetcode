// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//
//
//
// 示例 1：
//
//
// 输入：root = [1,null,2,3]
// 输出：[3,2,1]
//
//
// 示例 2：
//
//
// 输入：root = []
// 输出：[]
//
//
// 示例 3：
//
//
// 输入：root = [1]
// 输出：[1]
//
//
//
//
// 提示：
//
//
// 树中节点的数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
//
//
//
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1145 👎 0

#define MAX 100
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int help[MAX], len = 0;

    for (struct TreeNode *morris; root;) {
        if (root->right) {
            for (morris = root->right; morris->left && morris->left != root; morris = morris->left) {}
            if (morris->left) {
                morris->left = NULL;
            } else {
                help[len++] = root->val, morris->left = root, root = root->right;
                continue;
            }
        } else {
            help[len++] = root->val;
        }
        root = root->left;
    }
    for (int l = 0, r = len - 1, tmp; l < r; ++l, --r) {
        tmp = help[l], help[l] = help[r], help[r] = tmp;
    }

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}