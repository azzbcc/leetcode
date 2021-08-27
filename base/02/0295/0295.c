//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
//
// 例如，
//
// [2,3,4] 的中位数是 3
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5
//
// 设计一个支持以下两种操作的数据结构：
//
//
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
//
//
// 示例：
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3)
// findMedian() -> 2
//
// 进阶:
//
//
// 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
// 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
//
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 485 👎 0

#define DYNAMIC_ARRAY_SIZE 128
typedef struct {
    int *data;
    int size, capacity;
    bool (*cmp)(int a, int b);
} * heap_t;
static bool max(int a, int b) {
    return a > b;
}
static bool min(int a, int b) {
    return a < b;
}
static void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
heap_t heap_init(bool (*cmp)(int, int)) {
    heap_t ans = malloc(sizeof(*ans));

    ans->size = 0, ans->cmp = cmp;
    ans->data = malloc((ans->capacity = DYNAMIC_ARRAY_SIZE) * sizeof(int));
    return ans;
}
void heap_adjust(heap_t heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->cmp(heap->data[new_pos + 1], heap->data[new_pos])) new_pos += 1;
    if (new_pos < heap->size && heap->cmp(heap->data[new_pos], heap->data[pos])) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t heap, int val) {
    if (heap->size == heap->capacity) {
        heap->data = realloc(heap->data, (heap->capacity += DYNAMIC_ARRAY_SIZE) * sizeof(int));
    }
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->cmp(heap->data[parent], heap->data[pos])) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
int heap_pop(heap_t heap) {
    int ans = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
void heap_destroy(heap_t heap) {
    free(heap->data);
    free(heap);
}
typedef struct {
    heap_t min, max;
} MedianFinder;
MedianFinder *medianFinderCreate() {
    MedianFinder *finder = malloc(sizeof(*finder));
    finder->min = heap_init(max), finder->max = heap_init(min);
    return finder;
}
void medianFinderAddNum(MedianFinder *finder, int num) {
    if (finder->max->size == 0 || num >= finder->max->data[0]) {
        heap_add(finder->max, num);
    } else {
        heap_add(finder->min, num);
    }
    int diff = finder->max->size - finder->min->size;
    if (diff == 2) {
        heap_add(finder->min, heap_pop(finder->max));
    } else if (diff == -2) {
        heap_add(finder->max, heap_pop(finder->min));
    }
}
double medianFinderFindMedian(MedianFinder *finder) {
    int diff = finder->max->size - finder->min->size;
    if (diff == 0) {
        return (finder->max->data[0] + finder->min->data[0]) / 2.0;
    } else if (diff == 1) {
        return finder->max->data[0];
    } else {
        return finder->min->data[0];
    }
}
void medianFinderFree(MedianFinder *finder) {
    heap_destroy(finder->min), heap_destroy(finder->max);
    free(finder);
}