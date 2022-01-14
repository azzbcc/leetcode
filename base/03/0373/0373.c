// 给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
//
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//
// 请找到和最小的 k 个数对 (u1,v1), (u2,v2) ... (uk,vk) 。
//
//
//
// 示例 1:
//
//
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//
// 示例 2:
//
//
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
// 示例 3:
//
//
// 输入: nums1 = [1,2], nums2 = [3], k = 3
// 输出: [1,3],[2,3]
// 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
//
//
//
//
// 提示:
//
//
// 1 <= nums1.length, nums2.length <= 10⁵
// -10⁹ <= nums1[i], nums2[i] <= 10⁹
// nums1 和 nums2 均为升序排列
// 1 <= k <= 1000
//
// Related Topics 数组 堆（优先队列） 👍 335 👎 0

typedef struct {
    int *x, *y;
} data_t;
typedef struct {
    int size;
    data_t data[];
} heap_t;
void swap(data_t *a, data_t *b) {
    for (data_t tmp = *a; tmp.x != b->x || tmp.y != b->y; *a = *b, *b = tmp) {}
}
int comp(data_t *a, data_t *b) {
    long pa = *a->x + *a->y, pb = *b->x + *b->y;
    return pa >= pb ? pa > pb : -1;
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && comp(&heap->data[new_pos], &heap->data[new_pos + 1]) > 0) new_pos += 1;
    if (new_pos < heap->size && comp(&heap->data[pos], &heap->data[new_pos]) > 0) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, data_t val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (comp(&heap->data[pos], &heap->data[parent]) >= 0) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
data_t heap_pop(heap_t *heap) {
    data_t ans    = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize,
                     int **returnColumnSizes) {
    if (k > 1L * nums1Size * nums2Size) k = nums1Size * nums2Size;
    int **ans    = malloc((*returnSize = k) * sizeof(int *));
    heap_t *heap = calloc(1, sizeof(heap_t) + nums1Size * sizeof(data_t));

    *returnColumnSizes = malloc(k * sizeof(int));

    for (int i = 0; i < nums1Size; ++i) {
        heap_add(heap, (data_t) { nums1 + i, nums2 });
    }
    for (int i = 0; i < k; ++i) {
        data_t cur = heap_pop(heap);
        ans[i]     = malloc((returnColumnSizes[0][i] = 2) * sizeof(int));
        ans[i][0] = *cur.x, ans[i][1] = *cur.y;
        if (cur.y + 1 < nums2 + nums2Size) heap_add(heap, (data_t) { cur.x, cur.y + 1 });
    }
    free(heap);

    return ans;
}
