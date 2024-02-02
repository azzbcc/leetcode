// 小扣在秋日市集入口处发现了一个数字游戏。主办方共有 `N` 个计数器，计数器编号为 `0 ~ N-1`。
// 每个计数器上分别显示了一个数字，小扣按计数器编号升序将所显示的数字记于数组 `nums`。
// 每个计数器上有两个按钮，分别可以实现将显示数字加一或减一。小扣每一次操作可以选择一个计数器，按下加一或减一按钮。
//
// 主办方请小扣回答出一个长度为 `N` 的数组，第 `i` 个元素(0 <= i < N)表示将 `0~i` 号计数器
// **初始** 所示数字操作成满足所有条件 `nums[a]+1 == nums[a+1],(0 <= a < i)` 的最小操作数。
// 回答正确方可进入秋日市集。
//
// 由于答案可能很大，请将每个最小操作数对 `1,000,000,007` 取余。
//
// **示例 1：**
//
// 输入：`nums = [3,4,5,1,6,7]`
//
// 输出：`[0,0,0,5,6,7]`
//
// 解释：
// i = 0，[3] 无需操作
// i = 1，[3,4] 无需操作；
// i = 2，[3,4,5] 无需操作；
// i = 3，将 [3,4,5,1] 操作成 [3,4,5,6], 最少 5 次操作；
// i = 4，将 [3,4,5,1,6] 操作成 [3,4,5,6,7], 最少 6 次操作；
// i = 5，将 [3,4,5,1,6,7] 操作成 [3,4,5,6,7,8]，最少 7 次操作；
// 返回 [0,0,0,5,6,7]。
//
// **示例 2：**
//
// 输入：`nums = [1,2,3,4,5]`
//
// 输出：`[0,0,0,0,0]`
//
// 解释：对于任意计数器编号 i 都无需操作。
//
// **示例 3：**
//
// 输入：`nums = [1,1,1,2,3,4]`
//
// 输出：`[0,1,2,3,3,3]`
//
// 解释：
// i = 0，无需操作；
// i = 1，将 [1,1] 操作成 [1,2] 或 [0,1] 最少 1 次操作；
// i = 2，将 [1,1,1] 操作成 [1,2,3] 或 [0,1,2]，最少 2 次操作；
// i = 3，将 [1,1,1,2] 操作成 [1,2,3,4] 或 [0,1,2,3]，最少 3 次操作；
// i = 4，将 [1,1,1,2,3] 操作成 [-1,0,1,2,3]，最少 3 次操作；
// i = 5，将 [1,1,1,2,3,4] 操作成 [-1,0,1,2,3,4]，最少 3 次操作；
// 返回 [0,1,2,3,3,3]。
//
// **提示：**
// - `1 <= nums.length <= 10^5`
// - `1 <= nums[i] <= 10^3`
//
// Related Topics 数组 数学 堆（优先队列） 👍 67 👎 0

#define MOD 1000000007
typedef struct {
    long sum;
    bool (*cmp)(int a, int b);
    int size, data[];
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
heap_t *heap_init(int capacity, bool (*cmp)(int, int)) {
    heap_t *ans = malloc(sizeof(heap_t) + capacity * sizeof(int));
    ans->sum = ans->size = 0, ans->cmp = cmp;
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
    heap->data[heap->size] = val, heap->sum += val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->cmp(heap->data[parent], heap->data[pos])) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
int heap_pop(heap_t *heap) {
    int ans = heap->data[0];
    heap->sum -= heap->data[0], heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int *numsGame(int *nums, int size, int *returnSize) {
    int *ans         = malloc((*returnSize = size) * sizeof(int));
    heap_t *min_heap = heap_init(size, min), *max_heap = heap_init(size, max);

    for (int i = 0, tmp; i < size; ++i) {
        tmp = nums[i] - i;
        if (min_heap->size > max_heap->size) {
            if (tmp > min_heap->data[0]) {
                heap_add(min_heap, tmp);
                tmp = heap_pop(min_heap);
            }
            heap_add(max_heap, tmp);
        } else {
            if (max_heap->size && tmp < max_heap->data[0]) {
                heap_add(max_heap, tmp);
                tmp = heap_pop(max_heap);
            }
            heap_add(min_heap, tmp);
        }
        if (i % 2) {
            ans[i] = (min_heap->sum - max_heap->sum) % MOD;
        } else {
            ans[i] = (min_heap->sum - min_heap->data[0] - max_heap->sum) % MOD;
        }
    }

    free(min_heap);
    free(max_heap);
    return ans;
}
