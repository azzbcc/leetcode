// n 座城市，从 0 到 n-1 编号，其间共有 n-1
// 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输
// 部决定重新规划路线，以改变交通拥堵的状况。
//
// 路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。
//
// 今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。
//
// 请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。
//
// 题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。
//
//
//
// 示例 1：
//
//
//
// 输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// 输出：3
// 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
//
// 示例 2：
//
//
//
// 输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// 输出：2
// 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
//
// 示例 3：
//
// 输入：n = 3, connections = [[1,0],[2,0]]
// 输出：0
//
//
//
//
// 提示：
//
//
// 2 <= n <= 5 * 10^4
// connections.length == n-1
// connections[i].length == 2
// 0 <= connections[i][0], connections[i][1] <= n-1
// connections[i][0] != connections[i][1]
//
// Related Topics 树 深度优先搜索
// 👍 31 👎 0

typedef struct node {
    int val[2];
    struct node *prev[2];
    struct node *next[2];
} * node_t;
int dfs(node_t map[], int now) {
    node_t cur = map[now];
    int sum    = 0;

    while (cur) {
        // remove current
        cur->prev[0] ? (cur->prev[0]->next[cur->val[0] != cur->prev[0]->val[0]] = cur->next[0]) : (map[cur->val[0]] = cur->next[0]);
        cur->prev[1] ? (cur->prev[1]->next[cur->val[1] != cur->prev[1]->val[0]] = cur->next[1]) : (map[cur->val[1]] = cur->next[1]);
        if (cur->next[0]) cur->next[0]->prev[cur->val[0] != cur->next[0]->val[0]] = cur->prev[0];
        if (cur->next[1]) cur->next[1]->prev[cur->val[1] != cur->next[1]->val[0]] = cur->prev[1];

        sum += dfs(map, cur->val[cur->val[0] == now]) + (cur->val[0] == now);
        cur = cur->next[cur->val[0] != now];
    }
    return sum;
}
int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    struct node *map[n], nodes[connectionsSize];
    for (int i = 0; i < n; map[i++] = NULL) {}
    for (int i = 0; i < connectionsSize; ++i) {
        nodes[i].prev[0] = nodes[i].prev[1] = NULL;
        memcpy(nodes[i].val, connections[i], 2 * sizeof(int));

        if (map[nodes[i].val[0]]) map[nodes[i].val[0]]->prev[nodes[i].val[0] != map[nodes[i].val[0]]->val[0]] = &nodes[i];
        if (map[nodes[i].val[1]]) map[nodes[i].val[1]]->prev[nodes[i].val[1] != map[nodes[i].val[1]]->val[0]] = &nodes[i];
        nodes[i].next[0] = map[nodes[i].val[0]], nodes[i].next[1] = map[nodes[i].val[1]];
        map[nodes[i].val[0]] = map[nodes[i].val[1]] = &nodes[i];
    }

    int ans = dfs(map, 0);

    return ans;
}
