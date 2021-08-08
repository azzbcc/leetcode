//给定一个整数矩阵，找出最长递增路径的长度。
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
//
// 示例 1:
//
// 输入: nums =
//[
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//]
//输出: 4
//解释: 最长递增路径为 [1, 2, 6, 9]。
//
// 示例 2:
//
// 输入: nums =
//[
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//]
//输出: 4
//解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
//
// Related Topics 深度优先搜索 拓扑排序 记忆化
// 👍 315 👎 0

typedef struct {
    int x, y;
} point_t;

const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int dfs(int **matrix, int X, int Y, int **map, point_t now) {
    if (map[now.x][now.y]) return map[now.x][now.y];

    int max = 0;
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = { now.x + wards[i].x, now.y + wards[i].y };

        if (next.x < 0 || next.x >= X) continue;
        if (next.y < 0 || next.y >= Y) continue;
        if (matrix[next.x][next.y] <= matrix[now.x][now.y]) continue;

        map[next.x][next.y] = dfs(matrix, X, Y, map, next);
        if (max < map[next.x][next.y]) max = map[next.x][next.y];
    }
    return map[now.x][now.y] = max + 1;
}
int longestIncreasingPath(int **matrix, int matrixSize, int *matrixColSize) {
    int ans = 0, **map = calloc(matrixSize, sizeof(int *));

    for (int i = 0; i < matrixSize; ++i) {
        map[i] = calloc(*matrixColSize, sizeof(int));
        memset(map[i], 0, *matrixColSize * sizeof(int));
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            int tmp = dfs(matrix, matrixSize, *matrixColSize, map, (point_t) { i, j });
            if (ans < tmp) ans = tmp;
        }
    }

    for (int i = 0; i < matrixSize; ++i) {
        free(map[i]);
    }
    free(map);

    return ans;
}
