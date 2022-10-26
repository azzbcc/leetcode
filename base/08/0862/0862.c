// 给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组
// ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回-1 。
//
// 子数组 是数组中 连续 的一部分。
//
//
//
//
//
//
// 示例 1：
//
//
// 输入：nums = [1], k = 1
// 输出：1
//
//
// 示例 2：
//
//
// 输入：nums = [1,2], k = 4
// 输出：-1
//
//
// 示例 3：
//
//
// 输入：nums = [2,-1,2], k = 3
// 输出：3
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁵
// -10⁵ <= nums[i] <= 10⁵
// 1 <= k <= 10⁹
//
//
// Related Topics 队列 数组 二分查找 前缀和 滑动窗口 单调队列 堆（优先队列） 👍 501 👎 0

int shortestSubarray(int *nums, int size, int k) {
    int ans = size + 1;
    long prefix[size + 1];

    prefix[0] = 0;
    for (int i = 0; i < size; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    for (int i = 0, ss[size + 1], f = 0, r = 0; i <= size; ss[r++] = i++) {
        for (; f < r && prefix[i] - prefix[ss[f]] >= k; ans = fmin(ans, i - ss[f++])) {}
        for (; f < r && prefix[i] <= prefix[ss[r - 1]]; --r) {}
    }
    return ans <= size ? ans : -1;
}