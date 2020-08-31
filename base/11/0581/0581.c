// 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
// 你找到的子数组应是最短的，请输出它的长度。
//
// 示例 1:
//
//
// 输入: [2, 6, 4, 8, 10, 9, 15]
// 输出: 5
// 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
//
//
// 说明 :
//
//
// 输入的数组长度范围在 [1, 10,000]。
// 输入的数组可能包含重复元素 ，所以升序的意思是<=。
//
// Related Topics 数组
// 👍 378 👎 0

int findUnsortedSubarray(int *nums, int numsSize) {
    int beg = 0, end = numsSize;

    while (++beg < numsSize && nums[beg - 1] <= nums[beg]) {}
    if (beg-- == numsSize) return 0;
    while (--end > 0 && nums[end] >= nums[end - 1]) {}

    int min = nums[beg], max = nums[beg];
    for (int i = beg + 1; i <= end; ++i) {
        if (min > nums[i]) min = nums[i];
        if (max < nums[i]) max = nums[i];
    }

    while (beg-- > 0 && nums[beg] > min) {}
    while (++end < numsSize && nums[end] < max) {}

    return end - beg - 1;
}