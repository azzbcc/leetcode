// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋”
// 处于大陆的右边界和下边界。
//
// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
// 上单元格 高于海平面的高度 。
//
// 岛上雨水较多，如果相邻单元格的高度
// 小于或等于当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
//
// 返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋。
//
//
//
//  示例 1：
//
//
//
//
// 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
//
//
//  示例 2：
//
//
// 输入: heights = [[2,1],[1,2]]
// 输出: [[0,0],[0,1],[1,0],[1,1]]
//
//
//
//
//  提示：
//
//
//  m == heights.length
//  n == heights[r].length
//  1 <= m, n <= 200
//  0 <= heights[r][c] <= 10⁵
//
//  Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 414 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
void dfs(int **heights, int m, int n, bool map[m][n], point_t cur) {
    if (map[cur.x][cur.y]) return;
    map[cur.x][cur.y] = true;
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = (point_t) { cur.x + wards[i].x, cur.y + wards[i].y };
        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
        if (heights[next.x][next.y] < heights[cur.x][cur.y]) continue;
        dfs(heights, m, n, map, next);
    }
}
int **pacificAtlantic(int **heights, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    int m = size, n = *colSize, *help[m * n], len = 0;
    bool map[2][m][n];
    memset(map, 0, sizeof(map));
    for (int i = 0; i < m; ++i) {
        dfs(heights, m, n, map[0], (point_t) { i, 0 });
        dfs(heights, m, n, map[1], (point_t) { i, n - 1 });
    }
    for (int i = 0; i < n; ++i) {
        dfs(heights, m, n, map[0], (point_t) { 0, i });
        dfs(heights, m, n, map[1], (point_t) { m - 1, i });
    }
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (!map[0][x][y] || !map[1][x][y]) continue;
            help[len]    = malloc(2 * sizeof(int));
            help[len][0] = x, help[len][1] = y;
            len++;
        }
    }

    int **ans          = malloc((*returnSize = len) * sizeof(int *));
    *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0; i < len; returnColumnSizes[0][i++] = 2) {}
    memcpy(ans, help, len * sizeof(int *));
    return ans;
}
