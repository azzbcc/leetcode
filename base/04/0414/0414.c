//
// 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
//
//
//
// 示例 1：
//
//
// 输入：[3, 2, 1]
// 输出：1
// 解释：第三大的数是 1 。
//
// 示例 2：
//
//
// 输入：[1, 2]
// 输出：2
// 解释：第三大的数不存在, 所以返回最大的数 2 。
//
//
// 示例 3：
//
//
// 输入：[2, 2, 3, 1]
// 输出：1
// 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
// 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁴
// -2³¹ <= nums[i] <= 2³¹ - 1
//
//
//
//
// 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
// Related Topics 数组 排序 👍 271 👎 0

typedef struct {
    int size, data[3];
} heap_t;
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
int thirdMax(int *nums, int size) {
    heap_t heap[1] = { 0 };
    for (int i = 0; i < size; ++i) {
        bool exists = false;
        for (int j = 0; !exists && j < heap->size; exists = nums[i] == heap->data[j++]) {}
        if (exists) continue;
        if (heap->size < 3) {
            heap->data[heap->size++] = nums[i];
            if (nums[i] < heap->data[0]) swap(&heap->data[0], &heap->data[heap->size - 1]);
        } else if (nums[i] > heap->data[0]) {
            heap->data[0] = nums[i];
            int pos = heap->data[1] < heap->data[2] ? 1 : 2;
            if (nums[i] > heap->data[pos]) swap(&heap->data[0], &heap->data[pos]);
        }
    }
    return heap->size == 3 ? heap->data[0] : heap->data[heap->size - 1];
}
