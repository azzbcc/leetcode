// 给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
//
// 第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
//
// 返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
//
// 示例 1:
//
//
// 输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// 输出: [8,12,6,10,10,10]
// 解释:
// 如下为给定的树的示意图：
//   0
//  / \
// 1   2
//    /|\
//   3 4 5
//
// 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
//
//
// 说明: 1 <= N <= 10000
// Related Topics 树 深度优先搜索
// 👍 282 👎 0

#define MAXN 10000

int dp[MAXN], sz[MAXN];
int idx, h[MAXN + 1], e[MAXN * 2], ne[MAXN * 2];
void edge_record(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int cur, int parent) {
    dp[cur] = 0, sz[cur] = 1;
    for (int i = h[cur]; i >= 0; i = ne[i]) {
        if (e[i] == parent) continue;
        dfs(e[i], cur);
        dp[cur] += dp[e[i]] + sz[e[i]], sz[cur] += sz[e[i]];
    }
}
void dfs_ans(int cur, int parent, int ans[]) {
    ans[cur] = dp[cur];
    for (int i = h[cur], to, pf, pt, sf, st; i >= 0; i = ne[i]) {
        if (to = e[i], to == parent) continue;
        pf = dp[cur], pt = dp[to], sf = sz[cur], st = sz[to];
        dp[cur] -= dp[to] + sz[to], sz[cur] -= sz[to];
        dp[to] += dp[cur] + sz[cur], sz[to] += sz[cur];
        dfs_ans(to, cur, ans);
        dp[cur] = pf, dp[to] = pt, sz[cur] = sf, sz[to] = st;
    }
}
int *sumOfDistancesInTree(int n, int **edges, int size, int *colSize, int *returnSize) {
    int *ans = malloc((*returnSize = n) * sizeof(int));
    idx      = 0, memset(h, -1, n * sizeof(int));
    for (int i = 0; i < size; ++i) {
        edge_record(edges[i][0], edges[i][1]);
        edge_record(edges[i][1], edges[i][0]);
    }
    dfs(0, -1);
    dfs_ans(0, -1, ans);
    return ans;
}