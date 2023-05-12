// 给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]| 的和。
//
// 你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。
//
// 请你找到可行的最大 数组值 。
//
//
//
// 示例 1：
//
// 输入：nums = [2,3,1,5,4]
// 输出：10
// 解释：通过翻转子数组 [3,1,5] ，数组变成 [2,5,1,3,4] ，数组值为 10 。
//
//
// 示例 2：
//
// 输入：nums = [2,4,9,24,2,1,10]
// 输出：68
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 3*10^4
// -10^5 <= nums[i] <= 10^5
//
//
// Related Topics 贪心 数组 数学 👍 119 👎 0

int maxValueAfterReverse(int *nums, int size) {
    int sum = 0, max = INT32_MIN, min = INT32_MAX, ot = 0;
    for (int i = 1, x, y, d; i < size; ++i, sum += d) {
        x = nums[i - 1], y = nums[i], d = abs(x - y);
        max = fmax(max, fmin(x, y)), min = fmin(min, fmax(x, y));
        ot = fmax(fmax(ot, abs(nums[0] - y) - d), abs(x - nums[size - 1]) - d);
    }
    return fmax((max - min) * 2, ot) + sum;
}