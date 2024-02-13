// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
//
//
//
// 示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
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
// Related Topics 树 广度优先搜索 二叉树 👍 1884 👎 0

#define MAX 2000
typedef struct {
    struct TreeNode *node;
    int depth;
} node_t;
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    node_t queue[MAX] = { { root } };
    int **ans, len = 0, help_col[MAX] = { 0 }, *help[MAX] = { NULL };

    for (int l = 0, r = 1, last = 0; root && last < r; ++len, last = l) {
        for (int d = queue[l].depth; l < r && queue[l].depth == d; ++l) {
            if (queue[l].node->left) queue[r++] = (node_t) { queue[l].node->left, d + 1 };
            if (queue[l].node->right) queue[r++] = (node_t) { queue[l].node->right, d + 1 };
        }
        help[len] = malloc((help_col[len] = l - last) * sizeof(int));
        for (int i = last; i < l; help[len][i - last] = queue[i].node->val, ++i) {}
    }

    *returnSize = len;
    ans = malloc(len * sizeof(int *)), *returnColumnSizes = malloc(len * sizeof(int));
    memcpy(ans, help, len * sizeof(int *));
    memcpy(*returnColumnSizes, help_col, len * sizeof(int));
    return ans;
}
