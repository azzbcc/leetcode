// 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
//
//
//
// 示例 1：
//
//
//
//
// 输入：root1 = [2,1,4], root2 = [1,0,3]
// 输出：[0,1,1,2,3,4]
//
//
//  示例 2：
//
//
//
//
// 输入：root1 = [1,null,8], root2 = [8,1]
// 输出：[1,1,8,8]
//
//
//
//
//  提示：
//
//
//  每棵树的节点数在 [0, 5000] 范围内
//  -10⁵ <= Node.val <= 10⁵
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 排序 👍 115 👎 0

#define MAXN 5000
void dfs(struct TreeNode *t, int res[], int *len) {
    if (!t) return;
    dfs(t->left, res, len);
    res[(*len)++] = t->val;
    dfs(t->right, res, len);
}
int *getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize) {
    int data[2][MAXN], len[2] = { 0 }, pos[2] = { 0 };
    dfs(root1, data[0], &len[0]);
    dfs(root2, data[1], &len[1]);

    int *ans = malloc((*returnSize = len[0] + len[1]) * sizeof(int));
    for (int i = 0, cur; pos[0] < len[0] && pos[1] < len[1]; ++i) {
        ans[i] = fmin(data[0][pos[0]], data[1][pos[1]]);
        pos[ans[i] == data[1][pos[1]]]++;
    }
    for (int i = pos[0] + pos[1]; pos[0] < len[0]; ans[i++] = data[0][pos[0]++]) {}
    for (int i = pos[0] + pos[1]; pos[1] < len[1]; ans[i++] = data[1][pos[1]++]) {}
    return ans;
}
