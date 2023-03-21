// 给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
//
// 返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度。
//
// 子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
//
//
//
// 示例 1：
//
//
// 输入：nums = [4,5,2,1], queries = [3,10,21]
// 输出：[2,3,4]
// 解释：queries 对应的 answer 如下：
// - 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
// - 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
// - 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
//
//
// 示例 2：
//
//
// 输入：nums = [2,3,4,5], queries = [1]
// 输出：[0]
// 解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
//
//
//
// 提示：
//
//
// n == nums.length
// m == queries.length
// 1 <= n, m <= 1000
// 1 <= nums[i], queries[i] <= 10⁶
//
//
// Related Topics 贪心 数组 二分查找 前缀和 排序 👍 112 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int index_of(int arr[], int size, int key) {
    int r = size - 1;
    for (int l = 0, mid; l <= r;) {
        mid = (l + r) / 2;
        if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize, int *returnSize) {
    int sum[numsSize + 1];
    int *ans = malloc((*returnSize = queriesSize) * sizeof(int));

    sum[0] = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; sum[i + 1] = sum[i] + nums[i], ++i) {}
    for (int i = 0; i < queriesSize; ++i) {
        ans[i] = index_of(sum, numsSize + 1, queries[i]);
    }
    return ans;
}