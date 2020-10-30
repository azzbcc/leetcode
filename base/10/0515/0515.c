// 您需要在二叉树的每一行中找到最大的值。
//
// 示例：
//
//
// 输入:
//
//          1
//         / \
//        3   2
//       / \   \
//      5   3   9
//
// 输出: [1, 3, 9]
//
// Related Topics 树 深度优先搜索 广度优先搜索
// 👍 101 👎 0

#define MAXN 0x1000

int help[MAXN], help_len;
void dfs(struct TreeNode *root, int depth, bool visited[]) {
    if (!root) return;

    if (!visited[depth] || help[depth] < root->val) help[depth] = root->val;
    if (help_len <= depth) help_len = depth + 1;
    visited[depth] = true;

    dfs(root->left, depth + 1, visited);
    dfs(root->right, depth + 1, visited);
}
int *largestValues(struct TreeNode *root, int *returnSize) {
    int *ans           = NULL;
    bool visited[MAXN] = { false };

    help_len = 0;
    dfs(root, 0, visited);

    *returnSize = help_len, ans = calloc(help_len, sizeof(int));
    memcpy(ans, help, help_len * sizeof(int));

    return ans;
}
