// 现有一棵由 n 个节点组成的无向树，节点按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，
// 其中edges[i] = [ui, vi, wi] 表示树中存在一条位于节点 ui 和节点 vi 之间、权重为 wi 的边。
//
// 另给你一个长度为 m 的二维整数数组 queries ，其中 queries[i] = [ai, bi]。
// 对于每条查询，请你找出使从 ai 到 bi 路径上每条边的权重相等所需的 最小操作次数。
// 在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。
//
// 注意：
//
//
// 查询之间 相互独立 的，这意味着每条新的查询时，树都会回到 初始状态。
// 从 ai 到 bi的路径是一个由 不同 节点组成的序列，
// 从节点 ai 开始，到节点 bi 结束，且序列中相邻的两个节点在树中共享一条边。
//
//
// 返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 条查询的答案。
//
//
//
// 示例 1：
//
//
// 输入：n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]],
//   queries = [[0,3],[3,6],[2,6],[0,6]]
// 输出：[0,0,1,3]
// 解释：第 1 条查询，从节点 0 到节点 3 的路径中的所有边的权重都是 1。
// 因此，答案为 0。
// 第 2 条查询，从节点 3 到节点 6 的路径中的所有边的权重都是 2。
// 因此，答案为 0。
// 第 3 条查询，将边 [2,3] 的权重变更为 2。在这次操作之后，从节点 2 到节点 6 的路径中的所有边的权重都是 2。
// 因此，答案为 1。
// 第 4 条查询，将边 [0,1]、[1,2]、[2,3] 的权重变更为 2。在这次操作之后，从节点 0 到节点 6 的路径中的所有边的权重都是 2。
// 因此，答案为 3。
// 对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。
//
//
// 示例 2：
//
//
// 输入：n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]],
//   queries = [[4,6],[0,4],[6,5],[7,4]]
// 输出：[1,2,2,3]
// 解释：第 1 条查询，将边 [1,3] 的权重变更为 6。在这次操作之后，从节点 4 到节点 6 的路径中的所有边的权重都是 6。
// 因此，答案为 1。
// 第 2 条查询，将边 [0,3]、[3,1] 的权重变更为 6。在这次操作之后，从节点 0 到节点 4 的路径中的所有边的权重都是 6。
// 因此，答案为 2。
// 第 3 条查询，将边 [1,3]、[5,2] 的权重变更为 6。在这次操作之后，从节点 6 到节点 5 的路径中的所有边的权重都是 6。
// 因此，答案为 2。
// 第 4 条查询，将边 [0,7]、[0,3]、[1,3] 的权重变更为 6。在这次操作之后，从节点 7 到节点 4 的路径中的所有边的权重都是 6。
// 因此，答案为 3。
// 对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁴
// edges.length == n - 1
// edges[i].length == 3
// 0 <= ui, vi < n
// 1 <= wi <= 26
// 生成的输入满足 edges 表示一棵有效的树
// 1 <= queries.length == m <= 2 * 10⁴
// queries[i].length == 2
// 0 <= ai, bi < n
//
//
// Related Topics 树 图 数组 强连通分量 👍 39 👎 0

#define W 26
typedef struct __tag_edge_node edge_t;
struct __tag_edge_node {
    edge_t *next;
    int to, help;
};
typedef struct {
    bool visited;
    edge_t *map, *query;
    int ancestor, count[W];
} help_t;
int find(help_t help[], int n) {
    if (help[n].ancestor == n) return n;
    return help[n].ancestor = find(help, help[n].ancestor);
}
void tarjan(help_t help[], int lca[], int cur) {
    help[cur].ancestor = cur, help[cur].visited = true;
    for (edge_t *e = help[cur].map; e; e = e->next) {
        if (help[e->to].visited) continue;

        memcpy(help[e->to].count, help[cur].count, W * sizeof(int));
        help[e->to].count[e->help] += 1;

        tarjan(help, lca, e->to);
        help[e->to].ancestor = cur;
    }
    for (edge_t *e = help[cur].query; e; e = e->next) {
        if (!help[e->to].visited) continue;
        lca[e->help] = find(help, e->to);
    }
}
int *minOperationsQueries(int n, int **edges, int size, int *colSize, int **queries, int qSize, int *qColSize,
                          int *returnSize) {
    int lca[qSize];
    help_t help[n];
    edge_t lines[size * 2 + 1], q_lines[qSize * 2 + 1];

    memset(help, 0, sizeof(help));
    for (int i = 0; i < size; ++i) {
        int a = edges[i][0], b = edges[i][1], w = edges[i][2];
        lines[2 * i + 0] = (edge_t) { help[a].map, b, w - 1 };
        lines[2 * i + 1] = (edge_t) { help[b].map, a, w - 1 };
        help[a].map = &lines[2 * i + 0], help[b].map = &lines[2 * i + 1];
    }
    for (int i = 0; i < qSize; ++i) {
        int a = queries[i][0], b = queries[i][1];
        q_lines[2 * i + 0] = (edge_t) { help[a].query, b, i };
        q_lines[2 * i + 1] = (edge_t) { help[b].query, a, i };
        help[a].query = &q_lines[2 * i + 0], help[b].query = &q_lines[2 * i + 1];
    }
    tarjan(help, lca, 0);

    int *ans = malloc((*returnSize = qSize) * sizeof(int));
    for (int i = 0; i < qSize; i++) {
        int total = 0, max = 0;
        for (int j = 0, t; j < W; j++) {
            t = help[queries[i][0]].count[j] + help[queries[i][1]].count[j] - help[lca[i]].count[j] * 2;
            total += t, max = fmax(max, t);
        }
        ans[i] = total - max;
    }
    return ans;
}
