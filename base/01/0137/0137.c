// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//
//
//
// 示例 1：
//
//
// 输入：nums = [2,2,3,2]
// 输出：3
//
//
// 示例 2：
//
//
// 输入：nums = [0,1,0,1,0,1,99]
// 输出：99
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
//
//
//
//
// 进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
// Related Topics 位运算
// 👍 631 👎 0

#if 0
int singleNumber(int *nums, int size) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        long c = 0;
        for (int j = 0; j < size; ++j) {
            c += nums[j] >> i & 1;
        }
        ans |= (c % 3) << i;
    }
    return ans;
}
#else
int singleNumber(int *nums, int size) {
    int a = 0, b = 0;
    for (int i = 0; i < size; i++) {
        b = ~a & (b ^ nums[i]);
        a = ~b & (a ^ nums[i]);
    }
    return b;
}
#endif