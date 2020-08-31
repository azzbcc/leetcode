// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
// ？请你找出所有满足条件且不重复 的三元组。
//
// 注意：答案中不可以包含重复的三元组。
//
//
//
// 示例：
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
// Related Topics 数组 双指针
// 👍 2453 👎 0

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

int next(int *nums, int size, int now) {
    int cur = nums[now];
    while (++now < size && nums[now] == cur) {}
    return now;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int arr[0xffff][3] = { 0 }, len = 0, **ans = NULL;

    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(nums[0]), comp);
    for (int i = 0; i < numsSize - 2 && nums[i] <= 0; i = next(nums, numsSize, i)) {
        for (int j = i + 1, k = numsSize - 1; j < k; j = next(nums, k, j)) {
            while (j < k && nums[i] + nums[j] + nums[k] < 0) {
                j = next(nums, k, j);
            }
            while (j < k && nums[i] + nums[j] + nums[k] > 0) {
                int cur = nums[k];
                while (j < --k && nums[k] == cur) {}
            }
            if (j < k && nums[i] + nums[j] + nums[k] == 0) {
                arr[len][0] = nums[i];
                arr[len][1] = nums[j];
                arr[len][2] = nums[k];
                assert(len++ < 0xffff);
            }
        }
    }

    *returnSize = len;
    ans = calloc(len, sizeof(int *)), *returnColumnSizes = calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        (*returnColumnSizes)[i] = 3;

        ans[i] = calloc(3, sizeof(int));
        memcpy(ans[i], arr[i], 3 * sizeof(int));
    }
    return ans;
}
