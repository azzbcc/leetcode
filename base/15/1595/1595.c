// 给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >= size2 。
//
// 任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，
// 其中 cost[i][j] 是第一组中的点 i 和第二组中的点 j 的连接成本。
// 如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。
// 换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。
//
// 返回连通两组点所需的最小成本。
//
//
//
// 示例 1：
//
//
//
// 输入：cost = [[15, 96], [36, 2]]
// 输出：17
// 解释：连通两组点的最佳方法是：
// 1--A
// 2--B
// 总成本为 17 。
//
//
// 示例 2：
//
//
//
// 输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
// 输出：4
// 解释：连通两组点的最佳方法是：
// 1--A
// 2--B
// 2--C
// 3--A
// 最小成本为 4 。
// 请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A
// ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。
//
// 示例 3：
//
// 输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
// 输出：10
//
//
//
//
// 提示：
//
//
// size1 == cost.length
// size2 == cost[i].length
// 1 <= size1, size2 <= 12
// size1 >= size2
// 0 <= cost[i][j] <= 100
//
//
// Related Topics 位运算 数组 动态规划 状态压缩 矩阵 👍 109 👎 0

int connectTwoGroups(int **cost, int size, int *colSize) {
    int m = 0x1 << *colSize, dp[m];

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0, tmp[m]; i < size; ++i) {
        for (int mask = 0; mask < m; ++mask) {
            tmp[mask] = 0x3fffffff;
            for (int j = 0; j < *colSize; ++j) {
                if (!(0x1 << j & mask)) continue;
                tmp[mask] = fmin(tmp[mask], tmp[mask ^ (1 << j)] + cost[i][j]);
                tmp[mask] = fmin(tmp[mask], dp[mask] + cost[i][j]);
                tmp[mask] = fmin(tmp[mask], dp[mask ^ (1 << j)] + cost[i][j]);
            }
        }
        memcpy(dp, tmp, sizeof(dp));
    }
    return dp[m - 1];
}