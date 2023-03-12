// 给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，其中 edges[i] = [ui, vi] 表示城市 ui 和 vi
// 之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。
//
// 一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。
// 两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。
//
// 对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。
//
// 请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。
//
// 请注意，两个城市间距离定义为它们之间需要经过的边的数目。
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 4, edges = [[1,2],[2,3],[2,4]]
// 输出：[3,4,0]
// 解释：
// 子树 {1,2}, {2,3} 和 {2,4} 最大距离都是 1 。
// 子树 {1,2,3}, {1,2,4}, {2,3,4} 和 {1,2,3,4} 最大距离都为 2 。
// 不存在城市间最大距离为 3 的子树。
//
//
// 示例 2：
//
//
// 输入：n = 2, edges = [[1,2]]
// 输出：[1]
//
//
// 示例 3：
//
//
// 输入：n = 3, edges = [[1,2],[2,3]]
// 输出：[2,1]
//
//
//
//
// 提示：
//
//
// 2 <= n <= 15
// edges.length == n-1
// edges[i].length == 2
// 1 <= ui, vi <= n
// 题目保证 (ui, vi) 所表示的边互不相同。
//
//
// Related Topics 位运算 树 动态规划 状态压缩 枚举 👍 104 👎 0

typedef struct edge_node {
    int to;
    struct edge_node *next;
} edge_t;
int dfs(int n, int x, int y, int cur, int parent, int dist[n][n], edge_t *map[n]) {
    if (dist[cur][x] > dist[x][y] || dist[cur][y] > dist[x][y]) return 1;
    if ((cur < x && dist[cur][y] == dist[x][y]) || (cur < y && dist[cur][x] == dist[x][y])) return 1;

    int ans = 1;
    for (edge_t *e = map[cur]; e; e = e->next) {
        if (e->to == parent) continue;
        ans *= dfs(n, x, y, e->to, cur, dist, map);
    }
    return ans + (dist[cur][x] + dist[cur][y] > dist[x][y]);
}
int *countSubgraphsForEachDiameter(int n, int **edges, int size, int *colSize, int *returnSize) {
    edge_t *map[n], lines[size * 2];
    int dist[n][n], *ans = calloc(*returnSize = size, sizeof(int));

    memset(map, 0, sizeof(map));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; dist[i][i] = 0, ++i) {}
    for (int i = 0; i < size; ++i) {
        int a = edges[i][0] - 1, b = edges[i][1] - 1;
        lines[2 * i + 0] = (edge_t) { b, map[a] };
        lines[2 * i + 1] = (edge_t) { a, map[b] };
        dist[a][b] = dist[b][a] = 1, map[a] = &lines[2 * i + 0], map[b] = &lines[2 * i + 1];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dist[j][i] != 0x3f3f3f3f && dist[i][k] != 0x3f3f3f3f) {
                    dist[j][k] = fmin(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
    for (int x = 0; x < n - 1; ++x) {
        for (int y = x + 1; y < n; ++y) {
            ans[dist[x][y] - 1] += dfs(n, x, y, x, -1, dist, map);
        }
    }
    return ans;
}