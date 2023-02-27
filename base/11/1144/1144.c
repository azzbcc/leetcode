// 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。
//
// 如果符合下列情况之一，则数组 A 就是 锯齿数组：
//
//
// 每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
// 或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
//
//
// 返回将数组 nums 转换为锯齿数组所需的最小操作次数。
//
//
//
// 示例 1：
//
// 输入：nums = [1,2,3]
// 输出：2
// 解释：我们可以把 2 递减到 0，或把 3 递减到 1。
//
//
// 示例 2：
//
// 输入：nums = [9,6,1,6,2]
// 输出：4
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
//
//
// Related Topics 贪心 数组 👍 87 👎 0

int movesToMakeZigzag(int *nums, int size) {
    int sc[2] = { 0 };
    for (int i = 0, min; i < size; ++i) {
        min = INT32_MAX;
        if (i > 0) min = fmin(min, nums[i - 1]);
        if (i + 1 < size) min = fmin(min, nums[i + 1]);
        if (nums[i] < min) continue;
        sc[i % 2] += nums[i] - min + 1;
    }
    return fmin(sc[0], sc[1]);
}