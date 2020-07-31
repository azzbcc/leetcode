//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
//
// 示例 1:
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。
//
// 示例 2:
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。
// Related Topics 数学 动态规划
// 👍 293 👎 0
int max(int a, int b) {
    return a > b ? a : b;
}
int integerBreak(int n) {
    int arr[] = { 1, 2, 4 };
    if (n <= 4) return arr[n - 2];
    return 3 * max(integerBreak(n - 3), n - 3);
}