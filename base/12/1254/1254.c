// 二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，
// 封闭岛是一个 完全 由1包围（左、上、右、下）的岛。
//
// 请返回 封闭岛屿 的数目。
//
//
//
// 示例 1：
//
//
//
//
// 输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// 输出：2
// 解释：
// 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
//
// 示例 2：
//
//
//
//
// 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// 输出：1
//
//
// 示例 3：
//
//
// 输入：grid = [[1,1,1,1,1,1,1],
//              [1,0,0,0,0,0,1],
//              [1,0,1,1,1,0,1],
//              [1,0,1,0,1,0,1],
//              [1,0,1,1,1,0,1],
//              [1,0,0,0,0,0,1],
//              [1,1,1,1,1,1,1]]
// 输出：2
//
//
//
//
// 提示：
//
//
// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1
//
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 216 👎 0

bool dfs(int m, int n, int **grid, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (grid[x][y]) return true;
    grid[x][y] = -1;

    bool flags[] = { dfs(m, n, grid, x - 1, y), dfs(m, n, grid, x, y - 1),
                     dfs(m, n, grid, x + 1, y), dfs(m, n, grid, x, y + 1) };
    return flags[0] && flags[1] && flags[2] && flags[3];
}
int closedIsland(int **grid, int size, int *colSize) {
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            if (grid[i][j]) continue;
            ans += dfs(size, *colSize, grid, i, j);
        }
    }
    return ans;
}
