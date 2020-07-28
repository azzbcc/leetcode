//给定一个二叉树，找出其最大深度。
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例：
//给定二叉树 [3,9,20,null,null,15,7]，
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// 返回它的最大深度 3 。
// Related Topics 树 深度优先搜索
// 👍 627 👎 0
int (*maxDepth)(struct TreeNode *);
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define N 1024
int maxDepth_1(struct TreeNode *root) {
    if (!root) return 0;

    int beg = 0, end = 1;
    int queue_d[N]              = { 1 };
    struct TreeNode *queue_t[N] = { root };

    while (beg != end) {
        if (queue_t[beg]->left) {
            queue_d[end] = queue_d[beg] + 1;
            queue_t[end] = queue_t[beg]->left;
            end          = (end + 1) % N;
            assert(end != beg);
        }
        if (queue_t[beg]->right) {
            queue_d[end] = queue_d[beg] + 1;
            queue_t[end] = queue_t[beg]->right;
            end          = (end + 1) % N;
            assert(end != beg);
        }
        beg = (beg + 1) % N;
    }
    return queue_d[(beg + N - 1) % N];
}

static int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth_2(struct TreeNode *root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int (*maxDepth)(struct TreeNode *) = maxDepth_1;