// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
// 说明：解集不能包含重复的子集。
//
// 示例:
//
// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
// Related Topics 位运算 数组 回溯算法
// 👍 788 👎 0
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int res[numsSize], **ans;

    *returnSize        = 0x1U << numsSize;
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    ans                = calloc(*returnSize, sizeof(int *));
    for (size_t r = 0; r < 0x1U << numsSize; ++r) {
        size_t count = 0;
        for (size_t i = 0; i < numsSize; ++i) {
            if (0x1U << i & r) res[count++] = nums[i];
        }
        (*returnColumnSizes)[r] = count;
        ans[r]                  = calloc(count, sizeof(int));
        memcpy(ans[r], res, count * sizeof(int));
    }

    return ans;
}
