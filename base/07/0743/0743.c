// 有 n 个网络节点，标记为 1 到 n。
//
// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
// wi 是一个信号从源节点传递到目标节点的时间。
//
// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// 输出：2
//
//
// 示例 2：
//
//
// 输入：times = [[1,2,1]], n = 2, k = 1
// 输出：1
//
//
// 示例 3：
//
//
// 输入：times = [[1,2,1]], n = 2, k = 2
// 输出：-1
//
//
//
//
// 提示：
//
//
// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// 所有 (ui, vi) 对都 互不相同（即，不含重复边）
//
// Related Topics 深度优先搜索 广度优先搜索 图 最短路 堆（优先队列）
// 👍 371 👎 0

#define MAXN 100
#define MAXM 6000

typedef struct {
    int from, to, weight;
} node_t;
typedef struct {
    int size;
    node_t data[MAXM + MAXN];
} heap_t;
int idx, h[MAXN + 1], e[MAXM], ne[MAXM], w[MAXM];
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
int networkDelayTime(int **times, int size, int *colSize, int n, int k) {
    int dp[n + 1], ans = 0;
    heap_t heap[1] = { { 0 } };

    memset(dp, -1, sizeof(dp));
    idx = 0, memset(h, -1, (n + 1) * sizeof(int));
    for (int i = 0; i < size; ++i) {
        edge_record(times[i][0], times[i][1], times[i][2]);
    }

    dp[k] = 0;
    for (int i = h[k]; i >= 0; i = ne[i]) {
        heap_add(heap, (node_t) { k, e[i], w[i] });
    }
    for (node_t cur; heap->size;) {
        cur = heap_pop(heap);
        if (dp[cur.to] != -1 && dp[cur.from] + cur.weight >= dp[cur.to]) continue;
        for (int i = h[cur.to]; i >= 0; i = ne[i]) {
            heap_add(heap, (node_t) { cur.to, e[i], w[i] });
        }
        dp[cur.to] = dp[cur.from] + cur.weight;
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) return -1;
        if (ans < dp[i]) ans = dp[i];
    }
    return ans;
}
