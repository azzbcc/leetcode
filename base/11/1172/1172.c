// 我们把无限数量 ∞ 的栈排成一行，按从左到右的次序从 0 开始编号。每个栈的的最大容量 capacity 都相同。
//
// 实现一个叫「餐盘」的类 DinnerPlates：
//
//
// DinnerPlates(int capacity) - 给出栈的最大容量 capacity。
// void push(int val) - 将给出的正整数 val 推入 从左往右第一个 没有满的栈。
// int pop() - 返回 从右往左第一个 非空栈顶部的值，并将其从栈中删除；如果所有的栈都是空的，请返回 -1。
// int popAtStack(int index) - 返回编号 index 的栈顶部的值，并将其从栈中删除；如果编号 index 的栈是空的，请返回 -1。
//
//
//
//
// 示例：
//
// 输入：
// ["DinnerPlates","push","push","push","push","push","popAtStack","push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
// [[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
// 输出：
// [null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]
//
// 解释：
// DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
// D.push(1);
// D.push(2);
// D.push(3);
// D.push(4);
// D.push(5);         // 栈的现状为：   2  4
//                                    1  3  5
//                                    ﹈ ﹈ ﹈
// D.popAtStack(0);   // 返回 2。栈的现状为：     4
//                                          1  3  5
//                                          ﹈ ﹈ ﹈
// D.push(20);        // 栈的现状为：  20  4
//                                    1  3  5
//                                    ﹈ ﹈ ﹈
// D.push(21);        // 栈的现状为：  20  4 21
//                                    1  3  5
//                                    ﹈ ﹈ ﹈
// D.popAtStack(0);   // 返回 20。栈的现状为：       4 21
//                                             1  3  5
//                                             ﹈ ﹈ ﹈
// D.popAtStack(2);   // 返回 21。栈的现状为：       4
//                                             1  3  5
//                                             ﹈ ﹈ ﹈
// D.pop()            // 返回 5。栈的现状为：        4
//                                             1  3
//                                             ﹈ ﹈
// D.pop()            // 返回 4。栈的现状为：    1  3
//                                            ﹈ ﹈
// D.pop()            // 返回 3。栈的现状为：    1
//                                            ﹈
// D.pop()            // 返回 1。现在没有栈。
// D.pop()            // 返回 -1。仍然没有栈。
//
//
//
//
// 提示：
//
//
// 1 <= capacity <= 20000
// 1 <= val <= 20000
// 0 <= index <= 100000
// 最多会对 push，pop，和 popAtStack 进行 200000 次调用。
//
//
// Related Topics 栈 设计 哈希表 堆（优先队列） 👍 73 👎 0

#define DYNAMIC_ARRAY_SIZE 128
typedef struct {
    int key, count;
    UT_hash_handle hh;
} *hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t find = NULL;
    HASH_FIND_INT(t, &key, find);
    return find;
}
void hash_record(hash_t *t, int key) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
void hash_destroy(hash_t t) {
    hash_t cur, next;
    HASH_ITER(hh, t, cur, next) {
        HASH_DEL(t, cur);
        free(cur);
    }
}
typedef struct {
    hash_t del;
    int *data;
    int size, capacity;
} *heap_t;
static void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
heap_t heap_init() {
    heap_t ans = malloc(sizeof(*ans));
    ans->size = 0, ans->del = NULL;
    ans->data = malloc((ans->capacity = DYNAMIC_ARRAY_SIZE) * sizeof(int));
    return ans;
}
void heap_destroy(heap_t heap) {
    hash_destroy(heap->del);
    free(heap->data);
    free(heap);
}
void heap_adjust(heap_t heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos] > heap->data[new_pos + 1]) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos] > heap->data[new_pos]) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_pop(heap_t heap) {
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
}
bool heap_empty(heap_t heap) {
    for (hash_t find; heap->size;) {
        find = hash_find(heap->del, heap->data[0]);
        if (!find) return false;
        heap_pop(heap);
        if (--find->count) continue;
        HASH_DEL(heap->del, find);
        free(find);
    }
    return true;
}
void heap_add(heap_t heap, int val) {
    if (heap->size == heap->capacity) {
        heap->data = realloc(heap->data, (heap->capacity *= 2) * sizeof(int));
    }
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent] < heap->data[pos]) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
void heap_del(heap_t heap, int val) {
    hash_record(&heap->del, val);
}
typedef struct {
    int capacity;
    heap_t no_full;
    int *data;
    int size, data_capacity;
} DinnerPlates;
DinnerPlates *dinnerPlatesCreate(int capacity) {
    DinnerPlates *plates = malloc(sizeof(*plates));
    plates->capacity = capacity, plates->size = 0, plates->no_full = heap_init();
    plates->data    = malloc((plates->data_capacity = DYNAMIC_ARRAY_SIZE) * sizeof(int) * (capacity + 1));
    plates->data[0] = 0;
    return plates;
}
void dinnerPlatesPush(DinnerPlates *plates, int val) {
    if (heap_empty(plates->no_full)) {
        // 保证有新堆空间
        if (plates->size + 1 == plates->data_capacity) {
            plates->data = realloc(plates->data, (plates->data_capacity *= 2) * sizeof(int) * (plates->capacity + 1));
        }
        int *stack = plates->data + plates->size * (plates->capacity + 1);
        // 入栈
        stack[++stack[0]] = val, stack[plates->capacity + 1] = 0;
        if (stack[0] < plates->capacity) heap_add(plates->no_full, plates->size);
        plates->size++;
    } else {
        // 插入第一个未满的堆
        int position = plates->no_full->data[0];
        int *stack   = plates->data + position * (plates->capacity + 1);
        // 入栈
        stack[++stack[0]] = val;
        // 如果栈满，从堆中删除记录
        if (stack[0] == plates->capacity) heap_del(plates->no_full, position);
    }
}
int dinnerPlatesPop(DinnerPlates *plates) {
    int *stack;
    for (; plates->size; heap_del(plates->no_full, --plates->size)) {
        stack = plates->data + (plates->size - 1) * (plates->capacity + 1);
        if (stack[0]) break;
    }
    if (!plates->size) return -1;
    if (stack[0] == plates->capacity) heap_add(plates->no_full, plates->size - 1);
    int ans = stack[stack[0]--];
    if (!stack[0]) heap_del(plates->no_full, --plates->size);
    return ans;
}
int dinnerPlatesPopAtStack(DinnerPlates *plates, int index) {
    if (index >= plates->size) return -1;
    int *stack = plates->data + index * (plates->capacity + 1);
    if (!stack[0]) return -1;
    if (stack[0] == plates->capacity) heap_add(plates->no_full, index);
    return stack[stack[0]--];
}
void dinnerPlatesFree(DinnerPlates *plates) {
    heap_destroy(plates->no_full);
    free(plates->data);
    free(plates);
}