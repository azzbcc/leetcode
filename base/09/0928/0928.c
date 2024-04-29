// 给定一个由 n 个节点组成的网络，用 n x n 个邻接矩阵 graph 表示。
// 在节点网络中，只有当 graph[i][j] = 1 时，节点 i 能够直接连接到另一个节点 j。
//
// 一些节点 initial 最初被恶意软件感染。
// 只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。
// 这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
//
// 假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
//
// 我们可以从 initial 中删除一个节点，并完全移除该节点以及从该节点到任何其他节点的任何连接。
//
// 请返回移除后能够使 M(initial) 最小化的节点。如果有多个节点满足条件，返回索引 最小的节点 。
//
//
//
//
//
//
// 示例 1：
//
//
// 输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
// 输出：0
//
//
// 示例 2：
//
//
// 输入：graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
// 输出：1
//
//
// 示例 3：
//
//
// 输入：graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
// 输出：1
//
//
//
//
// 提示：
//
//
//
// n == graph.length
// n == graph[i].length
// 2 <= n <= 300
// graph[i][j] 是 0 或 1.
// graph[i][j] == graph[j][i]
// graph[i][i] == 1
// 1 <= initial.length < n
// 0 <= initial[i] <= n - 1
// initial 中每个整数都不同
//
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 数组 哈希表 👍 97 👎 0

typedef struct {
    int ancestor, count;
} node_t;
int find(node_t node[], int n) {
    if (node[n].ancestor == n) return n;
    return node[n].ancestor = find(node, node[n].ancestor);
}
void merge(node_t node[], int a, int b) {
    int ap = find(node, a), bp = find(node, b);
    if (ap == bp) return;
    node[bp].ancestor = ap, node[ap].count += node[bp].count;
}
int minMalwareSpread(int **graph, int size, int *colSize, int *initial, int iSize) {
    node_t ancestor[size];
    bool initial_flag[size];
    int visit[size][2], count[size], res = initial[0];

    memset(count, 0, sizeof(count));
    memset(visit, 0, sizeof(visit));
    memset(initial_flag, false, sizeof(initial_flag));
    for (int i = 0; i < iSize; initial_flag[initial[i++]] = true) {}
    for (int i = 0; i < size; ancestor[i] = (node_t) { i, 1 }, ++i) {}
    for (int i = 0; i < size; ++i) {
        if (initial_flag[i]) continue;
        for (int j = i + 1; j < size; ++j) {
            if (!initial_flag[j] && graph[i][j]) merge(ancestor, i, j);
        }
    }
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0, p; j < size; ++j) {
            if (initial_flag[j] || !graph[initial[i]][j]) continue;
            if (p = find(ancestor, j), visit[p][0]) {
                visit[p][0] += visit[p][1] != initial[i];
            } else {
                visit[p][visit[p][0] = 1] = initial[i];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        if (visit[i][0] == 1) count[visit[i][1]] += ancestor[i].count;
    }
    for (int i = 0; i < iSize; ++i) {
        if (count[initial[i]] > count[res] || count[initial[i]] == count[res] && initial[i] < res) res = initial[i];
    }
    return res;
}
