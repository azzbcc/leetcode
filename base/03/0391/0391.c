// 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。
// 这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
//
// 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
//
//
// 示例 1：
//
//
// 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
// 输出：true
// 解释：5 个矩形一起可以精确地覆盖一个矩形区域。
//
//
// 示例 2：
//
//
// 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
// 输出：false
// 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
//
// 示例 3：
//
//
// 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
// 输出：false
// 解释：图形顶端留有空缺，无法覆盖成一个矩形。
//
// 示例 4：
//
//
// 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
// 输出：false
// 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
//
//
//
// 提示：
//
//
// 1 <= rectangles.length <= 2 * 10⁴
// rectangles[i].length == 4
// -10⁵ <= xi, yi, ai, bi <= 10⁵
//
// Related Topics 数组 扫描线 👍 153 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} node_t, *hash_t;
#define MAXN    20001
#define T(x, y) (x * MAXN + y)
void hash_record(hash_t *t, int key, node_t *node) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = node, cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
bool hash_del(hash_t *t, int key) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur || cur->count != 1) return false;
    HASH_DEL(*t, cur);
    return true;
}
bool isRectangleCover(int **rectangles, int size, int *colSize) {
    bool ans = false;
    node_t nodes[size * 4];
    hash_t cur, next, hash = NULL;
    int area = 0, minx = INT32_MAX, miny = INT32_MAX, maxx = INT32_MIN, maxy = INT32_MIN;

    for (int i = 0; i < size; ++i) {
        int x1 = rectangles[i][0], y1 = rectangles[i][1], x2 = rectangles[i][2], y2 = rectangles[i][3];

        area += (x2 - x1) * (y2 - y1);
        minx = fmin(minx, x1), miny = fmin(miny, y1);
        maxx = fmax(maxx, x2), maxy = fmax(maxy, y2);

        hash_record(&hash, T(x1, y1), &nodes[4 * i + 0]);
        hash_record(&hash, T(x1, y2), &nodes[4 * i + 1]);
        hash_record(&hash, T(x2, y1), &nodes[4 * i + 2]);
        hash_record(&hash, T(x2, y2), &nodes[4 * i + 3]);
    }
    if (area != (maxx - minx) * (maxy - miny)) goto end;

    if (!hash_del(&hash, T(minx, miny))) goto end;
    if (!hash_del(&hash, T(minx, maxy))) goto end;
    if (!hash_del(&hash, T(maxx, miny))) goto end;
    if (!hash_del(&hash, T(maxx, maxy))) goto end;

    HASH_ITER(hh, hash, cur, next) {
        if (cur->count != 2 && cur->count != 4) goto end;
    }
    ans = true;
end:
    HASH_CLEAR(hh, hash);
    return ans;
}
