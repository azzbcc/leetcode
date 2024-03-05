// 你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向道路。
// 输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。
//
// 给你一个整数 n 和二维整数数组 roads ，
// 其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。
// 你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。
//
// 请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 10⁹ + 7 取余 后返回。
//
//
//
// 示例 1：
// 输入：n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// 输出：4
// 解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
// 四条花费 7 分钟的路径分别为：
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
//
//
// 示例 2：
//
// 输入：n = 2, roads = [[1,0,10]]
// 输出：1
// 解释：只有一条从路口 0 到路口 1 的路，花费 10 分钟。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 200
// n - 1 <= roads.length <= n * (n - 1) / 2
// roads[i].length == 3
// 0 <= ui, vi <= n - 1
// 1 <= timei <= 10⁹
// ui != vi
// 任意两个路口之间至多有一条路。
// 从任意路口出发，你能够到达其他任意路口。
//
//
// Related Topics 图 拓扑排序 动态规划 最短路 👍 105 👎 0

#define MAX 200
#define MOD 1000000007
typedef struct {
    union {
        int cur, count;
    };
    uint64_t time;
} node_t;
typedef struct edge_node {
    struct edge_node *next;
    int to, time;
} edge_t;
typedef struct {
    int size;
    node_t data[MAX * MAX];
} heap_t;
void swap(node_t *a, node_t *b) {
    for (node_t tmp = *a; tmp.time != b->time; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t *heap, int cur) {
    for (int next; cur < heap->size; cur = next) {
        next = cur * 2 + 1;
        if (next + 1 < heap->size && heap->data[next].time >= heap->data[next + 1].time) next += 1;
        if (next >= heap->size || heap->data[next].time >= heap->data[cur].time) break;
        swap(&heap->data[cur], &heap->data[next]);
    }
}
void heap_add(heap_t *heap, node_t val) {
    heap->data[heap->size] = val;
    for (int now = heap->size++, parent; now; now = parent) {
        parent = (now - 1) / 2;
        if (heap->data[parent].time <= heap->data[now].time) break;
        swap(&heap->data[now], &heap->data[parent]);
    }
}
node_t heap_pop(heap_t *heap) {
    node_t ans = heap->data[0];

    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int countPaths(int n, int **roads, int size, int *colSize) {
    node_t dp[n];
    heap_t heap[1] = { 0 };
    edge_t *map[n], lines[size * 2 + 1];

    memset(map, 0, sizeof(map));
    memset(dp, 0xff, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        int u = roads[i][0], v = roads[i][1], time = roads[i][2];
        lines[2 * i + 0] = (edge_t) { map[u], v, time };
        lines[2 * i + 1] = (edge_t) { map[v], u, time };
        map[u] = &lines[2 * i + 0], map[v] = &lines[2 * i + 1];
    }

    dp[0] = (node_t) { 1 }, heap_add(heap, (node_t) { 0 });
    for (; heap->size;) {
        node_t now = heap_pop(heap);
        if (now.time > dp[now.cur].time) continue;
        for (edge_t *e = map[now.cur]; e; e = e->next) {
            if (now.time + e->time < dp[e->to].time) {
                heap_add(heap, (node_t) { e->to, now.time + e->time });
                dp[e->to] = (node_t) { dp[now.cur].count, now.time + e->time };
            } else if (now.time + e->time == dp[e->to].time) {
                dp[e->to].count = (dp[e->to].count + dp[now.cur].count) % MOD;
            }
        }
    }
    return dp[n - 1].count;
}
