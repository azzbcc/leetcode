// 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
//
// 如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
//
// 我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
//
// 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
//
//
//
// 示例 1：
//
//
//
// 输入：root = [1,2,3,4], x = 4, y = 3
// 输出：false
//
//
// 示例 2：
//
//
//
// 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
// 输出：true
//
//
// 示例 3：
//
//
//
//
// 输入：root = [1,2,3,null,4], x = 2, y = 3
// 输出：false
//
//
//
// 提示：
//
//
// 二叉树的节点数介于 2 到 100 之间。
// 每个节点的值都是唯一的、范围为 1 到 100 的整数。
//
//
//
// Related Topics 树 广度优先搜索
// 👍 154 👎 0

#if 0
typedef struct {
    int depth;
    struct TreeNode *parent;
} node_t;
bool find(struct TreeNode *root, int key, int depth, struct TreeNode *parent, node_t *node) {
    if (!root) return false;
    if (root->val == key) {
        node->depth = depth, node->parent = parent;
        return true;
    }
    if (find(root->left, key, depth + 1, root, node)) return true;
    if (find(root->right, key, depth + 1, root, node)) return true;
    return false;
}
bool isCousins(struct TreeNode *root, int x, int y) {
    node_t px[1] = { { 0 } }, py[1] = { { 0 } };

    if (x == y) return false;
    find(root, x, 0, NULL, px);
    find(root, y, 0, NULL, py);
    return px->depth == py->depth && px->parent != py->parent;
}
#else
#define MAX 100
typedef struct {
    int depth;
    struct TreeNode *parent, *node;
} node_t;
bool isCousins(struct TreeNode *root, int x, int y) {
    node_t nodes[MAX + 1] = { 0 }, *queue[MAX] = { &nodes[root->val] };

    if (x == y) return false;
    queue[0]->node = root;
    for (int i = 0, len = 1; i < len; ++i) {
        struct TreeNode *l = queue[i]->node->left, *r = queue[i]->node->right;
        if (l) nodes[l->val] = (node_t) { queue[i]->depth + 1, queue[i]->node, l };
        if (r) nodes[r->val] = (node_t) { queue[i]->depth + 1, queue[i]->node, r };
        if (l) queue[len++] = &nodes[l->val];
        if (r) queue[len++] = &nodes[r->val];
    }
    return nodes[x].node && nodes[y].node && nodes[x].depth == nodes[y].depth && nodes[x].parent != nodes[y].parent;
}
#endif