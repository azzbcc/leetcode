// 给你一个二维整数数组 queries ，其中 queries[i] = [ni, ki] 。第 i 个查询 queries[i] 要求构造长度为 ni 、每
// 个元素都是正整数的数组，且满足所有元素的乘积为 ki ，请你找出有多少种可行的方案。由于答案可能会很大，方案数需要对 109
// + 7 取余 。
//
// 请你返回一个整数数组 answer，满足 answer.length == queries.length ，其中 answer[i]是第 i 个查询的结果。
//
//
//
// 示例 1：
//
//
// 输入：queries = [[2,6],[5,1],[73,660]]
// 输出：[4,1,50734910]
// 解释：每个查询之间彼此独立。
// [2,6]：总共有 4 种方案得到长度为 2 且乘积为 6 的数组：[1,6]，[2,3]，[3,2]，[6,1]。
// [5,1]：总共有 1 种方案得到长度为 5 且乘积为 1 的数组：[1,1,1,1,1]。
// [73,660]：总共有 1050734917 种方案得到长度为 73 且乘积为 660 的数组。1050734917 对 109 + 7 取余得到 50734910 。
//
//
// 示例 2 ：
//
//
// 输入：queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
// 输出：[1,2,3,10,5]
//
//
//
//
// 提示：
//
//
// 1 <= queries.length <= 104
// 1 <= ni, ki <= 104
//
// Related Topics 数学
// 👍 5 👎 0

#define MOD  1000000007
#define MAXN 10020

int dp[MAXN + 1][MAXN + 1];
int C(int m, int n) {
    if (m - n < n) return C(m, m - n);
    if (dp[m][n]) return dp[m][n];
    if (n == 0) return dp[m][n] = 1;
    if (n == 1) return dp[m][n] = m;
    return dp[m][n] = (C(m - 1, n - 1) + C(m - 1, n)) % MOD;
}
int count(int n, int mul) {
    int ans = 1;
    for (int i = 2, cur; i <= mul; ++i) {
        if (mul % i) continue;
        for (cur = 0; mul % i == 0; cur++, mul /= i) {}
        ans = ( long )ans * C(n + cur - 1, cur) % MOD;
    }
    return ans;
}
int *waysToFillArray(int **queries, int size, int *colSize, int *returnSize) {
    int *ans = malloc((*returnSize = size) * sizeof(int));
    for (int i = 0; i < size; i++) {
        ans[i] = count(queries[i][0], queries[i][1]);
    }
    return ans;
}