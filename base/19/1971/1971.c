// 有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges
// 表示，其中edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条
// 边连接，并且没有顶点存在与自身相连的边。
//
// 请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
//
// 给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回true，否则返回
// false 。
//
//
//
// 示例 1：
//
//
// 输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// 输出：true
// 解释：存在由顶点 0 到顶点 2 的路径:
// - 0 → 1 → 2
// - 0 → 2
//
//
// 示例 2：
//
//
// 输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
//
// 输出：false
// 解释：不存在由顶点 0 到顶点 5 的路径.
//
//
//
//
// 提示：
//
//
// 1 <= n <= 2 * 10⁵
// 0 <= edges.length <= 2 * 10⁵
// edges[i].length == 2
// 0 <= ui, vi <= n - 1
// ui != vi
// 0 <= source, destination <= n - 1
// 不存在重复边
// 不存在指向顶点自身的边
//
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 73 👎 0

typedef struct __tag_edge_node edge_t;
struct __tag_edge_node {
    int to;
    edge_t *next;
};
bool dfs(int n, edge_t *nodes[n], int cur, int dest, bool visited[n]) {
    if (cur == dest) return true;
    if (visited[cur]) return false;
    visited[cur] = true;
    for (edge_t *p = nodes[cur]; p; p = p->next) {
        if (dfs(n, nodes, p->to, dest, visited)) return true;
    }
    return false;
}
bool validPath(int n, int **edges, int size, int *colSize, int source, int destination) {
    edge_t *nodes[n], lines[size * 2 + 1];
    memset(nodes, 0, sizeof(nodes));
    for (int i = 0; i < size; ++i) {
        int from = edges[i][0], to = edges[i][1];
        lines[2 * i + 0] = (edge_t) { to, nodes[from] };
        lines[2 * i + 1] = (edge_t) { from, nodes[to] };
        nodes[from] = &lines[2 * i + 0], nodes[to] = &lines[2 * i + 1];
    }

    bool visited[n];
    memset(visited, 0, sizeof(visited));
    return dfs(n, nodes, source, destination, visited);
}
