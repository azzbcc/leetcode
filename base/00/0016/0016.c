// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
//
// 返回这三个数的和。
//
// 假定每组输入只存在恰好一个解。
//
//
//
// 示例 1：
//
//
// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
//
//
// 示例 2：
//
//
// 输入：nums = [0,0,0], target = 1
// 输出：0
//
//
//
//
// 提示：
//
//
// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -10⁴ <= target <= 10⁴
//
//
// Related Topics 数组 双指针 排序 👍 1450 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int next(int *nums, int size, int now) {
    for (int cur = nums[now]; ++now < size && nums[now] == cur;) {}
    return now;
}
int threeSumClosest(int *nums, int size, int target) {
    int ans = nums[0] + nums[1] + nums[2];
    qsort(nums, size, sizeof(nums[0]), cmp);
    for (int i = 0; i < size - 2; i = next(nums, size, i)) {
        for (int j = i + 1, k = size - 1; j < k; j = next(nums, k, j)) {
            for (; j < k && nums[i] + nums[j] + nums[k] < target; j = next(nums, k, j)) {}
            if (j <= k && j > i + 1) {
                int cur = nums[i] + nums[j - 1] + nums[k];
                if (abs(target - cur) < abs(target - ans)) ans = cur;
            }
            for (; j < k && nums[i] + nums[j] + nums[k] > target;) {
                for (int cur = nums[k]; j < --k && nums[k] == cur;) {}
            }
            if (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - ans)) ans = cur;
                if (ans == target) return ans;
            }
            if (j <= k && k < size - 1) {
                int cur = nums[i] + nums[j] + nums[k + 1];
                if (abs(target - cur) < abs(target - ans)) ans = cur;
            }
        }
    }
    return ans;
}
