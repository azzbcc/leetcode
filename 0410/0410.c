//给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m
//个子数组各自和的最大值最小。
//
// 注意:
//数组长度 n 满足以下条件:
//
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
//
// 示例:
//
//
//输入:
// nums = [7,2,5,10,8]
// m = 2
//
//输出:
// 18
//
//解释:
//一共有四种方法将nums分割为2个子数组。
//其中最好的方式是将其分为[7,2,5] 和 [10,8]，
//因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
//
// Related Topics 二分查找 动态规划
// 👍 254 👎 0

#define MAXN      1000
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)

// a  up  array
// b down array
long bs(long a[], long b[], int beg, int end) {
    if (beg >= end) return MAX(a[end], b[end]);
    if (a[beg] > b[beg]) return a[beg];
    if (a[end] < b[end]) return b[end];

    while (beg < end) {
        int mid = (beg + end) / 2;
        if (mid == beg) break;

        if (a[mid] == b[mid]) return a[mid];
        if (a[mid] < b[mid]) beg = mid;
        if (a[mid] > b[mid]) end = mid;
    }
    return MIN(a[end], b[beg]);
}

// dp[i][j] = min( max(dp[i-1][j-1], num[j]), ..., max(dp[i-1][i-1], num[i...j]) )
int splitArray(int *nums, int numsSize, int m) {
    long dp[MAXN + 1]     = { 0 };
    long sums[MAXN][MAXN] = { 0 }; // sums[i][j] = sum(num[j...i])

    // data initial
    for (int i = 0; i < numsSize; ++i) {
        sums[i][i] = nums[i];
        for (int j = i - 1; j >= 0; --j) {
            sums[i][j] = sums[i][j + 1] + nums[j];
        }
        dp[i + 1] = sums[i][0];
    }

    // calculate
    for (int i = 1; i < m - 1; ++i) {
        for (int j = numsSize; j > i; --j) {
            dp[j] = bs(dp, sums[j - 1], i, j - 1);
        }
    }
    if (m > 1) {
        return bs(dp, sums[numsSize - 1], m - 1, numsSize - 1);
    } else {
        return dp[numsSize];
    }
}
