// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
// 最接近。返回这三个数的和 。假定每组输入只存在唯一答案。
//
//
//
// 示例：
//
// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
//
//
//
//
// 提示：
//
//
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4
//
// Related Topics 数组 双指针
// 👍 530 👎 0
int comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int next(int *nums, int size, int now) {
    int cur = nums[now];
    while (++now < size && nums[now] == cur) {}
    return now;
}
int threeSumClosest(int *nums, int numsSize, int target) {
    int ans = nums[0] + nums[1] + nums[2];
    qsort(nums, numsSize, sizeof(nums[0]), comp);
    for (int i = 0; i < numsSize - 2; i = next(nums, numsSize, i)) {
        for (int j = i + 1, k = numsSize - 1; j < k; j = next(nums, k, j)) {
            while (j < k && nums[i] + nums[j] + nums[k] < target) {
                j = next(nums, k, j);
            }
            if (j <= k && j > i + 1) {
                int cur = nums[i] + nums[j - 1] + nums[k];
                if (abs(target - cur) < abs(target - ans)) { ans = cur; }
            }
            while (j < k && nums[i] + nums[j] + nums[k] > target) {
                int cur = nums[k];
                while (j < --k && nums[k] == cur) {}
            }
            if (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - ans)) { ans = cur; }
                if (ans == target) return ans;
            }
            if (j <= k && k < numsSize - 1) {
                int cur = nums[i] + nums[j] + nums[k + 1];
                if (abs(target - cur) < abs(target - ans)) { ans = cur; }
            }
        }
    }
    return ans;
}
