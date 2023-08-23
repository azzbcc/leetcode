// 给你一个无向图，无向图由整数 n ，表示图中节点的数目，和 edges 组成，
// 其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。
// 同时给你一个代表查询的整数数组 queries 。
//
// 第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：
//
//
// a < b
// cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
//
//
// 请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答案。
//
// 请注意，图中可能会有 重复边 。
//
//
//
// 示例 1：
//
//
// 输入：n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
// 输出：[6,5]
// 解释：每个点对中，与至少一个点相连的边的数目如上图所示。
// answers[0] = 6。所有的点对(a, b)中边数和都大于2，故有6个；
// answers[1] = 5。所有的点对(a, b)中除了(3,4)边数等于3，其它点对边数和都大于3，故有5个。
//
//
// 示例 2：
//
//
// 输入：n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
// 输出：[10,10,9,8,6]
//
//
//
//
// 提示：
//
//
// 2 <= n <= 2 * 10⁴
// 1 <= edges.length <= 10⁵
// 1 <= ui, vi <= n
// ui != vi
// 1 <= queries.length <= 20
// 0 <= queries[j] < edges.length
//
//
// Related Topics 图 数组 双指针 二分查找 排序 👍 131 👎 0

#define N 20000
int c[N], c_copy[N];
typedef struct {
    long key;
    int count;
    UT_hash_handle hh;
} *hash_t;
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void hash_record(hash_t *t, long key) {
    hash_t cur;
    HASH_FIND(hh, *t, &key, sizeof(long), cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD(hh, *t, key, sizeof(long), cur);
    }
    cur->count += 1;
}
int *countPairs(int n, int **edges, int size, int *colSize, int *queries, int queriesSize, int *returnSize) {
    hash_t cur, next, hash = NULL;
    int *ans = malloc((*returnSize = queriesSize) * sizeof(int));

    memset(c, 0, n * sizeof(int));
    for (int i = 0; i < size; ++i) {
        int a = edges[i][0] - 1, b = edges[i][1] - 1;
        for (int tmp = a; tmp > b; a = b, b = tmp) {}
        c[a]++, c[b]++;
        hash_record(&hash, a * N + b);
    }
    memcpy(c_copy, c, n * sizeof(int));
    qsort(c_copy, n, sizeof(int), cmp);
    for (int i = 0; i < queriesSize; ++i) {
        int count = 0;
        for (int l = 0, r = n - 1; l < n; ++l) {
            for (; r >= 0 && c_copy[l] + c_copy[r] > queries[i]; r--) {}
            count += n - 1 - r;
        }
        for (int j = 0; j < n; ++j) {
            if (c[j] + c[j] > queries[i]) count--;
        }
        count /= 2;
        HASH_ITER(hh, hash, cur, next) {
            int cc = c[cur->key / N] + c[cur->key % N];
            if (cc > queries[i] && cc - cur->count <= queries[i]) count--;
        }
        ans[i] = count;
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}