// 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，
// 其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，
// 并且必须在不晚于 lastDayi 的时候完成。
//
// 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
//
// 返回你最多可以修读的课程数目。
//
//
//
// 示例 1：
//
//
// 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
// 输出：3
// 解释：
// 这里一共有 4 门课程，但是你最多可以修 3 门：
// 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
// 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
// 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
// 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
//
// 示例 2：
//
//
// 输入：courses = [[1,2]]
// 输出：1
//
//
// 示例 3：
//
//
// 输入：courses = [[3,2],[4,3]]
// 输出：0
//
//
//
//
// 提示:
//
//
// 1 <= courses.length <= 10⁴
// 1 <= durationi, lastDayi <= 10⁴
//
// Related Topics 贪心 数组 堆（优先队列） 👍 230 👎 0

typedef struct {
    int size;
    int data[];
} heap_t;
int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    return pa[1] - pb[1];
}
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
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
int heap_pop(heap_t *heap) {
    int ans;
    ans = heap->data[0], heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int scheduleCourse(int **courses, int size, int *colSize) {
    int memory[size + 1];
    heap_t *heap = ( heap_t * )memory;

    heap->size = 0;
    qsort(courses, size, sizeof(int *), cmp);
    for (int i = 0, sum = 0; i < size; ++i) {
        int duration = courses[i][0], end = courses[i][1];
        if (sum + duration <= end) {
            sum += duration;
            heap_add(heap, duration);
        } else if (heap->size && heap->data[0] > duration) {
            sum -= heap_pop(heap) - duration;
            heap_add(heap, duration);
        }
    }
    return heap->size;
}