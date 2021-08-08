// 给定一个二叉树，我们在树的节点上安装摄像头。
//
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
//
// 计算监控树的所有节点所需的最小摄像头数量。
//
//
//
// 示例 1：
//
//
//
// 输入：[0,0,null,0,0]
// 输出：1
// 解释：如图所示，一台摄像头足以监控所有节点。
//
//
// 示例 2：
//
//
//
// 输入：[0,0,null,0,null,0,null,null,0]
// 输出：2
// 解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
//
//
//
// 提示：
//
//
// 给定树的节点数的范围是 [1, 1000]。
// 每个节点的值都是 0。
//
// Related Topics 树 深度优先搜索 动态规划
// 👍 146 👎 0
#define MAX 1000
typedef struct Status {
    int must_root;
    int no_root;
    int ans;
} status_t;
int min(int a, int b) {
    return a < b ? a : b;
}
status_t dfs(struct TreeNode* root) {
    if (!root) return (status_t) { .must_root = MAX };
    status_t ans, l = dfs(root->left), r = dfs(root->right);
    ans.must_root = l.no_root + r.no_root + 1;
    ans.no_root   = min(l.ans + r.ans, ans.must_root);
    ans.ans       = min(min(l.must_root + r.ans, l.ans + r.must_root), ans.must_root);
    return ans;
}

int minCameraCover(struct TreeNode* root) {
    return dfs(root).ans;
}
