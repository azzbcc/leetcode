// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
// （即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//
//
// 示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[20,9],[15,7]]
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
// -100 <= Node.val <= 100
//
//
// Related Topics 树 广度优先搜索 二叉树 👍 848 👎 0

#define MAX 2000
typedef struct {
    struct TreeNode *node;
    int depth;
} node_t;
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    node_t queue[MAX] = { { root } };
    int **ans, len = 0, help_col[MAX] = { 0 }, *help[MAX] = { NULL };

    for (int l = 0, r = 1, last = 0; root && last < r; ++len, last = l) {
        help[len] = malloc((help_col[len] = r - last) * sizeof(int));
        for (int d = queue[l].depth; l < r && queue[l].depth == d; ++l) {
            help[len][len % 2 ? (help_col[len] - 1 - l + last) : (l - last)] = queue[l].node->val;
            if (queue[l].node->left) queue[r++] = (node_t) { queue[l].node->left, d + 1 };
            if (queue[l].node->right) queue[r++] = (node_t) { queue[l].node->right, d + 1 };
        }
    }

    *returnSize = len;
    ans = malloc(len * sizeof(int *)), *returnColumnSizes = malloc(len * sizeof(int));
    memcpy(ans, help, len * sizeof(int *));
    memcpy(*returnColumnSizes, help_col, len * sizeof(int));
    return ans;
}