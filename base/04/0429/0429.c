// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//
// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//
//
//
// 示例 1：
//
//
//
//
// 输入：root = [1,null,3,2,4,null,5,6]
// 输出：[[1],[3,2,4],[5,6]]
//
//
// 示例 2：
//
//
//
//
// 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
//
//
//
//
// 提示：
//
//
// 树的高度不会超过 1000
// 树的节点总数在 [0, 10^4] 之间
//
// Related Topics 树 广度优先搜索 👍 227 👎 0

#define MAXM 1000
#define MAXN 10000
typedef struct {
    int front, rear;
    struct Node *data[MAXN];
} queue_t;
int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    queue_t q[1] = { 0 };
    int **ans, *help[MAXM] = { NULL }, help_len = 0, help_col[MAXM] = { 0 };

    if (root) q->data[q->rear++] = root;
    for (; q->front < q->rear; ++help_len) {
        help[help_len] = malloc((help_col[help_len] = q->rear - q->front) * sizeof(int));
        for (int i = 0; i < help_col[help_len]; ++i) {
            struct Node *now  = q->data[q->front++];
            help[help_len][i] = now->val;
            for (int j = 0; j < now->numChildren; ++j) {
                q->data[q->rear++] = now->children[j];
            }
        }
    }

    ans = malloc((*returnSize = help_len) * sizeof(int *)), *returnColumnSizes = malloc(help_len * sizeof(int));
    memcpy(ans, help, help_len * sizeof(int *));
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));

    return ans;
}
