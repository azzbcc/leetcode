// 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
//
//
//
// 示例 1：
//
//
// 输入：points = [[1,1],[2,2],[3,3]]
// 输出：3
//
//
// 示例 2：
//
//
// 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// 输出：4
//
//
//
//
// 提示：
//
//
// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// points 中的所有点 互不相同
//
// Related Topics 几何 哈希表 数学
// 👍 287 👎 0

#define MAXN 300
typedef struct {
    double key;
    int len;
    int data[MAXN];
    UT_hash_handle hh;
} * hash_t;
static int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    if (pa[0] == pb[0]) return pa[1] - pb[1];
    return pa[0] - pb[0];
}
static double cal(int pa[], int pb[]) {
    return 1. * (pa[1] - pb[1]) / (pa[0] - pb[0]);
}
static hash_t hash_find(hash_t t, double val) {
    hash_t cur;
    HASH_FIND(hh, t, &val, sizeof(double), cur);
    return cur;
}
int maxPoints(int **points, int size, int *colSize) {
    double k;
    int ans = 1;
    hash_t hash[size], cur, next;

    memset(hash, 0, sizeof(hash));
    qsort(points, size, sizeof(int *), cmp);
    for (int i = 1; i < size; ++i) {
        bool visit[MAXN] = { false };
        for (int j = i - 1; j >= 0; --j) {
            if (visit[j]) continue;
            cur = hash_find(hash[j], k = cal(points[j], points[i]));
            if (cur) {
                HASH_DEL(hash[j], cur);
            } else {
                cur = malloc(sizeof(*cur)), cur->key = k, cur->len = 0;
                cur->data[cur->len++] = j;
            }
            for (int l = 0; l < cur->len; visit[cur->data[l++]] = true) {}
            cur->data[cur->len++] = i;
            HASH_ADD(hh, hash[i], key, sizeof(double), cur);
        }
    }
    for (int i = 0; i < size; ++i) {
        HASH_ITER(hh, hash[i], cur, next) {
            if (ans < cur->len) ans = cur->len;
            HASH_DEL(hash[i], cur);
            free(cur);
        }
    }
    return ans;
}