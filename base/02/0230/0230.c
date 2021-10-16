// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
//
//
//
// 示例 1：
//
//
// 输入：root = [3,1,4,null,2], k = 1
// 输出：1
//
//
// 示例 2：
//
//
// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3
//
//
//
//
//
//
// 提示：
//
//
// 树中的节点数为 n 。
// 1 <= k <= n <= 10⁴
// 0 <= Node.val <= 10⁴
//
//
//
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 466 👎 0

int dfs(struct TreeNode *t, int *k) {
    int ans = -1;
    if (!t) return ans;
    if (ans = dfs(t->left, k), ans != -1) return ans;
    if (!--*k) return t->val;
    return dfs(t->right, k);
}
int kthSmallest(struct TreeNode *t, int k) {
    return dfs(t, &k);
}
