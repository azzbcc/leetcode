// 给你一棵二叉树的根节点 root 和一个正整数 k 。
//
// 树中的 层和 是指 同一层 上节点值的总和。
//
// 返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。
//
// 注意，如果两个节点与根节点的距离相同，则认为它们在同一层。
//
//
//
// 示例 1：
//
//
//
//
// 输入：root = [5,8,9,2,1,3,7,4,6], k = 2
// 输出：13
// 解释：树中每一层的层和分别是：
// - Level 1: 5
// - Level 2: 8 + 9 = 17
// - Level 3: 2 + 1 + 3 + 7 = 13
// - Level 4: 4 + 6 = 10
// 第 2 大的层和等于 13 。
//
//
// 示例 2：
//
//
//
//
// 输入：root = [1,2,null,3], k = 1
// 输出：3
// 解释：最大的层和是 3 。
//
//
//
//
// 提示：
//
//
// 树中的节点数为 n
// 2 <= n <= 10⁵
// 1 <= Node.val <= 10⁶
// 1 <= k <= n
//
//
// Related Topics 树 广度优先搜索 二叉树 排序 👍 17 👎 0

#define MAX 100000
typedef struct {
    struct TreeNode *node;
    int depth;
} node_t;
void swap(long long *a, long long *b) {
    for (long long tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(long long heap[], int size, int cur) {
    for (int next; cur < size; cur = next) {
        next = cur * 2 + 1;
        if (next + 1 < size && heap[next] >= heap[next + 1]) next += 1;
        if (next >= size || heap[next] >= heap[cur]) break;
        swap(&heap[cur], &heap[next]);
    }
}
long long kthLargestLevelSum(struct TreeNode *root, int k) {
    long long heap[k], sum, len = 0;
    node_t queue[MAX] = { { root } };
    for (int l = 0, r = 1; sum = 0, l < r; ++len) {
        for (int d = queue[l].depth; l < r && queue[l].depth == d; ++l) {
            sum += queue[l].node->val;
            if (queue[l].node->left) queue[r++] = (node_t) { queue[l].node->left, d + 1 };
            if (queue[l].node->right) queue[r++] = (node_t) { queue[l].node->right, d + 1 };
        }
        if (len < k) {
            heap[len] = sum;
            for (int i = k / 2 - 1; len + 1 == k && i >= 0; heap_adjust(heap, k, i--)) {}
        } else if (sum > heap[0]) {
            heap[0] = sum;
            heap_adjust(heap, k, 0);
        }
    }
    return len < k ? -1 : heap[0];
}