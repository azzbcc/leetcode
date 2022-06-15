// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
//
// 给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。
// 返回所有数对距离中 第 k 小的数对距离。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,3,1], k = 1
// 输出：0
// 解释：数对和对应的距离如下：
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// 距离第 1 小的数对是 (1,1) ，距离为 0 。
//
//
// 示例 2：
//
//
// 输入：nums = [1,1,1], k = 2
// 输出：0
//
//
// 示例 3：
//
//
// 输入：nums = [1,6,1], k = 3
// 输出：5
//
//
//
//
// 提示：
//
//
// n == nums.length
// 2 <= n <= 10⁴
// 0 <= nums[i] <= 10⁶
// 1 <= k <= n * (n - 1) / 2
//
// Related Topics 数组 双指针 二分查找 排序 👍 282 👎 0

static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int getCount(int *nums, int size, int target) {
    int ans = 0;
    for (int i = 0, j = 0; i < size; ++i) {
        for (; j < size && nums[j] - nums[i] <= target; ++j) {}
        if (i == j) continue;
        ans += j - i - 1;
    }
    return ans;
}
int smallestDistancePair(int *nums, int size, int k) {
    qsort(nums, size, sizeof(int), cmp);

    int l = 0, r = nums[size - 1] - nums[0];
    for (int mid; l <= r;) {
        if (k <= getCount(nums, size, mid = (l + r) / 2)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
