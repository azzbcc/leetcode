// 给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形
// 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。
//
//
//
// 示例 1：
//
// 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：9
//
//
// 示例 2：
//
// 输入：grid = [[1,1,0,0]]
// 输出：1
//
//
//
//
// 提示：
//
//
// 1 <= grid.length <= 100
// 1 <= grid[0].length <= 100
// grid[i][j] 为 0 或 1
//
//
// Related Topics 数组 动态规划 矩阵 👍 175 👎 0

int largest1BorderedSquare(int **grid, int size, int *colSize) {
    int ans = 0;
    struct {
        int row, col;
    } dp[size + 1][*colSize + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            if (!grid[i][j]) continue;
            dp[i + 1][j + 1].row = dp[i + 1][j].row + 1, dp[i + 1][j + 1].col = dp[i][j + 1].col + 1;
            for (int k = fmin(dp[i + 1][j + 1].row, dp[i + 1][j + 1].col); k > ans; --k) {
                if (dp[i + 2 - k][j + 1].row >= k && dp[i + 1][j + 2 - k].col >= k) ans = fmax(ans, k);
            }
        }
    }
    return ans * ans;
}