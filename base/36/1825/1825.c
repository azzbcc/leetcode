// 给你两个整数 m 和 k ，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 MK 平均值 。
//
// MK 平均值 按照如下步骤计算：
//
//
// 如果数据流中的整数少于 m 个，MK 平均值 为 -1 ，否则将数据流中最后 m 个元素拷贝到一个独立的容器中。
// 从这个容器中删除最小的 k 个数和最大的 k 个数。
// 计算剩余元素的平均值，并 向下取整到最近的整数 。
//
//
// 请你实现 MKAverage 类：
//
//
// MKAverage(int m, int k) 用一个空的数据流和两个整数 m 和 k 初始化 MKAverage 对象。
// void addElement(int num) 往数据流中插入一个新的元素 num 。
// int calculateMKAverage() 对当前的数据流计算并返回 MK 平均数 ，结果需 向下取整到最近的整数 。
//
//
//
//
// 示例 1：
//
//
// 输入：
// ["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement",
// "addElement", "addElement", "calculateMKAverage"]
// [[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
// 输出：
// [null, null, null, -1, null, 3, null, null, null, 5]
//
// 解释：
// MKAverage obj = new MKAverage(3, 1);
// obj.addElement(3);        // 当前元素为 [3]
// obj.addElement(1);        // 当前元素为 [3,1]
// obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
// obj.addElement(10);       // 当前元素为 [3,1,10]
// obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
//                           // 删除最小以及最大的 1 个元素后，容器为 [3]
//                           // [3] 的平均值等于 3/1 = 3 ，故返回 3
// obj.addElement(5);        // 当前元素为 [3,1,10,5]
// obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
// obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
// obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
//                          // 删除最小以及最大的 1 个元素后，容器为 [5]
//                          // [5] 的平均值等于 5/1 = 5 ，故返回 5
//
//
//
//
// 提示：
//
//
// 3 <= m <= 105
// 1 <= k*2 < m
// 1 <= num <= 105
// addElement 与 calculateMKAverage 总操作次数不超过 105 次。
//
// Related Topics 堆 设计 队列
// 👍 15 👎 0

#define MAXN 100001

static bool max(int a, int b) {
    return a > b;
}
static bool min(int a, int b) {
    return a < b;
}
static void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}

typedef struct {
    int front, rear, size;
    int data[];
} * queue_t;
queue_t queue_create(int size) {
    queue_t q = malloc(sizeof(*q) + (size + 1) * sizeof(int));
    q->front = q->rear = 0, q->size = size + 1;
    return q;
}
void queue_destroy(queue_t q) {
    free(q);
}
int queue_size(queue_t q) {
    return (q->rear + q->size - q->front) % q->size;
}
bool queue_full(queue_t q) {
    return (q->rear + 1) % q->size == q->front;
}
int queue_en(queue_t q, int val) {
    int ans = -1;
    if (queue_full(q)) ans = q->data[q->front], q->front = (q->front + 1) % q->size;
    q->data[q->rear] = val, q->rear = (q->rear + 1) % q->size;
    return ans;
}

#define INIT_SIZE 0x100
typedef struct {
    int size, capacity, *data;
    bool (*cmp)(int a, int b);
    int del_map[MAXN], del_count;
} * heap_t;
void heap_adjust(heap_t heap, int pos) {
    int new_pos = pos;
    if (2 * pos + 1 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 1])) new_pos = 2 * pos + 1;
    if (2 * pos + 2 < heap->size && !heap->cmp(heap->data[new_pos], heap->data[2 * pos + 2])) new_pos = 2 * pos + 2;
    if (new_pos != pos) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
heap_t heap_create(bool (*cmp)(int, int)) {
    heap_t heap = malloc(sizeof(*heap));
    memset(heap->del_map, 0, sizeof(heap->del_map));
    heap->size = 0, heap->del_count = 0, heap->capacity = INIT_SIZE;
    heap->cmp = cmp, heap->data = malloc(heap->capacity * sizeof(int));
    return heap;
}
void heap_destroy(heap_t heap) {
    free(heap->data);
    free(heap);
}
int heap_size(heap_t heap) {
    return heap->size - heap->del_count;
}
bool heap_empty(heap_t heap) {
    return heap_size(heap) == 0;
}
void heap_add(heap_t heap, int val) {
    if (heap->del_map[val]) {
        heap->del_map[val] -= 1, heap->del_count -= 1;
        return;
    }
    if (heap->size + 1 >= heap->capacity) heap->data = realloc(heap->data, (heap->capacity *= 2) * sizeof(int));
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->cmp(heap->data[parent], heap->data[pos])) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
void heap_del(heap_t heap, int val) {
    heap->del_map[val] += 1, heap->del_count += 1;
}
int heap_top(heap_t heap) {
    while (!heap_empty(heap) && heap->del_map[heap->data[0]]) {
        heap->del_map[heap->data[0]] -= 1, heap->del_count -= 1;
        heap->data[0] = heap->data[--heap->size];
        heap_adjust(heap, 0);
    }
    return heap_empty(heap) ? -1 : heap->data[0];
}
int heap_pop(heap_t heap) {
    int ans       = heap_top(heap);
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int heap_replace(heap_t heap, int val) {
    int ans       = heap_top(heap);
    heap->data[0] = val;
    heap_adjust(heap, 0);
    return ans;
}

typedef struct {
    int m, k;
    long sum;
    queue_t q;
    heap_t bot, mid0, mid1, top;
} MKAverage;
MKAverage *mKAverageCreate(int m, int k) {
    MKAverage *avg = malloc(sizeof(MKAverage));
    avg->m = m, avg->k = k, avg->sum = 0;
    avg->q    = queue_create(m);
    avg->bot  = heap_create(max);
    avg->mid0 = heap_create(min);
    avg->mid1 = heap_create(max);
    avg->top  = heap_create(min);
    return avg;
}
void mKAverageAddElement(MKAverage *avg, int num) {
    // 统一转化为中间部分处理
    int del = queue_en(avg->q, num);
    if (del != -1 && !heap_empty(avg->bot) && del <= heap_top(avg->bot)) {
        heap_del(avg->bot, del);
        del = heap_top(avg->mid0);
        heap_add(avg->bot, del);
    }
    if (del != -1 && !heap_empty(avg->top) && del >= heap_top(avg->top)) {
        heap_del(avg->top, del);
        del = heap_top(avg->mid1);
        heap_add(avg->top, del);
    }

    if (heap_size(avg->bot) < avg->k) {
        heap_add(avg->bot, num);
        return;
    } else if (!heap_empty(avg->bot) && num <= heap_top(avg->bot)) {
        num = heap_replace(avg->bot, num);
    }
    if (heap_size(avg->top) < avg->k) {
        heap_add(avg->top, num);
        return;
    } else if (!heap_empty(avg->top) && num >= heap_top(avg->top)) {
        num = heap_replace(avg->top, num);
    }

    // 删除优先处理
    if (del != -1) {
        avg->sum -= del;
        heap_del(avg->mid0, del);
        heap_del(avg->mid1, del);
    }
    avg->sum += num;
    heap_add(avg->mid0, num);
    heap_add(avg->mid1, num);
}
int mKAverageCalculateMKAverage(MKAverage *avg) {
    if (queue_size(avg->q) < avg->m) return -1;
    return avg->sum / (avg->m - 2 * avg->k);
}
void mKAverageFree(MKAverage *avg) {
    queue_destroy(avg->q);
    heap_destroy(avg->bot);
    heap_destroy(avg->mid0);
    heap_destroy(avg->mid1);
    heap_destroy(avg->top);
    free(avg);
}