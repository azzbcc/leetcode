// 给定一个整数数组 nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
//
//
//
// 示例 1：
//
//
// 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// 输出： True
// 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
//
// 示例 2:
//
//
// 输入: nums = [1,2,3,4], k = 3
// 输出: false
//
//
//
// 提示：
//
//
// 1 <= k <= len(nums) <= 16
// 0 < nums[i] < 10000
// 每个元素的频率在 [1,4] 范围内
//
//
// Related Topics 位运算 记忆化搜索 数组 动态规划 回溯 状态压缩 👍 753 👎 0

int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
bool canPartitionKSubsets(int *nums, int size, int k) {
    int sum = 0;
    qsort(nums, size, sizeof(int), cmp);
    for (int i = 0; i < size; sum += nums[i++]) {}
    if (sum % k || sum / k < nums[size - 1]) return false;

    int ss[1 << size];
    bool dp[1 << size];
    memset(ss, 0, sizeof(ss));
    memset(dp, false, sizeof(dp)), dp[0] = true;
    for (int mask = 0; mask < 1 << size; mask++) {
        if (!dp[mask]) continue;
        for (int i = 0; i < size; i++) {
            if ((mask >> i) & 1) continue;
            if (ss[mask] + nums[i] > sum / k) break;
            dp[mask | 1 << i] = true;
            ss[mask | 1 << i] = (ss[mask] + nums[i]) % (sum / k);
        }
    }
    return dp[(1 << size) - 1];
}