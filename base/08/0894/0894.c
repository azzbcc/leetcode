// 给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树 ，并以列表形式返回。
// 答案中每棵树的每个节点都必须符合 Node.val == 0 。
//
// 答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序 返回最终的真二叉树列表。
//
// 真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
//
//
//
// 示例 1：
//
//
// 输入：n = 7
// 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//
//
// 示例 2：
//
//
// 输入：n = 3
// 输出：[[0,0,0]]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 20
//
//
// Related Topics 树 递归 记忆化搜索 动态规划 二叉树 👍 352 👎 0

struct TreeNode *tree_node_new(struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *ans = calloc(1, sizeof(struct TreeNode));
    if (left) ans->left = tree_node_new(left->left, left->right);
    if (right) ans->right = tree_node_new(right->left, right->right);
    return ans;
}
void tree_destroy(struct TreeNode *t) {
    if (!t) return;
    tree_destroy(t->left);
    tree_destroy(t->right);
    free(t);
}
struct TreeNode **allPossibleFBT(int n, int *returnSize) {
    int len = 0;
    struct TreeNode *help[5000];

    if (n % 2 == 0) return malloc(*returnSize = 0);
    if (n == 1) {
        struct TreeNode **ans = malloc(sizeof(struct TreeNode *));
        *returnSize = 1, ans[0] = tree_node_new(NULL, NULL);
        return ans;
    }

    for (int i = 1, left, right; i < n; i += 2) {
        struct TreeNode **ltrees = allPossibleFBT(i, &left), **rtrees = allPossibleFBT(n - 1 - i, &right);
        for (int j = 0; j < left; ++j) {
            for (int k = 0; k < right; ++k) {
                help[len++] = tree_node_new(ltrees[j], rtrees[k]);
            }
        }
        for (int j = 0; j < left; tree_destroy(ltrees[j++])) {}
        for (int j = 0; j < right; tree_destroy(rtrees[j++])) {}
        free(ltrees);
        free(rtrees);
    }

    struct TreeNode **ans = malloc((*returnSize = len) * sizeof(struct TreeNode *));
    memcpy(ans, help, len * sizeof(struct TreeNode *));
    return ans;
}