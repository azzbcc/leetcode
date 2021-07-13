// 城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的天际线
// 。
//
// 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：
//
//
//
// lefti 是第 i 座建筑物左边缘的 x 坐标。
// righti 是第 i 座建筑物右边缘的 x 坐标。
// heighti 是第 i 座建筑物的高度。
//
//
// 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序
// 。关键点是水平线段的左端点。 列表中最后一个点是最右侧建筑物的终点，y 坐标始终为
// 0，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
//
// 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...]
// 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
//
//
//
// 示例 1：
//
//
// 输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// 输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// 解释：
// 图 A 显示输入的所有建筑物的位置和高度，
// 图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
//
// 示例 2：
//
//
// 输入：buildings = [[0,2,3],[2,5,3]]
// 输出：[[0,3],[5,0]]
//
//
//
//
// 提示：
//
//
// 1 <= buildings.length <= 104
// 0 <= lefti < righti <= 231 - 1
// 1 <= heighti <= 231 - 1
// buildings 按 lefti 非递减排序
//
// Related Topics 树状数组 线段树 数组 分治 有序集合 扫描线 堆（优先队列）
// 👍 465 👎 0

typedef struct {
    int x, y;
} point_t;
typedef struct {
    int key, count;
    UT_hash_handle hh;
} hash_t;
typedef struct {
    int size;
    hash_t *del;
    int data[];
} heap_t;
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
heap_t *heap_init(int size) {
    heap_t *ans = malloc(sizeof(heap_t) + size * sizeof(int));
    ans->size = 0, ans->del = NULL;
    return ans;
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos] < heap->data[new_pos + 1]) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos] < heap->data[new_pos]) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, int val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent] >= heap->data[pos]) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
void heap_pop(heap_t *heap) {
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
}
void heap_del(heap_t *heap, int val) {
    hash_t *cur = NULL;
    HASH_FIND_INT(heap->del, &val, cur);
    if (!cur) {
        cur = calloc(1, sizeof(hash_t)), cur->key = val;
        HASH_ADD_INT(heap->del, key, cur);
    }
    cur->count += 1;
}
int heap_top(heap_t *heap) {
    for (hash_t *cur = NULL;; cur->count -= 1) {
        HASH_FIND_INT(heap->del, &heap->data[0], cur);
        if (!cur || !cur->count) return heap->data[0];
        heap_pop(heap);
    }
}
void heap_destroy(heap_t *heap) {
    hash_t *cur, *next;
    HASH_ITER(hh, heap->del, cur, next) {
        HASH_DEL(heap->del, cur);
        free(cur);
    }
    free(heap);
}
int cmp_point(const void *a, const void *b) {
    point_t *pa = ( point_t * )a, *pb = ( point_t * )b;
    if (pa->x == pb->x) return pa->y - pb->y;
    return pa->x - pb->x;
}
int **getSkyline(int **buildings, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    point_t points[size << 1];
    heap_t *heap = heap_init(size + 1);
    int len = 0, **ans = malloc(size * 2 * sizeof(int *));

    heap_add(heap, 0);
    for (int i = 0; i < size; ++i) {
        points[i * 2 + 0] = (point_t) { buildings[i][0], -buildings[i][2] };
        points[i * 2 + 1] = (point_t) { buildings[i][1], buildings[i][2] };
    }
    qsort(points, size << 1, sizeof(point_t), cmp_point);

    *returnColumnSizes = malloc(size * 2 * sizeof(int));
    for (int i = 0, cur = 0; i < size + size; ++i) {
        if (points[i].y > 0) {
            heap_del(heap, points[i].y);
        } else {
            heap_add(heap, -points[i].y);
        }
        if (cur != heap_top(heap)) {
            ans[len]    = malloc(((*returnColumnSizes)[len] = 2) * sizeof(int));
            ans[len][0] = points[i].x, ans[len][1] = cur = heap_top(heap), len++;
        }
    }
    heap_destroy(heap);

    *returnSize = len;
    return ans;
}