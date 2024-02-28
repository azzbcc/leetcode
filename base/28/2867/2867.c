// 给你一棵 n 个节点的无向树，节点编号为 1 到 n 。
// 给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示节点 ui 和 vi 在树中有一条边。
//
// 请你返回树中的 合法路径数目 。
//
// 如果在节点 a 到节点 b 之间 恰好有一个 节点的编号是质数，那么我们称路径 (a, b) 是 合法的 。
//
// 注意：
//
//
// 路径 (a, b) 指的是一条从节点 a 开始到节点 b 结束的一个节点序列，序列中的节点 互不相同，且相邻节点之间在树上有一条边。
// 路径 (a, b) 和路径 (b, a) 视为 同一条 路径，且只计入答案 一次 。
//
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
// 输出：4
// 解释：恰好有一个质数编号的节点路径有：
// - (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
// - (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
// - (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
// - (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
// 只有 4 条合法路径。
//
//
// 示例 2：
//
//
//
//
// 输入：n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
// 输出：6
// 解释：恰好有一个质数编号的节点路径有：
// - (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
// - (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
// - (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
// - (1, 6) 因为路径 1 到 6 只包含一个质数 3 。
// - (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
// - (3, 6) 因为路径 3 到 6 只包含一个质数 3 。
// 只有 6 条合法路径。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁵
// edges.length == n - 1
// edges[i].length == 2
// 1 <= ui, vi <= n
// 输入保证 edges 形成一棵合法的树。
//
//
// Related Topics 树 深度优先搜索 数学 动态规划 数论 👍 52 👎 0

#define MAXN 100000

typedef struct edge_node {
    int to;
    struct edge_node *next;
} edge_t;
typedef struct {
    int ancestor;
    int size;
} node_t;
bool flag[MAXN + 1] = { true, true };
void euler() {
    if (flag[4]) return;
    int prime[9600], c = 0;

    for (int i = 2; i <= MAXN; i++) {
        if (!flag[i]) prime[c++] = i;
        for (int j = 0; j < c && i * prime[j] <= MAXN; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int find(node_t nodes[], int n) {
    if (nodes[n].ancestor == n) return n;
    return nodes[n].ancestor = find(nodes, nodes[n].ancestor);
}
void merge(node_t nodes[], int from, int to) {
    int a = find(nodes, from), b = find(nodes, to);
    if (nodes[a].ancestor == b) return;
    nodes[a].ancestor = b;
    nodes[b].size += nodes[a].size;
}
long long countPaths(int n, int **edges, int size, int *colSize) {
    long long ans = 0;
    node_t nodes[n + 1];
    edge_t *map[n + 1], lines[n], *e;

    euler();
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= n; nodes[i] = (node_t) { i, 1 }, ++i) {}
    for (int i = 0; i < size; ++i) {
        int a = edges[i][0], b = edges[i][1];
        if (flag[a] && flag[b]) {
            merge(nodes, a, b);
        } else if (flag[a] || flag[b]) {
            for (int tmp = a; flag[a] && tmp != b; a = b, b = tmp) {}
            lines[i] = (edge_t) { b, map[a] }, map[a] = &lines[i];
        }
    }
    for (int root = 2, c, ancestor; root <= n; ++root) {
        for (e = map[root], c = 1; e; e = e->next) {
            ancestor = find(nodes, e->to);
            ans += c * nodes[ancestor].size;
            c += nodes[ancestor].size;
        }
    }
    return ans;
}