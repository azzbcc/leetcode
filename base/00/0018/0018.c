// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

int next(const int *nums, int size, int now) {
    int cur = nums[now];
    while (++now < size && nums[now] == cur) {}
    return now;
}
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {
    int arr[0xffff][4] = { 0 }, len = 0, **ans = NULL;

    if (numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(nums[0]), comp);
    for (int i = 0; i < numsSize - 3; i = next(nums, numsSize, i)) {
        for (int j = i + 1; j < numsSize - 2; j = next(nums, numsSize, j)) {
            for (int k = j + 1, l = numsSize - 1; k < l; k = next(nums, l, k)) {
                while (k < l && nums[i] + nums[j] + nums[k] + nums[l] < target) {
                    k = next(nums, l, k);
                }
                while (k < l && nums[i] + nums[j] + nums[k] + nums[l] > target) {
                    int cur = nums[l];
                    while (k < --l && nums[l] == cur) {}
                }
                if (k < l && nums[i] + nums[j] + nums[k] + nums[l] == target) {
                    arr[len][0] = nums[i];
                    arr[len][1] = nums[j];
                    arr[len][2] = nums[k];
                    arr[len][3] = nums[l];
                    assert(len++ < 0xffff);
                }
            }
        }
    }

    *returnSize = len;
    ans = calloc(len, sizeof(int *)), *returnColumnSizes = calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        (*returnColumnSizes)[i] = 4;

        ans[i] = calloc(4, sizeof(int));
        memcpy(ans[i], arr[i], 4 * sizeof(int));
    }
    return ans;
}