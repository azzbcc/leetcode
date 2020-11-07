// 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
//
// 说明:
// 最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。
//
// 示例:
//
// 输入: nums = [-2,5,-1], lower = -2, upper = 2,
// 输出: 3
// 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
//
// Related Topics 排序 树状数组 线段树 二分查找 分治算法
// 👍 184 👎 0

int countRange(const long sums[], int left, int right, long lower, long upper) {
    long sum;
    int mid = (left + right) / 2, count = 0;
    if (mid == left) {
        sum = sums[right] - sums[left];
        return right > left && lower <= sum && sum <= upper;
    }
    for (int i = left; i < mid; ++i) {
        for (int j = right; j > mid; --j) {
            sum = sums[j] - sums[i];
            count += lower <= sum && sum <= upper;
        }
    }
    count += countRange(sums, left, mid, lower, upper);
    count += countRange(sums, mid, right, lower, upper);
    return count;
}

int countRangeSum(int *nums, int numsSize, int lower, int upper) {
    long sums[numsSize + 1];

    sums[0] = 0;
    for (int i = 0; i < numsSize; ++i) {
        sums[i + 1] = sums[i] + nums[i];
    }

    return countRange(sums, 0, numsSize, lower, upper);
}
