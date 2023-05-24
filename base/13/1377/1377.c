// 给你一棵由 n 个顶点组成的无向树，顶点编号从 1 到 n。青蛙从 顶点 1 开始起跳。规则如下：
//
//
// 在一秒内，青蛙从它所在的当前顶点跳到另一个 未访问 过的顶点（如果它们直接相连）。
// 青蛙无法跳回已经访问过的顶点。
// 如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。
// 如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
//
//
// 无向树的边用数组 edges 描述，其中 edges[i] = [ai, bi] 意味着存在一条直接连通 ai 和 bi 两个顶点的边。
//
// 返回青蛙在 t 秒后位于目标顶点 target 上的概率。与实际答案相差不超过 10⁻⁵ 的结果将被视为正确答案。
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
// 输出：0.16666666666666666
// 解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，第 1 秒 有 1/3 的概率跳到顶点 2 ，然后第 2 秒 有 1/2
// 的概率跳到顶点 4，因此青蛙 在 2 秒后位于顶点 4 的概率是 1/3 * 1/2 = 1/6 = 0.16666666666666666 。
//
//
// 示例 2：
//
//
//
//
// 输入：n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
// 输出：0.3333333333333333
// 解释：上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，有 1/3 = 0.3333333333333333 的概率能够 1 秒 后跳到顶点 7 。
//
//
//
//
//
//
// 提示：
//
//
// 1 <= n <= 100
// edges.length == n - 1
// edges[i].length == 2
// 1 <= ai, bi <= n
// 1 <= t <= 50
// 1 <= target <= n
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 图 👍 77 👎 0

typedef struct edge_node {
    int to;
    struct edge_node *next;
} edge_t;
int bfs(int n, edge_t *map[n], int t, int target) {
    struct {
        int step, base;
    } nodes[n];
    bool visit[n];
    int queue[n], front = 0, rear = 0;

    memset(nodes, 0, sizeof(nodes));
    memset(visit, false, sizeof(visit));
    visit[0] = true, nodes[0].base = 1, queue[rear++] = 0;
    for (; front < rear && nodes[queue[front]].step < t; ++front) {
        int count = 0;
        for (edge_t *e = map[queue[front]]; e; count += !visit[e->to], e = e->next) {}
        if (count) {
            for (edge_t *e = map[queue[front]]; e; e = e->next) {
                if (visit[e->to]) continue;
                visit[e->to] = true, queue[rear++] = e->to;
                nodes[e->to].step = nodes[queue[front]].step + 1;
                nodes[e->to].base = nodes[queue[front]].base * count;
            }
        } else {
            nodes[queue[front]].step = t;
        }
    }
    return nodes[target].step == t ? nodes[target].base : 0;
}
double frogPosition(int n, int **edges, int size, int *colSize, int t, int target) {
    if (!size) return target == 1;
    edge_t *graph[n], nodes[size * 2];
    memset(graph, 0, sizeof(graph));
    for (int i = 0, a, b; i < size; ++i) {
        a = edges[i][0] - 1, b = edges[i][1] - 1;
        nodes[2 * i + 0] = (edge_t) { b, graph[a] }, graph[a] = &nodes[2 * i + 0];
        nodes[2 * i + 1] = (edge_t) { a, graph[b] }, graph[b] = &nodes[2 * i + 1];
    }
    int base = bfs(n, graph, t, target - 1);
    return base ? 1. / base : 0;
}
