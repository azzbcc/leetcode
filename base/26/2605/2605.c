// 给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，
// 请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。
//
//
//
// 示例 1：
//
// 输入：nums1 = [4,1,3], nums2 = [5,7]
// 输出：15
// 解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
//
//
// 示例 2：
//
// 输入：nums1 = [3,5,2,6], nums2 = [3,1,7]
// 输出：3
// 解释：数字 3 的数位 3 在两个数组中都出现了。
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length, nums2.length <= 9
// 1 <= nums1[i], nums2[i] <= 9
// 每个数组中，元素 互不相同 。
//
//
// Related Topics 数组 哈希表 枚举 👍 90 👎 0

int minNumber(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int m1 = 10, m2 = 10;
    bool f1[10] = { false }, f2[10] = { false };
    for (int i = 0; i < nums1Size; m1 = fmin(m1, nums1[i]), f1[nums1[i++]] = true) {}
    for (int i = 0; i < nums2Size; m2 = fmin(m2, nums2[i]), f2[nums2[i++]] = true) {}
    for (int i = 0; i < 10; ++i) {
        if (f1[i] && f2[i]) return i;
    }
    return fmin(m1 * 10 + m2, m1 + m2 * 10);
}