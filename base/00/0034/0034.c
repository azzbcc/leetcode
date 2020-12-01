// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
// 你的算法时间复杂度必须是 O(log n) 级别。
//
// 如果数组中不存在目标值，返回 [-1, -1]。
//
// 示例 1:
//
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
//
// 示例 2:
//
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]
// Related Topics 数组 二分查找
// 👍 625 👎 0

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int beg = 0, end = numsSize - 1, mid;
    int *ans = calloc(*returnSize = 2, sizeof(int));

    for (ans[0] = ans[1] = -1; beg <= end;) {
        mid = (beg + end) / 2;
        if (nums[mid] == target) break;
        if (nums[mid] > target) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    if (beg > end) return ans;

    for (int m, r = mid; beg <= r;) {
        m = (beg + r) / 2;
        if (nums[m] < target) {
            beg = m + 1;
        } else {
            r = m - 1;
        }
    }
    for (int m, l = mid; l <= end;) {
        m = (l + end) / 2;
        if (nums[m] > target) {
            end = m - 1;
        } else {
            l = m + 1;
        }
    }
    ans[0] = beg, ans[1] = end;

    return ans;
}
