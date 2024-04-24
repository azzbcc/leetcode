// 给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。
// 另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。
//
// 每分钟，如果节点满足以下全部条件，就会被感染：
//
//
// 节点此前还没有感染。
// 节点与一个已感染节点相邻。
//
//
// 返回感染整棵树需要的分钟数。
//
//
//
// 示例 1：
// 输入：root = [1,5,3,null,4,10,6,9,2], start = 3
// 输出：4
// 解释：节点按以下过程被感染：
// - 第 0 分钟：节点 3
// - 第 1 分钟：节点 1、10、6
// - 第 2 分钟：节点5
// - 第 3 分钟：节点 4
// - 第 4 分钟：节点 9 和 2
// 感染整棵树需要 4 分钟，所以返回 4 。
//
//
// 示例 2：
// 输入：root = [1], start = 1
// 输出：0
// 解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
//
//
//
//
// 提示：
//
//
// 树中节点的数目在范围 [1, 10⁵] 内
// 1 <= Node.val <= 10⁵
// 每个节点的值 互不相同
// 树中必定存在值为 start 的节点
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 79 👎 0

#define MAXN 100000 + 1
typedef struct {
    struct TreeNode *node;
    int parent, height;
} node_t;
int amountOfTime(struct TreeNode *root, int start) {
    node_t nodes[MAXN];
    int front = 0, rear = 0, cur;
    struct TreeNode *queue[MAXN], *now;

    nodes[root->val] = (node_t) { root };
    for (queue[rear++] = root; front < rear;) {
        now = queue[front++];
        if (now->left) queue[rear++] = now->left, nodes[now->left->val] = (node_t) { now->left, now->val };
        if (now->right) queue[rear++] = now->right, nodes[now->right->val] = (node_t) { now->right, now->val };
    }
    for (front = rear = 0, queue[rear++] = nodes[start].node; front < rear;) {
        now = queue[front++];
        if ((cur = nodes[now->val].parent) && cur != start && !nodes[cur].height) {
            queue[rear++]     = nodes[cur].node;
            nodes[cur].height = nodes[now->val].height + 1;
        }
        if (now->left && (cur = now->left->val) && cur != start && !nodes[cur].height) {
            queue[rear++]     = nodes[cur].node;
            nodes[cur].height = nodes[now->val].height + 1;
        }
        if (now->right && (cur = now->right->val) && cur != start && !nodes[cur].height) {
            queue[rear++]     = nodes[cur].node;
            nodes[cur].height = nodes[now->val].height + 1;
        }
    }
    return nodes[queue[rear - 1]->val].height;
}
