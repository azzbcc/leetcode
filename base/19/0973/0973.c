// 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
//
// （这里，平面上两点之间的距离是欧几里德距离。）
//
// 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
//
//
//
// 示例 1：
//
// 输入：points = [[1,3],[-2,2]], K = 1
// 输出：[[-2,2]]
// 解释：
// (1, 3) 和原点之间的距离为 sqrt(10)，
// (-2, 2) 和原点之间的距离为 sqrt(8)，
// 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
// 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
//
//
// 示例 2：
//
// 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
// 输出：[[3,3],[-2,4]]
//（答案 [[-2,4],[3,3]] 也会被接受。）
//
//
//
//
// 提示：
//
//
// 1 <= K <= points.length <= 10000
// -10000 < points[i][0] < 10000
// -10000 < points[i][1] < 10000
//
// Related Topics 堆 排序 分治算法
// 👍 159 👎 0

#define DIST(point) ((point[0] * point[0]) + (point[1] * point[1]))
#define HEAP_SWAP(heap, i, j)                                                                                          \
    do {                                                                                                               \
        node_t t  = heap[(i)];                                                                                         \
        heap[(i)] = heap[(j)];                                                                                         \
        heap[(j)] = t;                                                                                                 \
    } while (0)

typedef struct {
    int *data;
    int dist;
} node_t;

void adjust(node_t heap[], int size, int cur) {
    int l = 2 * cur + 1, r = 2 * cur + 2, max = cur;
    if (l < size && heap[l].dist > heap[max].dist) max = l;
    if (r < size && heap[r].dist > heap[max].dist) max = r;
    if (max != cur) {
        HEAP_SWAP(heap, cur, max);
        adjust(heap, size, max);
    }
}
int **kClosest(int **points, int pointsSize, int *colSize, int K, int *returnSize, int **returnColumnSizes) {
    node_t nodes[K];
    for (int i = 0; i < K; ++i) {
        nodes[i].data = points[i], nodes[i].dist = DIST(points[i]);
    }

    for (int i = K / 2 - 1; i >= 0; adjust(nodes, K, i--)) {}
    for (int i = K, dist; i < pointsSize; ++i) {
        dist = DIST(points[i]);
        if (dist < nodes[0].dist) {
            nodes[0].data = points[i], nodes[0].dist = dist;
            adjust(nodes, K, 0);
        }
    }

    int **ans   = malloc(K * sizeof(int *));
    *returnSize = K, *returnColumnSizes = malloc(K * sizeof(int));
    for (int i = 0; i < K; ++i) {
        (*returnColumnSizes)[i] = 2;

        ans[i] = malloc(2 * sizeof(int));
        memcpy(ans[i], nodes[i].data, 2 * sizeof(int));
    }

    return ans;
}
