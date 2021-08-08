// 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
//
// 请实现 KthLargest 类：
//
//
// KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
// int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
//
//
//
//
// 示例：
//
//
// 输入：
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// 输出：
// [null, 4, 5, 5, 8, 8]
//
// 解释：
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8
//
//
//
// 提示：
//
//
// 1 <= k <= 104
// 0 <= nums.length <= 104
// -104 <= nums[i] <= 104
// -104 <= val <= 104
// 最多调用 add 方法 104 次
// 题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
//
// Related Topics 堆 设计
// 👍 191 👎 0

#define MIN -10001

typedef struct {
    int size;
    int heap[];
} KthLargest;

static void heap_adjust(KthLargest *kth, int pos) {
    int max_pos = pos;
    if (2 * pos + 1 < kth->size && kth->heap[max_pos] > kth->heap[2 * pos + 1]) max_pos = 2 * pos + 1;
    if (2 * pos + 2 < kth->size && kth->heap[max_pos] > kth->heap[2 * pos + 2]) max_pos = 2 * pos + 2;
    if (max_pos != pos) {
        int tmp            = kth->heap[pos];
        kth->heap[pos]     = kth->heap[max_pos];
        kth->heap[max_pos] = tmp;
        heap_adjust(kth, max_pos);
    }
}

KthLargest *kthLargestCreate(int k, int *nums, int size) {
    KthLargest *kth = malloc(sizeof(KthLargest) + k * sizeof(int));

    kth->size = k;
    for (int i = 0; i < k && i < size; ++i) {
        kth->heap[i] = nums[i];
    }
    if (size < k) kth->heap[k - 1] = MIN;
    for (int i = k / 2 - 1; i >= 0; heap_adjust(kth, i--)) {}
    for (int i = k; i < size; ++i) {
        if (nums[i] > kth->heap[0]) kth->heap[0] = nums[i], heap_adjust(kth, 0);
    }

    return kth;
}

int kthLargestAdd(KthLargest *kth, int val) {
    if (val > kth->heap[0]) kth->heap[0] = val, heap_adjust(kth, 0);
    return kth->heap[0];
}

void kthLargestFree(KthLargest *obj) {
    free(obj);
}