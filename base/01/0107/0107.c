// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
// （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//
//
// 示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[15,7],[9,20],[3]]
//
//
// 示例 2：
//
//
// 输入：root = [1]
// 输出：[[1]]
//
//
// 示例 3：
//
//
// 输入：root = []
// 输出：[]
//
//
//
//
// 提示：
//
//
// 树中节点数目在范围 [0, 2000] 内
// -1000 <= Node.val <= 1000
//
//
// Related Topics 树 广度优先搜索 二叉树 👍 766 👎 0

#define MAX 2000
typedef struct {
    struct TreeNode *node;
    int depth;
} node_t;
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    node_t queue[MAX] = { { root } };
    int **ans, len = 0, help_col[MAX] = { 0 }, *help[MAX] = { NULL };

    for (int l = 0, r = 1, last = 0; root && last < r; ++len, last = l) {
        help[len] = malloc((help_col[len] = r - last) * sizeof(int));
        for (int d = queue[l].depth; l < r && queue[l].depth == d; ++l) {
            help[len][l - last] = queue[l].node->val;
            if (queue[l].node->left) queue[r++] = (node_t) { queue[l].node->left, d + 1 };
            if (queue[l].node->right) queue[r++] = (node_t) { queue[l].node->right, d + 1 };
        }
    }

    *returnSize = len;
    ans = malloc(len * sizeof(int *)), *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        ans[i] = help[len - i - 1], returnColumnSizes[0][i] = help_col[len - i - 1];
    }
    return ans;
}