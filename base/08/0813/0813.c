// 我们将给定的数组 A 分成 K
// 个相邻的非空子数组，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。
//
// 注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。
//
//
// 示例:
// 输入:
// A = [9,1,2,3,9]
// K = 3
// 输出: 20
// 解释:
// A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
// 我们也可以把 A 分成[9, 1], [2], [3, 9].
// 这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
//
//
// 说明:
//
//
// 1 <= A.length <= 100.
// 1 <= A[i] <= 10000.
// 1 <= K <= A.length.
// 答案误差在 10^-6 内被视为是正确的。
//
// Related Topics 动态规划
// 👍 110 👎 0

double largestSumOfAverages(int *arr, int size, int K) {
    double prefix[size], dp[size]; // dp[i][j] = max(dp[i-1][j-1] + arr[i], dp[i-2][j-1] + (arr[i-1] + arr[i]) / 2, ...)

    prefix[0] = dp[0] = arr[0];
    for (int i = 1; i < size; ++i) {
        prefix[i] = prefix[i - 1] + arr[i], dp[i] = prefix[i] / (i + 1);
    }

    for (int i = 1; i < K; ++i) {
        for (int j = size - 1; j >= i; --j) {
            dp[j] = dp[j - 1] + arr[j];
            for (int k = i - 1; k < j - 1; ++k) {
                double avg = (prefix[j] - prefix[k]) / (j - k);
                if (dp[j] < avg + dp[k]) dp[j] = avg + dp[k];
            }
        }
    }

    return dp[size - 1];
}
