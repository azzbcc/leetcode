// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。
//
// 说明：m 和 n 的值均不超过 100。
//
// 示例 1:
//
// 输入:
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// 输出: 2
// 解释:
// 3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
//  1. 向右 -> 向右 -> 向下 -> 向下
//  2. 向下 -> 向下 -> 向右 -> 向右
//
// Related Topics 数组 动态规划
// 👍 396 👎 0

int uniquePathsWithObstacles(int **grid, int size, int *colSize) {
    if (grid[0][0]) return 0;

    int dp[*colSize];
    for (int i = 0, val = 1; i < *colSize; dp[i++] = val) {
        if (grid[0][i] == 1) val = 0;
    }
    for (int i = 1; i < size; ++i) {
        if (grid[i][0]) dp[0] = 0;
        for (int j = 1; j < *colSize; ++j) {
            dp[j] = grid[i][j] ? 0 : dp[j] + dp[j - 1];
        }
    }

    return dp[*colSize - 1];
}
