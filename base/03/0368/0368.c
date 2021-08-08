// 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
// answer[j]) 都应当满足：
//
// answer[i] % answer[j] == 0 ，或
// answer[j] % answer[i] == 0
//
//
// 如果存在多个有效解子集，返回其中任何一个均可。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,3]
// 输出：[1,2]
// 解释：[1,3] 也会被视为正确答案。
//
//
// 示例 2：
//
//
// 输入：nums = [1,2,4,8]
// 输出：[1,2,4,8]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// nums 中的所有整数 互不相同
//
// Related Topics 数学 动态规划
// 👍 290 👎 0

typedef struct node {
    int count, val;
    struct node *next;
} node_t;
int cmp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;
    return *pa - *pb;
}
int *largestDivisibleSubset(int *nums, int size, int *returnSize) {
    node_t dp[size + 1], *pmax = &dp[size];

    dp[size] = (node_t) { 0 };
    qsort(nums, size, sizeof(int), cmp);

    for (int i = size - 1; i >= 0; --i) {
        dp[i] = (node_t) { 1, nums[i], &dp[size] };
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] % nums[i] != 0 || dp[i].count > dp[j].count) continue;
            dp[i].count = dp[j].count + 1, dp[i].next = &dp[j];
        }
        if (dp[i].count > pmax->count) pmax = &dp[i];
    }

    int *ans = malloc((*returnSize = pmax->count) * sizeof(int));
    for (int i = 0; pmax->next; ++i, pmax = pmax->next) {
        ans[i] = pmax->val;
    }
    return ans;
}
