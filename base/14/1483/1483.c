// 给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。
// 树的根节点是编号为 0 的节点。
//
// 树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。
//
// 实现 TreeAncestor 类：
//
//
// TreeAncestor（int n， int[] parent） 对树和父数组中的节点数初始化对象。
// getKthAncestor(int node, int k) 返回节点 node 的第 k 个祖先节点。如果不存在这样的祖先节点，返回 -1 。
//
//
//
//
// 示例 1：
//
//
//
//
// 输入：
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
// [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
//
// 输出：
// [null,1,0,-1]
//
// 解释：
// TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
//
// treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
// treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
// treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
//
//
//
//
// 提示：
//
//
// 1 <= k <= n <= 5 * 10⁴
// parent[0] == -1 表示编号为 0 的节点是根节点。
// 对于所有的 0 < i < n ，0 <= parent[i] < n 总成立
// 0 <= node < n
// 至多查询 5 * 10⁴ 次
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 设计 二分查找 动态规划 👍 150 👎 0

#define MAXN 16
typedef struct _tag_node_t {
    int to;
    struct _tag_node_t *neigh, *child;
} node_t;
typedef int TreeAncestor[MAXN + 1];
static void dfs(node_t tree[], int now, int res[], TreeAncestor *ancestor) {
    res[++res[0]] = now;
    for (int i = 1; i < res[0]; i <<= 1) {
        ancestor[now][++ancestor[now][0]] = res[res[0] - i];
    }
    for (node_t *p = tree[now].child; p; p = p->neigh) {
        dfs(tree, p->to, res, ancestor);
    }
    --res[0];
}
TreeAncestor *treeAncestorCreate(int n, int *parent, int size) {
    node_t tree[n];
    int root, res[n + 1];
    TreeAncestor *ancestor = malloc(n * sizeof(*ancestor));

    memset(res, 0, sizeof(res));
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < n; tree[i].to = i, ancestor[i++][0] = 0) {}
    for (int i = 0, p; i < size; ++i) {
        if (p = parent[i], p < 0) {
            root = i;
        } else {
            tree[i].neigh = tree[p].child, tree[p].child = &tree[i];
        }
    }

    dfs(tree, root, res, ancestor);
    return ancestor;
}
int treeAncestorGetKthAncestor(TreeAncestor *ancestor, int node, int k) {
    if (!k) return node;
    int step = __builtin_ctz(k);
    return step < ancestor[node][0] ? treeAncestorGetKthAncestor(ancestor, ancestor[node][step + 1], k & (k - 1)) : -1;
}
void treeAncestorFree(TreeAncestor *ancestor) {
    free(ancestor);
}
