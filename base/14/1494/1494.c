// 给你一个整数 n 表示某所大学里课程的数目，编号为 1 到 n ，数组 relations 中，
// relations[i] = [xi, yi] 表示一个先修课的关系，也就是课程 xi 必须在课程 yi 之前上。同时你还有一个整数 k 。
//
// 在一个学期中，你 最多 可以同时上 k 门课，前提是这些课的先修课在之前的学期里已经上过了。
//
// 请你返回上完所有课最少需要多少个学期。题目保证一定存在一种上完所有课的方式。
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
// 输出：3
// 解释：上图展示了题目输入的图。在第一个学期中，我们可以上课程 2 和课程 3 。然后第二个学期上课程 1 ，第三个学期上课程 4
// 。
//
//
// 示例 2：
//
//
//
//
// 输入：n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
// 输出：4
// 解释：上图展示了题目输入的图。一个最优方案是：第一学期上课程 2 和 3，第二学期上课程 4 ，
// 第三学期上课程 1，第四学期上课程 5 。
//
//
// 示例 3：
//
//
// 输入：n = 11, relations = [], k = 2
// 输出：6
//
//
//
//
// 提示：
//
//
// 1 <= n <= 15
// 1 <= k <= n
// 0 <= relations.length <= n * (n-1) / 2
// relations[i].length == 2
// 1 <= xi, yi <= n
// xi != yi
// 所有先修关系都是不同的，也就是说 relations[i] != relations[j] 。
// 题目输入的图是个有向无环图。
//
//
// Related Topics 位运算 图 动态规划 状态压缩 👍 146 👎 0

int minNumberOfSemesters(int n, int **relations, int size, int *colSize, int k) {
    int dep[n], dp[0x1 << n], mask = (0x1 << n) - 1;

    memset(dep, 0, sizeof(dep));
    memset(dp, 0x7f, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        dep[relations[i][1] - 1] |= 0x1 << (relations[i][0] - 1);
    }

    dp[0] = 0;
    for (int state = 0, next; next = 0, state <= mask; state++) {
        if (dp[state] == 0x7f7f7f7f) continue;
        for (int i = 0; i < n; i++) {
            if ((state & dep[i]) == dep[i]) next |= 1 << i;
        }
        next &= ~state;
        for (int sub = next; sub; sub = (sub - 1) & next) {
            if (__builtin_popcount(sub) > k) continue;
            dp[state | sub] = fmin(dp[state | sub], dp[state] + 1);
        }
    }
    return dp[mask];
}