// 给你一个大小为 rows x cols 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。
//
// 在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，找出具有 最大非负积
// 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。
//
// 返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为负数，则返回 -1 。
//
// 注意，取余是在得到最大积之后执行的。
//
//
//
// 示例 1：
//
// 输入：grid = [[-1,-2,-3],
//             [-2,-3,-3],
//             [-3,-3,-2]]
// 输出：-1
// 解释：从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1
//
//
// 示例 2：
//
// 输入：grid = [[1,-2,1],
//             [1,-2,1],
//             [3,-4,1]]
// 输出：8
// 解释：最大非负积对应的路径已经用粗体标出 (1 * 1 * -2 * -4 * 1 = 8)
//
//
// 示例 3：
//
// 输入：grid = [[1, 3],
//             [0,-4]]
// 输出：0
// 解释：最大非负积对应的路径已经用粗体标出 (1 * 0 * -4 = 0)
//
//
// 示例 4：
//
// 输入：grid = [[ 1, 4,4,0],
//             [-2, 0,0,1],
//             [ 1,-1,1,1]]
// 输出：2
// 解释：最大非负积对应的路径已经用粗体标出 (1 * -2 * 1 * -1 * 1 * 1 = 2)
//
//
//
//
// 提示：
//
//
// 1 <= rows, cols <= 15
// -4 <= grid[i][j] <= 4
//
// Related Topics 贪心算法 动态规划
// 👍 12 👎 0
#define MOD 1000000007
typedef struct {
    int c;
    int64_t d[3];
} node_t;
int maxProductPath(int **grid, int gridSize, int *gridColSize) {
    node_t dp[*gridColSize], *ans = &dp[*gridColSize - 1];

    dp[0] = (node_t) { .c = 1, .d[0] = grid[0][0] };
    for (int i = 1; i < *gridColSize; ++i) {
        dp[i].c = 1, dp[i].d[0] = grid[0][i] * dp[i - 1].d[0];
    }
    for (int i = 1; i < gridSize; ++i) {
        dp[0].d[0] *= grid[i][0];
        for (int j = 1; j < *gridColSize; ++j) {
            int64_t c = 0, d[dp[j - 1].c + dp[j].c], cur = grid[i][j];
            for (int k = 0; k < dp[j - 1].c; ++k) {
                d[c++] = cur * dp[j - 1].d[k];
            }
            for (int k = 0; k < dp[j].c; ++k) {
                d[c++] = cur * dp[j].d[k];
            }

            dp[j].c = 0;
            for (int k = 0, negative = -1, positive = -1, zero = -1; k < c; ++k) {
                if (!d[k]) {
                    if (zero < 0) dp[j].d[zero = dp[j].c++] = 0;
                } else if (d[k] < 0) {
                    if (negative < 0) {
                        dp[j].d[negative = dp[j].c++] = d[k];
                    } else {
                        if (dp[j].d[negative] > d[k]) dp[j].d[negative] = d[k];
                    }
                } else {
                    if (positive < 0) {
                        dp[j].d[positive = dp[j].c++] = d[k];
                    } else {
                        if (dp[j].d[positive] < d[k]) dp[j].d[positive] = d[k];
                    }
                }
            }
        }
    }

    int64_t max = -1;
    for (int i = 0; i < ans->c; ++i) {
        if (max < ans->d[i]) max = ans->d[i];
    }

    return max % MOD;
}
