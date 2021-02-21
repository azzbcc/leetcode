// 给你一个整数数组 nums ，和一个表示限制的整数
// limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limi t 。
//
// 如果不存在满足条件的子数组，则返回 0 。
//
//
//
// 示例 1：
//
// 输入：nums = [8,2,4,7], limit = 4
// 输出：2
// 解释：所有子数组如下：
// [8] 最大绝对差 |8-8| = 0 <= 4.
// [8,2] 最大绝对差 |8-2| = 6 > 4.
// [8,2,4] 最大绝对差 |8-2| = 6 > 4.
// [8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
// [2] 最大绝对差 |2-2| = 0 <= 4.
// [2,4] 最大绝对差 |2-4| = 2 <= 4.
// [2,4,7] 最大绝对差 |2-7| = 5 > 4.
// [4] 最大绝对差 |4-4| = 0 <= 4.
// [4,7] 最大绝对差 |4-7| = 3 <= 4.
// [7] 最大绝对差 |7-7| = 0 <= 4.
// 因此，满足题意的最长子数组的长度为 2 。
//
//
// 示例 2：
//
// 输入：nums = [10,1,2,4,7,2], limit = 5
// 输出：4
// 解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
//
//
// 示例 3：
//
// 输入：nums = [4,2,2,2,4,4,2,2], limit = 0
// 输出：3
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^9
// 0 <= limit <= 10^9
//
// Related Topics 数组 Sliding Window
// 👍 83 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} hash_t;
typedef struct {
    int size;
    hash_t *del;
    bool (*cmp)(int a, int b);
    int data[];
} heap_t;
bool max(int a, int b) {
    return a > b;
}
bool min(int a, int b) {
    return a < b;
}
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
heap_t *heap_init(int size, bool (*cmp)(int, int)) {
    heap_t *ans = malloc(sizeof(heap_t) + size * sizeof(int));
    ans->size = 0, ans->cmp = cmp, ans->del = NULL;
    return ans;
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos;
    if (2 * pos + 1 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 1])) new_pos = 2 * pos + 1;
    if (2 * pos + 2 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 2])) new_pos = 2 * pos + 2;
    if (new_pos != pos) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, int val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->cmp(heap->data[parent], heap->data[pos])) break;
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
int longestSubarray(int *nums, int size, int limit) {
    int ans = 0;
    heap_t *min_heap = heap_init(size, min), *max_heap = heap_init(size, max);

    for (int beg = 0, end = 0; end < size; ++end) {
        heap_add(min_heap, nums[end]);
        heap_add(max_heap, nums[end]);
        for (; heap_top(max_heap) - heap_top(min_heap) > limit; beg++) {
            heap_del(max_heap, nums[beg]);
            heap_del(min_heap, nums[beg]);
        }
        if (ans < end - beg + 1) ans = end - beg + 1;
    }

    heap_destroy(min_heap), heap_destroy(max_heap);
    return ans;
}
