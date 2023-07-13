// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
//
// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
// 在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
// 具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
// 输出：13
// 解释：如图所示，为和最小的两条下降路径
//
//
// 示例 2：
//
//
//
//
// 输入：matrix = [[-19,57],[-40,-5]]
// 输出：-59
// 解释：如图所示，为和最小的下降路径
//
//
//
//
// 提示：
//
//
// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100
//
//
// Related Topics 数组 动态规划 矩阵 👍 271 👎 0

int min(int *arr, int size) {
    int ans = arr[0];
    for (int i = 1; i < size; ans = fmin(ans, arr[i++])) {}
    return ans;
}
int minFallingPathSum(int **matrix, int size, int *colSize) {
    int dp[2][size + 2], cur = 1;
    memset(dp, 0x7f, sizeof(dp));
    for (int i = 0; i < size; dp[0][i + 1] = matrix[0][i], ++i) {}
    for (int i = 1; i < size; ++i, cur = 1 - cur) {
        for (int j = 0; j < size; ++j) {
            dp[cur][j + 1] = matrix[i][j] + min(&dp[1 - cur][j], 3);
        }
    }
    return min(&dp[1 - cur][1], size);
}
