// 给出二叉树的根节点 root，树上每个节点都有一个不同的值。
//
// 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
//
// 返回森林中的每棵树。你可以按任意顺序组织答案。
//
//
//
// 示例：
//
//
//
// 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
// 输出：[[1,2,null,4],[6],[7]]
//
//
//
//
// 提示：
//
//
// 树中的节点数最大为 1000。
// 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
// to_delete.length <= 1000
// to_delete 包含一些从 1 到 1000、各不相同的值。
//
// Related Topics 树 深度优先搜索
// 👍 100 👎 0

#define MAXN 1000

int help_count = 0;
struct TreeNode *help[MAXN / 2];
void dfs(struct TreeNode *root, bool delete[], struct TreeNode *parent) {
    if (!root) return;

    struct TreeNode *left = root->left, *right = root->right;
    if (delete[root->val]) {
        if (parent && parent->left == root) parent->left = NULL;
        if (parent && parent->right == root) parent->right = NULL;
        free(root), root = NULL;
    } else if (!parent) {
        help[help_count++] = root;
    }
    dfs(left, delete, root);
    dfs(right, delete, root);
}
struct TreeNode **delNodes(struct TreeNode *root, int *to_delete, int size, int *returnSize) {
    bool delete[MAXN + 1] = { false };
    for (int i = 0; i < size; delete[to_delete[i++]] = true) {}

    help_count = 0;
    dfs(root, delete, NULL);

    struct TreeNode **ans = malloc((*returnSize = help_count) * sizeof(struct TreeNode *));
    memcpy(ans, help, help_count * sizeof(struct TreeNode *));

    return ans;
}
