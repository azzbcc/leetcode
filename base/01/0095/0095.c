// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
//
//
//
// 示例：
//
// 输入：3
// 输出：
// [
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
// ]
// 解释：
// 以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
//
//
//
// 提示：
//
//
// 0 <= n <= 8
//
// Related Topics 树 动态规划
// 👍 716 👎 0
#define MAXN 0x800

struct TreeNode *tree_node_new(int val) {
    struct TreeNode *t = malloc(sizeof(struct TreeNode));
    t->val = val, t->left = t->right = NULL;
    return t;
}
struct TreeNode *tree_copy(struct TreeNode *t) {
    if (!t) return NULL;
    struct TreeNode *ans = tree_node_new(t->val);
    ans->left = tree_copy(t->left), ans->right = tree_copy(t->right);
    return ans;
}
void generate(int l, int r, int *len, struct TreeNode *res[]) {
    struct TreeNode *lres[MAXN], *rres[MAXN], *tmp;
    for (int i = l, left, right, c; i <= r; ++i) {
        left = right = 0, lres[0] = rres[0] = NULL;
        if (i > l) generate(l, i - 1, &left, lres);
        if (i < r) generate(i + 1, r, &right, rres);
        c = (left ? left : 1) * (right ? right : 1);
        for (int j = left - 1; right && j >= 0; --j) {
            lres[j * right] = lres[j];
            for (int k = 1; k < right; ++k) {
                lres[j * right + k] = tree_copy(lres[j]);
            }
        }
        for (int j = right; right && j < c; ++j) {
            rres[j] = tree_copy(rres[j % right]);
        }
        for (int j = 0; j < c; ++j) {
            tmp = res[(*len)++] = tree_node_new(i);
            if (left) tmp->left = lres[j];
            if (right) tmp->right = rres[j];
        }
    }
}
struct TreeNode **generateTrees(int n, int *returnSize) {
    struct TreeNode **ans = NULL;

    *returnSize = 0, ans = malloc(MAXN * sizeof(struct TreeNode *));
    generate(1, n, returnSize, ans);

    return ans;
}
