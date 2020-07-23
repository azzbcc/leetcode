//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
// 说明：每次只能向下或者向右移动一步。
//
// 示例:
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
//
// Related Topics 数组 动态规划
// 👍 582 👎 0

int min(int a, int b) {
    return a < b ? a : b;
}

int minPathSum(int **grid, int gridSize, int *gridColSize) {
    for (int i = 1; i < gridSize; ++i) {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < *gridColSize; ++i) {
        grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < gridSize; ++i) {
        for (int j = 1; j < *gridColSize; ++j) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[gridSize - 1][*gridColSize - 1];
}