// 在一个有向图中，节点分别标记为 0, 1, ..., n-1。图中每条边为红色或者蓝色，且存在自环或平行边。
//
// red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i
// 到节点 j 的蓝色有向边。
//
// 返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X
// 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。
//
//
//
// 示例 1：
//
//
// 输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
// 输出：[0,1,-1]
//
//
// 示例 2：
//
//
// 输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
// 输出：[0,1,-1]
//
//
// 示例 3：
//
//
// 输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
// 输出：[0,-1,-1]
//
//
// 示例 4：
//
//
// 输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
// 输出：[0,1,2]
//
//
// 示例 5：
//
//
// 输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
// 输出：[0,1,1]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 100
// red_edges.length <= 400
// blue_edges.length <= 400
// red_edges[i].length == blue_edges[i].length == 2
// 0 <= red_edges[i][j], blue_edges[i][j] < n
//
//
// Related Topics 广度优先搜索 图 👍 184 👎 0

typedef struct __tag_edge_node edge_t;
struct __tag_edge_node {
    int to;
    edge_t *next;
};
typedef struct {
    int cur, step, state;
} queue_t;
int *shortestAlternatingPaths(int n, int **redEdges, int redEdgesSize, int *redEdgesColSize, int **blueEdges,
                              int blueEdgesSize, int *blueEdgesColSize, int *returnSize) {
    bool visit[2][n];
    queue_t queue[n * n + 1];
    int *ans = malloc((*returnSize = n) * sizeof(int));
    edge_t *nodes[2][n], lines[redEdgesSize + blueEdgesSize + 1];

    memset(nodes, 0, sizeof(nodes));
    memset(ans, -1, n * sizeof(int));
    memset(visit, false, sizeof(visit));
    queue[0] = (queue_t) { 0, 0, 0 }, queue[1] = (queue_t) { 0, 0, 1 };

    for (int i = 0; i < redEdgesSize; ++i) {
        int from = redEdges[i][0], to = redEdges[i][1];
        lines[i]       = (edge_t) { to, nodes[0][from] };
        nodes[0][from] = &lines[i];
    }
    for (int i = 0; i < blueEdgesSize; ++i) {
        int from = blueEdges[i][0], to = blueEdges[i][1];
        lines[redEdgesSize + i] = (edge_t) { to, nodes[1][from] };
        nodes[1][from]          = &lines[redEdgesSize + i];
    }

    for (int front = 0, rear = 2; front < rear; ++front) {
        queue_t *cur = &queue[front];

        if (ans[cur->cur] == -1 || ans[cur->cur] > cur->step) ans[cur->cur] = cur->step;
        for (edge_t *e = nodes[cur->state][cur->cur]; e; e = e->next) {
            if (visit[cur->state][e->to]) continue;
            visit[cur->state][e->to] = true;
            queue[rear++]            = (queue_t) { e->to, cur->step + 1, 1 - cur->state };
        }
    }

    return ans;
}