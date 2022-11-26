// 给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1 。你决定将图中的每条边 细分
// 为一条节点链，每条边之间的新节点数各不相同。
//
// 图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti] 表示原始图中节点 ui 和 vi 之间存在一条边，cnti
// 是将边 细分 后的新节点总数。注意，cnti == 0 表示边不可细分。
//
// 要 细分 边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti 个新节点。新节点为 x1, x2, ..., xcnti ，新边为 [ui,
// x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] 。
//
// 现在得到一个 新的细分图 ，请你计算从节点 0 出发，可以到达多少个节点？如果节点间距离是 maxMoves 或更少，则视为
// 可以到达 。
//
// 给你原始图和 maxMoves ，返回 新的细分图中从节点 0 出发 可到达的节点数 。
//
//
//
// 示例 1：
//
//
// 输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
// 输出：13
// 解释：边的细分情况如上图所示。
// 可以到达的节点已经用黄色标注出来。
//
//
// 示例 2：
//
//
// 输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
// 输出：23
//
//
// 示例 3：
//
//
// 输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
// 输出：1
// 解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
//
//
//
//
// 提示：
//
//
// 0 <= edges.length <= min(n * (n - 1) / 2, 10⁴)
// edges[i].length == 3
// 0 <= ui < vi < n
// 图中 不存在平行边
// 0 <= cnti <= 10⁴
// 0 <= maxMoves <= 10⁹
// 1 <= n <= 3000
//
//
// Related Topics 图 最短路 堆（优先队列） 👍 114 👎 0

#define MAXN 10000
#define MAXM 2 * MAXN
typedef struct {
    int now, weight;
} node_t;
typedef struct {
    int size;
    node_t data[MAXM + MAXN];
} heap_t;
int idx, h[MAXN], e[MAXM], ne[MAXM], w[MAXM];
void edge_record(int a, int b, int weight) {
    e[idx] = b, ne[idx] = h[a], w[idx] = weight, h[a] = idx++;
}
void swap(node_t *a, node_t *b) {
    node_t tmp;
    tmp = *a, *a = *b, *b = tmp;
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos].weight > heap->data[new_pos + 1].weight) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos].weight > heap->data[new_pos].weight) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, node_t val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent].weight <= heap->data[pos].weight) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
node_t heap_pop(heap_t *heap) {
    node_t ans    = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int reachableNodes(int **edges, int size, int *colSize, int maxMoves, int n) {
    bool visit[n];
    int dp[n], ans = 0;
    heap_t heap[1] = { 1 };

    memset(dp, 0x3f, sizeof(dp));
    memset(visit, false, sizeof(visit));
    dp[0] = 0, idx = 0, memset(h, -1, n * sizeof(int));
    for (int i = 0; i < size; ++i) {
        edge_record(edges[i][0], edges[i][1], edges[i][2] + 1);
        edge_record(edges[i][1], edges[i][0], edges[i][2] + 1);
    }
    for (node_t cur; heap->size;) {
        cur = heap_pop(heap);
        if (visit[cur.now]) continue;
        visit[cur.now] = true;
        for (int i = h[cur.now]; i >= 0; i = ne[i]) {
            if (visit[e[i]]) continue;
            if (dp[cur.now] + w[i] > maxMoves) continue;
            if (dp[cur.now] + w[i] >= dp[e[i]]) continue;
            heap_add(heap, (node_t) { e[i], dp[e[i]] = dp[cur.now] + w[i] });
        }
    }
    for (int i = 0; i < n; ans += dp[i++] <= maxMoves) {}
    for (int i = 0; i < size; ++i) {
        int fa = fmax(maxMoves - dp[edges[i][0]], 0);
        int fb = fmax(maxMoves - dp[edges[i][1]], 0);
        ans += fmin(fa + fb, edges[i][2]);
    }
    return ans;
}
