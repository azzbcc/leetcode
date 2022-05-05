// 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//
//
// 示例 1：
//
//
// 输入：nums = [10,5,2,6], k = 100
// 输出：8
// 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
// 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
//
//
// 示例 2：
//
//
// 输入：nums = [1,2,3], k = 0
// 输出：0
//
//
//
// 提示:
//
//
// 1 <= nums.length <= 3 * 10⁴
// 1 <= nums[i] <= 1000
// 0 <= k <= 10⁶
//
// Related Topics 数组 滑动窗口 👍 450 👎 0

#if 0
int numSubarrayProductLessThanK(int *nums, int size, int k) {
    int ans = 0;
    for (int l = 0, r = 0, mul = 1; l < size; ++l) {
        for (; r < size && mul * nums[r] < k; mul *= nums[r++]) {}
        ans += r - l;
        if (l == r) {
            r++;
        } else {
            mul /= nums[l];
        }
    }
    return ans;
}
#else
int numSubarrayProductLessThanK(int *nums, int size, int k) {
    int ans = 0;
    for (int l = 0, r = 0, mul = 1; r < size; ++r) {
        for (mul *= nums[r]; mul >= k && l <= r; mul /= nums[l++]) {}
        ans += r - l + 1;
    }
    return ans;
}
#endif
