// 给你一个整数数组 nums 和一个 正 整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。
//
// 数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）
//
// 返回数组的 第 k 大和 。
//
// 子序列是一个可以由其他数组删除某些或不删除元素排生而来的数组，且派生过程不改变剩余元素的顺序。
//
// 注意：空子序列的和视作 0 。
//
//
//
// 示例 1：
//
// 输入：nums = [2,4,-2], k = 5
// 输出：2
// 解释：所有可能获得的子序列和列出如下，按递减顺序排列： 6、4、4、2、2、0、0、-2
// 数组的第 5 大和是 2 。
//
//
// 示例 2：
//
// 输入：nums = [1,-2,3,4,-10,12], k = 16
// 输出：10
// 解释：数组的第 16 大和是 10 。
//
//
//
//
// 提示：
//
//
// n == nums.length
// 1 <= n <= 10⁵
// -10⁹ <= nums[i] <= 10⁹
// 1 <= k <= min(2000, 2ⁿ)
//
//
// Related Topics 数组 排序 堆（优先队列） 👍 120 👎 0

#define MAX 2000
typedef struct {
    int index;
    long long sum;
} node_t;
typedef struct {
    int size;
    node_t data[MAX];
} heap_t;
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
void swap(node_t *a, node_t *b) {
    for (node_t tmp = *a; tmp.sum != b->sum; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t *heap, int cur) {
    for (int next; cur < heap->size; cur = next) {
        next = cur * 2 + 1;
        if (next + 1 < heap->size && heap->data[next].sum >= heap->data[next + 1].sum) next += 1;
        if (next >= heap->size || heap->data[next].sum >= heap->data[cur].sum) break;
        swap(&heap->data[cur], &heap->data[next]);
    }
}
void heap_add(heap_t *heap, node_t val) {
    heap->data[heap->size] = val;
    for (int now = heap->size++, parent; now; now = parent) {
        parent = (now - 1) / 2;
        if (heap->data[parent].sum <= heap->data[now].sum) break;
        swap(&heap->data[now], &heap->data[parent]);
    }
}
node_t heap_pop(heap_t *heap) {
    node_t ans = heap->data[0];

    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
long long kSum(int *nums, int size, int k) {
    int data[size];
    long long sum  = 0;
    heap_t heap[1] = { 0 };
    for (int i = 0; i < size; ++i) {
        data[i] = abs(nums[i]);
        if (nums[i] > 0) sum += nums[i];
    }
    if (k == 1) return sum;
    qsort(data, size, sizeof(int), cmp);

    heap_add(heap, (node_t) { .sum = data[0] });
    for (int i = 2; i < k; ++i) {
        node_t now = heap_pop(heap);
        if (now.index + 1 >= size) continue;
        heap_add(heap, (node_t) { now.index + 1, now.sum + data[now.index + 1] });
        heap_add(heap, (node_t) { now.index + 1, now.sum + data[now.index + 1] - data[now.index] });
    }
    return sum - heap->data[0].sum;
}