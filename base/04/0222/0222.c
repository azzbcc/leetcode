// 给出一个完全二叉树，求出该树的节点个数。
//
// 说明：
//
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为
// 第 h 层，则该层包含 1~ 2h 个节点。
//
// 示例:
//
// 输入:
//    1
//   / \
//  2   3
// / \  /
// 4  5 6
//
// 输出: 6
// Related Topics 树 二分查找
// 👍 329 👎 0

int minDepth(struct TreeNode *t) {
    if (!t) return 0;
    return minDepth(t->right) + 1;
}
bool check(struct TreeNode *t, int n) {
    for (int i = 30 - __builtin_clz(n); i >= 0; --i) {
        if (n & 1 << i) {
            t = t->right;
        } else {
            t = t->left;
        }
    }
    return t != NULL;
}
int countNodes(struct TreeNode *root) {
    if (!root) return 0;

    int depth = minDepth(root);
    int beg = (1 << depth) - 1, end = beg * 2;

    for (int mid; beg <= end;) {
        mid = (beg + end) / 2;
        if (check(root, mid)) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}