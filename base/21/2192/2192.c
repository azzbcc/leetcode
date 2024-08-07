// 给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。
//
// 给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。
//
// 请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。
//
// 如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。
//
//
//
// 示例 1：
//
//
//
// 输入：n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
// 输出：[[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
// 解释：
// 上图为输入所对应的图。
// - 节点 0 ，1 和 2 没有任何祖先。
// - 节点 3 有 2 个祖先 0 和 1 。
// - 节点 4 有 2 个祖先 0 和 2 。
// - 节点 5 有 3 个祖先 0 ，1 和 3 。
// - 节点 6 有 5 个祖先 0 ，1 ，2 ，3 和 4 。
// - 节点 7 有 4 个祖先 0 ，1 ，2 和 3 。
//
//
// 示例 2：
//
//
//
// 输入：n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// 输出：[[],[0],[0,1],[0,1,2],[0,1,2,3]]
// 解释：
// 上图为输入所对应的图。
// - 节点 0 没有任何祖先。
// - 节点 1 有 1 个祖先 0 。
// - 节点 2 有 2 个祖先 0 和 1 。
// - 节点 3 有 3 个祖先 0 ，1 和 2 。
// - 节点 4 有 4 个祖先 0 ，1 ，2 和 3 。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 1000
// 0 <= edges.length <= min(2000, n * (n - 1) / 2)
// edges[i].length == 2
// 0 <= fromi, toi <= n - 1
// fromi != toi
// 图中不会有重边。
// 图是 有向 且 无环 的。
//
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 54 👎 0

typedef struct __tag_edge_node edge_t;
struct __tag_edge_node {
    int to;
    edge_t *next;
};
typedef struct {
    int key;
    UT_hash_handle hh;
} *hash_t;
int cmp(hash_t a, hash_t b) {
    return a->key - b->key;
}
void hash_record(hash_t *t, int key) {
    hash_t cur;
    HASH_FIND_INT(*t, &key, cur);
    if (cur) return;
    cur = malloc(sizeof(*cur)), cur->key = key;
    HASH_ADD_INT(*t, key, cur);
}
void dfs(edge_t *map[], hash_t hash[], int now) {
    hash_t cur, next;
    if (hash[now]) return;
    for (edge_t *e = map[now]; e; e = e->next) {
        dfs(map, hash, e->to);
        HASH_ITER(hh, hash[e->to], cur, next) {
            hash_record(&hash[now], cur->key);
        }
        hash_record(&hash[now], e->to);
    }
}
int **getAncestors(int n, int **edges, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    int **ans;
    hash_t hash[n], cur, next;
    edge_t *map[n], lines[size + 1];

    memset(map, 0, sizeof(map));
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < size; ++i) {
        lines[i] = (edge_t) { edges[i][0], map[edges[i][1]] }, map[edges[i][1]] = &lines[i];
    }
    for (int i = 0; i < n; dfs(map, hash, i++)) {}

    *returnSize = n, ans = malloc(n * sizeof(int *)), *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0, j; i < n; ++i) {
        j = 0, (*returnColumnSizes)[i] = HASH_COUNT(hash[i]);
        ans[i] = malloc(HASH_COUNT(hash[i]) * sizeof(int));
        HASH_SORT(hash[i], cmp);
        HASH_ITER(hh, hash[i], cur, next) {
            ans[i][j++] = cur->key;
            HASH_DEL(hash[i], cur);
            free(cur);
        }
    }
    return ans;
}