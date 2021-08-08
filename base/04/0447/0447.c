// 给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j
// 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
//
// 返回平面上所有回旋镖的数量。
//
//
// 示例 1：
//
//
// 输入：points = [[0,0],[1,0],[2,0]]
// 输出：2
// 解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
//
//
// 示例 2：
//
//
// 输入：points = [[1,1],[2,2],[3,3]]
// 输出：2
//
//
// 示例 3：
//
//
// 输入：points = [[1,1]]
// 输出：0
//
//
//
//
// 提示：
//
//
// n == points.length
// 1 <= n <= 500
// points[i].length == 2
// -104 <= xi, yi <= 104
// 所有点都 互不相同
//
// Related Topics 哈希表 数学
// 👍 130 👎 0

typedef struct {
    int dist, count;
    UT_hash_handle hh;
} * hash_t;
int dist(int *p, int *q) {
    return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
}
void hash_record(hash_t *t, int dist) {
    hash_t cur;
    HASH_FIND_INT(*t, &dist, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->dist = dist, cur->count = 0;
        HASH_ADD_INT(*t, dist, cur);
    }
    cur->count += 1;
}
int numberOfBoomerangs(int **points, int size, int *colSize) {
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        hash_t hash = NULL, cur, next;
        for (int j = 0; j < size; ++j) {
            if (i == j) continue;
            hash_record(&hash, dist(points[i], points[j]));
        }
        HASH_ITER(hh, hash, cur, next) {
            ans += cur->count * (cur->count - 1);
            HASH_DEL(hash, cur);
            free(cur);
        }
    }
    return ans;
}