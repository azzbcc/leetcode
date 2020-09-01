// 给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
//
// 输入:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// 输出: ["1->2->5", "1->3"]
//
// 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
// Related Topics 树 深度优先搜索
// 👍 314 👎 0

int help_len       = 0;
char *help[0x1000] = { NULL };

void dfs(struct TreeNode *root, char *str, int len) {
    if (!root) return;

    len += sprintf(&str[len], "%d->", root->val);
    if (!root->left && !root->right) {
        str[len - 2]   = '\0';
        help[help_len] = strdup(str);
        assert(help_len++ < 0x1000);
        return;
    }
    if (root->left) dfs(root->left, str, len);
    if (root->right) dfs(root->right, str, len);
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    char str[0x1000], **ans = NULL;

    help_len = 0;
    dfs(root, str, 0);

    *returnSize = help_len, ans = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}
