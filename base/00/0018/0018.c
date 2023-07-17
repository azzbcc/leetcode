// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
// 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
// 注意：
//
// 答案中不可以包含重复的四元组。
//
// 示例：
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
// 满足要求的四元组集合为：
// [
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
// ]
//
// Related Topics 数组 哈希表 双指针
// 👍 533 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int next(const int *nums, int size, int now) {
    for (int cur = nums[now]; ++now < size && nums[now] == cur;) {}
    return now;
}
int **fourSum(int *nums, int size, int target, int *returnSize, int **returnColumnSizes) {
    int arr[0xffff][4] = { 0 }, len = 0, **ans = NULL;
    if (size < 4) return malloc(*returnSize = 0);

    qsort(nums, size, sizeof(nums[0]), cmp);
    for (int i = 0; i < size - 3; i = next(nums, size, i)) {
        for (int j = i + 1; j < size - 2; j = next(nums, size, j)) {
            for (int k = j + 1, l = size - 1; k < l; k = next(nums, l, k)) {
                while (k < l && 0L + nums[i] + nums[j] + nums[k] + nums[l] < target) {
                    k = next(nums, l, k);
                }
                while (k < l && 0L + nums[i] + nums[j] + nums[k] + nums[l] > target) {
                    int cur = nums[l];
                    while (k < --l && nums[l] == cur) {}
                }
                if (k < l && nums[i] + nums[j] + nums[k] + nums[l] == target) {
                    arr[len][0] = nums[i], arr[len][1] = nums[j], arr[len][2] = nums[k], arr[len][3] = nums[l];
                    len += 1;
                }
            }
        }
    }

    ans = calloc(*returnSize = len, sizeof(int *)), *returnColumnSizes = calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        ans[i] = calloc((*returnColumnSizes)[i] = 4, sizeof(int));
        memcpy(ans[i], arr[i], 4 * sizeof(int));
    }
    return ans;
}