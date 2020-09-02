//我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5,
// 7]，表示第一 辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。
//
// 假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1
// 表示不可能到达终点车站。
//
//
//
// 示例：
//
// 输入：
// routes = [[1, 2, 7], [3, 6, 7]]
// S = 1
// T = 6
//输出：2
//解释：
//最优策略是先乘坐第一辆公交车到达车站 7, 然后换乘第二辆公交车到车站 6。
//
//
//
//
// 提示：
//
//
// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 10^5.
// 0 <= routes[i][j] < 10 ^ 6.
//
// Related Topics 广度优先搜索
// 👍 64 👎 0
#define MAXM 500
#define MAXN 100000
typedef struct data {
    int size;
    int base[MAXM];
    struct data *next;
} * data_t;
static data_t data_add(data_t *head) {
    data_t d = calloc(1, sizeof(struct data));
    d->size = 0, d->next = *head, *head = d;
    return *head;
}
static void data_free(data_t list) {
    if (list) data_free(list->next);
    free(list);
}
typedef struct {
    int station, count;
} node_t;
static int bfs(data_t map[], int **routes, int *routesColSize, int S, int T) {
    int front = 0, rear = 1;
    node_t queue[MAXN] = { { S, 0 } };
    bool visited[MAXN] = { false }, bus_visited[MAXM] = { false };

    visited[S] = true;
    while (front < rear) {
        node_t now = queue[front++];
        if (now.station == T) return now.count;

        for (int i = 0; i < map[now.station]->size; ++i) {
            int bus = map[now.station]->base[i];
            if (bus_visited[bus]) continue;
            bus_visited[bus] = true;
            for (int j = 0; j < routesColSize[bus]; ++j) {
                int station = routes[bus][j];
                if (visited[station]) continue;
                visited[station] = true, queue[rear++] = (node_t) { station, now.count + 1 };
            }
        }
    }
    return -1;
}
int numBusesToDestination(int **routes, int routesSize, int *routesColSize, int S, int T) {
    data_t map[MAXN] = { 0 }, list = NULL;

    for (int i = 0; i < routesSize; ++i) {
        for (int j = 0; j < routesColSize[i]; ++j) {
            int station = routes[i][j];
            if (!map[station]) map[station] = data_add(&list);
            map[station]->base[map[station]->size++] = i;
        }
    }

    int ans = bfs(map, routes, routesColSize, S, T);

    data_free(list);
    return ans;
}
