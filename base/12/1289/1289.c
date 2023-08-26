// 给你一个 n x n 整数矩阵 grid ，请你返回 非零偏移下降路径 数字和的最小值。
//
// 非零偏移下降路径 定义为：从 grid 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。
//
//
//
// 示例 1：
//
//
//
//
// 输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：13
// 解释：
// 所有非零偏移下降路径包括：
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// 下降路径中数字和最小的是[1,5,7] ，所以答案是13 。
//
//
// 示例 2：
//
//
// 输入：grid = [[7]]
// 输出：7
//
//
//
//
// 提示：
//
//
// n == grid.length == grid[i].length
// 1 <= n <= 200
// -99 <= grid[i][j] <= 99
//
//
// Related Topics 数组 动态规划 矩阵 👍 185 👎 0

typedef struct {
    int val[2], index;
} node_t;
int minFallingPathSum(int **grid, int size, int *colSize) {
    node_t ans = { .index = -1 }, tmp;
    for (int i = 0; i < size; ++i, ans = tmp) {
        tmp = (node_t) { { INT32_MAX, INT32_MAX }, -1 };
        for (int j = 0, val; j < size; ++j) {
            val = grid[i][j] + ans.val[ans.index == j];
            if (val < tmp.val[0]) {
                tmp.val[1] = tmp.val[0], tmp.val[0] = val, tmp.index = j;
            } else if (val < tmp.val[1]) {
                tmp.val[1] = val;
            }
        }
    }
    return ans.val[0];
}