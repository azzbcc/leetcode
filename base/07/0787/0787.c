// 有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi
// 开始，以价格 pricei 抵达 toi。
//
// 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到
// dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。
//
//
//
// 示例 1：
//
//
// 输入:
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// 输出: 200
// 解释:
// 城市航班图如下
//
//
// 从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
//
// 示例 2：
//
//
// 输入:
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// 输出: 500
// 解释:
// 城市航班图如下
//
//
// 从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
//
//
//
// 提示：
//
//
// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 10⁴
// 航班没有重复，且不存在自环
// 0 <= src, dst, k < n
// src != dst
//
// Related Topics 深度优先搜索 广度优先搜索 图 动态规划 最短路 堆（优先队列） 👍 331 👎 0

#if 0
typedef struct edge_node {
    int from, to, weight;
    struct edge_node *next;
} edge_t;
typedef struct {
    int key, weight;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, int key, int weight) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->weight = INT32_MAX;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->weight = fmin(cur->weight, weight);
}
int findCheapestPrice(int n, int **flights, int size, int *colSize, int src, int dst, int k) {
    int now = 0, ans = -1;
    edge_t *graph[n], edges[size];
    hash_t hash[2] = { NULL }, cur, next;

    memset(graph, 0, sizeof(graph));
    for (int i = 0, current; i < size; graph[current] = &edges[i++]) {
        current = flights[i][0], edges[i] = (edge_t) { current, flights[i][1], flights[i][2], graph[current] };
    }

    hash_record(&hash[now], src, 0);
    for (int i = 0; i <= k; ++i, now = 1 - now) {
        HASH_ITER(hh, hash[now], cur, next) {
            HASH_DEL(hash[now], cur);
            for (edge_t *e = graph[cur->key]; e; e = e->next) {
                hash_record(&hash[1 - now], e->to, cur->weight + e->weight);
            }
            free(cur);
        }
        cur = hash_find(hash[1 - now], dst);
        if (cur && (ans == -1 || cur->weight < ans)) ans = cur->weight;
    }
    HASH_ITER(hh, hash[now], cur, next) {
        HASH_DEL(hash[now], cur);
        free(cur);
    }

    return ans;
}
#else
int findCheapestPrice(int n, int **flights, int size, int *colSize, int src, int dst, int k) {
    int now = 0, dp[2][n], ans = 0x3f3f3f3f;

    memset(dp[now], 0x3f, sizeof(dp[now])), dp[now][src] = 0;
    for (int i = 0; i <= k; ++i, now = 1 - now) {
        memset(dp[1 - now], 0x3f, sizeof(dp[1 - now]));
        for (int j = 0; j < size; ++j) {
            int from = flights[j][0], to = flights[j][1], weight = flights[j][2];
            dp[1 - now][to] = fmin(dp[1 - now][to], dp[now][from] + weight);
        }
        ans = fmin(ans, dp[1 - now][dst]);
    }
    return ans == 0x3f3f3f3f ? -1 : ans;
}
#endif