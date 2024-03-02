// 现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。
//
// 给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。
// 另给你一个整数数组 restricted 表示 受限 节点。
//
// 在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。
//
// 注意，节点 0 不 会标记为受限节点。
//
//
//
// 示例 1：
// 输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
// 输出：4
// 解释：上图所示正是这棵树。
// 在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。
//
// 示例 2：
// 输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//
// 输出：3
// 解释：上图所示正是这棵树。
// 在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
//
//
//
//
// 提示：
//
//
// 2 <= n <= 10⁵
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// edges 表示一棵有效的树
// 1 <= restricted.length < n
// 1 <= restricted[i] < n
// restricted 中的所有值 互不相同
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 并查集 图 数组 哈希表 👍 53 👎 0

typedef struct edge_node {
    int to;
    struct edge_node *next;
} edge_t;
int dfs(edge_t *map[], int now, int pre, bool limit[]) {
    int ans = 1;
    if (limit[now]) return 0;
    for (edge_t *p = map[now]; p; p = p->next) {
        if (p->to == pre) continue;
        ans += dfs(map, p->to, now, limit);
    }
    return ans;
}
int reachableNodes(int n, int **edges, int eSize, int *colSize, int *restricted, int rSize) {
    bool limit[n];
    edge_t *map[n], lines[2 * eSize];

    memset(map, 0, sizeof(map));
    memset(limit, false, sizeof(limit));
    for (int i = 0; i < rSize; limit[restricted[i++]] = true) {}
    for (int i = 0; i < eSize; ++i) {
        int a = edges[i][0], b = edges[i][1];
        lines[2 * i + 0] = (edge_t) { b, map[a] };
        lines[2 * i + 1] = (edge_t) { a, map[b] };
        map[a] = &lines[2 * i + 0], map[b] = &lines[2 * i + 1];
    }
    return dfs(map, 0, -1, limit);
}
