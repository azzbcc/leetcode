// Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。
// 树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。
//
// Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：
//
//
// 选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
// Bob 猜测树中 u 是 v 的 父节点 。
//
//
// Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。
//
// Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。
//
// 给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。
//
//
//
// 示例 1：
//
//
//
//
// 输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
// 输出：3
// 解释：
// 根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
// 根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
// 根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
// 根为节点 3 ，正确的猜测为 [1,0], [2,4]
// 根为节点 4 ，正确的猜测为 [1,3], [1,0]
// 节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
//
//
// 示例 2：
//
//
//
//
// 输入：edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
// 输出：5
// 解释：
// 根为节点 0 ，正确的猜测为 [3,4]
// 根为节点 1 ，正确的猜测为 [1,0], [3,4]
// 根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
// 根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
// 根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
// 任何节点为根，都至少有 1 个正确的猜测。
//
//
//
//
// 提示：
//
//
// edges.length == n - 1
// 2 <= n <= 10⁵
// 1 <= guesses.length <= 10⁵
// 0 <= ai, bi, uj, vj <= n - 1
// ai != bi
// uj != vj
// edges 表示一棵有效的树。
// guesses[j] 是树中的一条边。
// guesses 是唯一的。
// 0 <= k <= guesses.length
//
//
// Related Topics 树 深度优先搜索 哈希表 动态规划 👍 65 👎 0

typedef struct {
    int from, to;
} data_t;
typedef struct {
    int count;
    data_t data;
    UT_hash_handle hh;
} hash_t;
int hash_count(hash_t *t, data_t data) {
    hash_t *find;
    HASH_FIND(hh, t, &data, sizeof(data_t), find);
    return find ? find->count : 0;
}
void hash_record(hash_t **t, hash_t *node) {
    hash_t *find;
    HASH_FIND(hh, *t, &node->data, sizeof(data_t), find);
    if (!find) {
        find = node;
        HASH_ADD(hh, *t, data, sizeof(data_t), find);
    }
    find->count += 1;
}
typedef struct edge_node {
    int to;
    struct edge_node *next;
} edge_t;
int dfs(edge_t *map[], hash_t *hash, data_t edge, int res[], int now) {
    int ans = 0;

    res[edge.to] = now;
    for (edge_t *e = map[edge.to]; e; e = e->next) {
        if (e->to == edge.from) continue;
        int a = hash_count(hash, (data_t) { edge.to, e->to });
        int b = hash_count(hash, (data_t) { e->to, edge.to });
        ans += a + dfs(map, hash, (data_t) { edge.to, e->to }, res, now - a + b);
    }
    return ans;
}
int rootCount(int **edges, int eSize, int *eColSize, int **guesses, int gSize, int *gColSize, int k) {
    int res[eSize + 1], cnt, ans = 0;
    hash_t nodes[gSize], *hash = NULL;
    edge_t *map[eSize + 1], lines[eSize * 2];

    memset(res, 0, sizeof(res));
    memset(map, 0, sizeof(map));
    for (int i = 0; i < eSize; ++i) {
        int a = edges[i][0], b = edges[i][1];
        lines[2 * i + 0] = (edge_t) { b, map[a] };
        lines[2 * i + 1] = (edge_t) { a, map[b] };
        map[a] = &lines[2 * i + 0], map[b] = &lines[2 * i + 1];
    }
    for (int i = 0; i < gSize; ++i) {
        nodes[i] = (hash_t) { .data = { guesses[i][0], guesses[i][1] } };
        hash_record(&hash, &nodes[i]);
    }

    cnt = dfs(map, hash, (data_t) { -1, 0 }, res, 0);
    for (int i = 0; i <= eSize; ans += (res[i++] + cnt) >= k) {}
    HASH_CLEAR(hh, hash);
    return ans;
}
