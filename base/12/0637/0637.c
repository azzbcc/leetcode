//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
//
//
//
// 示例 1：
//
// 输入：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出：[3, 14.5, 11]
//解释：
//第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
//
//
//
//
// 提示：
//
//
// 节点值的范围在32位有符号整数范围内。
//
// Related Topics 树
// 👍 172 👎 0
#define MAXN 0x1000

int help_len, help_col[MAXN];
double help[MAXN];
void dfs(struct TreeNode *root, int depth) {
    if (help_len < depth) help_len = depth;
    if (!root) return;
    help[depth] += root->val, help_col[depth] += 1;

    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    double *ans;

    help_len = 0;
    memset(help, 0, sizeof(help));
    memset(help_col, 0, sizeof(help_col));

    dfs(root, 0);

    *returnSize = help_len, ans = calloc(help_len, sizeof(double));
    for (int i = 0; i < help_len; ++i) {
        ans[i] = help[i] / help_col[i];
    }

    return ans;
}