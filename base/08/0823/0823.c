// 给出一个含有不重复整数元素的数组 arr ，每个整数 arr[i] 均大于 1。
//
// 用这些整数来构建二叉树，每个整数可以使用任意次数。其中：每个非叶结点的值应等于它的两个子结点的值的乘积。
//
// 满足条件的二叉树一共有多少个？答案可能很大，返回 对 10⁹ + 7 取余 的结果。
//
//
//
// 示例 1:
//
//
// 输入: arr = [2, 4]
// 输出: 3
// 解释: 可以得到这些二叉树: [2], [4], [4, 2, 2]
//
// 示例 2:
//
//
// 输入: arr = [2, 4, 5, 10]
// 输出: 7
// 解释: 可以得到这些二叉树: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 1000
// 2 <= arr[i] <= 10⁹
// arr 中的所有值 互不相同
//
//
// Related Topics 数组 哈希表 动态规划 排序 👍 146 👎 0

#define MOD 1000000007
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int numFactoredBinaryTrees(int *arr, int size) {
    int ans = 0, dp[size];

    memset(dp, 0, sizeof(dp));
    qsort(arr, size, sizeof(int), cmp);
    for (int i = 0; i < size; dp[i++] = 1) {}
    for (int i = 0; i < size; ans = (ans + dp[i++]) % MOD) {
        for (int l = 0, r = i - 1; l <= r; ++l) {
            for (; l <= r && 1L * arr[l] * arr[r] < arr[i]; ++l) {}
            for (; l <= r && 1L * arr[l] * arr[r] > arr[i]; --r) {}
            if (l > r || 1L * arr[l] * arr[r] != arr[i]) continue;
            if (l == r) {
                dp[i] = (1L * dp[l] * dp[r] + dp[i]) % MOD;
            } else {
                dp[i] = (2L * dp[l] * dp[r] + dp[i]) % MOD;
            }
        }
    }
    return ans;
}
