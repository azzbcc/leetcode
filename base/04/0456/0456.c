// 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k]
// 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
//
// 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
//
//
//
// 进阶：很容易想到时间复杂度为 O(n^2) 的解决方案，你可以设计一个时间复杂度为 O(n logn) 或 O(n) 的解决方案吗？
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,3,4]
// 输出：false
// 解释：序列中不存在 132 模式的子序列。
//
//
// 示例 2：
//
//
// 输入：nums = [3,1,4,2]
// 输出：true
// 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
//
//
// 示例 3：
//
//
// 输入：nums = [-1,3,2,0]
// 输出：true
// 解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
//
//
//
//
// 提示：
//
//
// n == nums.length
// 1 <= n <= 104
// -109 <= nums[i] <= 109
//
// Related Topics 栈
// 👍 383 👎 0

#if 0
typedef struct {
    int min, max
} node_t;
bool find132pattern(int *nums, int size) {
    int top = -1;
    node_t stack[size];

    stack[++top] = (node_t) { *nums, *nums };
    for (int i = 1, num; i < size; ++i) {
        num = nums[i];
        for (int c = 0; c <= top; ++c) {
            if (num > stack[c].min && num < stack[c].max) return true;
        }
        if (num >= stack[top].max) {
            stack[top].max = num;
        } else if (num < stack[top].min) {
            stack[++top] = (node_t) { num, num };
        }
    }

    return false;
}
#else
bool find132pattern(int *nums, int size) {
    int max = INT32_MIN;
    int stack[size], top = -1;

    stack[++top] = nums[size - 1];
    for (int i = size - 2; i >= 0; --i) {
        if (nums[i] < max) return true;
        for (; top > -1 && nums[i] > stack[top]; max = stack[top--]) {}
        if (nums[i] > max) stack[++top] = nums[i];
    }
    return false;
}
#endif
