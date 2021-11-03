// 给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
//
//
//
// 示例 1:
//
//
//
//
// 输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// 输出: 4
// 解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
//
//
// 示例 2:
//
//
//
//
// 输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// 输出: 10
//
//
//
//
// 提示:
//
//
// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 10⁴
//
//
//
// Related Topics 广度优先搜索 数组 矩阵 堆（优先队列） 👍 441 👎 0

typedef struct {
    int x, y;
} point_t;
typedef struct {
    int height;
    point_t point[1];
} node_t;
typedef struct {
    int size;
    node_t *data;
} heap_t;
const point_t wards[] = { -1, 0, 0, -1, 1, 0, 0, 1 };
void swap(node_t *a, node_t *b) {
    node_t tmp;
    tmp = *a, *a = *b, *b = tmp;
}
void heap_add(heap_t *heap, point_t p, int height) {
    heap->data[heap->size] = (node_t) { height, { p } };
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent].height <= heap->data[pos].height) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos].height > heap->data[new_pos + 1].height) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos].height > heap->data[new_pos].height) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
node_t heap_pop(heap_t *heap) {
    node_t ans    = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int trapRainWater(int **map, int size, int *colSize) {
    if (size <= 2 || *colSize <= 2) return 0;
    int ans = 0;
    bool visit[size][*colSize];
    heap_t heap[1] = { 0, malloc(size * *colSize * sizeof(node_t)) };

    memset(visit, false, sizeof(visit));
    for (int i = 0; i < size; ++i) {
        visit[i][0] = visit[i][*colSize - 1] = true;
        heap_add(heap, (point_t) { i, 0 }, map[i][0]);
        heap_add(heap, (point_t) { i, *colSize - 1 }, map[i][*colSize - 1]);
    }
    for (int i = 1; i + 1 < *colSize; ++i) {
        visit[0][i] = visit[size - 1][i] = true;
        heap_add(heap, (point_t) { 0, i }, map[0][i]);
        heap_add(heap, (point_t) { size - 1, i }, map[size - 1][i]);
    }

    while (heap->size) {
        node_t cur[1] = { heap_pop(heap) };
        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            point_t next = (point_t) { cur->point->x + wards[i].x, cur->point->y + wards[i].y };
            if (next.x < 0 || next.x >= size || next.y < 0 || next.y >= *colSize || visit[next.x][next.y]) continue;
            if (cur->height > map[next.x][next.y]) ans += cur->height - map[next.x][next.y];
            visit[next.x][next.y] = true, heap_add(heap, next, fmax(map[next.x][next.y], cur->height));
        }
    }

    free(heap->data);
    return ans;
}
