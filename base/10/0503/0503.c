// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
// 数字
// x的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
// 如果不存在，则输出 -1。
//
// 示例 1:
//
//
// 输入: [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数；
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//
//
// 注意: 输入数组的长度不会超过 10000。
// Related Topics 栈
// 👍 335 👎 0

int *nextGreaterElements(int *nums, int size, int *returnSize) {
    int stack[size + 1], top = -1;
    int *ans = malloc((*returnSize = size) * sizeof(int));

    for (int i = size - 1; i >= 0; stack[++top] = nums[i--]) {
        for (; top >= 0 && stack[top] <= nums[i]; top--) {}
        ans[i] = top >= 0 ? stack[top] : -1;
    }
    for (int i = size - 1; i >= 0; stack[++top] = nums[i--]) {
        for (; top >= 0 && stack[top] <= nums[i]; top--) {}
        if (top < 0) break;
        ans[i] = stack[top];
    }

    return ans;
}