// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//
//
// 示例 1：
//
//
// 输入：root = [1,null,2,3]
// 输出：[1,3,2]
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
// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
//
//
//
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 2013 👎 0

#define MAX 100
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int help[MAX], len = 0;

    for (struct TreeNode *morris; root;) {
        if (root->left) {
            for (morris = root->left; morris->right && morris->right != root; morris = morris->right) {}
            if (morris->right) {
                morris->right = NULL;
            } else {
                morris->right = root, root = root->left;
                continue;
            }
        }
        help[len++] = root->val, root = root->right;
    }

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}