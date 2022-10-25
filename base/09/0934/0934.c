// 给你一个大小为 n x n 的二元矩阵 grid ，其中 1 表示陆地，0 表示水域。
//
// 岛 是由四面相连的 1 形成的一个最大组，即不会与非组内的任何其他 1 相连。grid 中 恰好存在两座岛 。
//
//
//
// 你可以将任意数量的 0 变为 1 ，以使两座岛连接起来，变成 一座岛 。
//
//
//
// 返回必须翻转的 0 的最小数目。
//
//
//
// 示例 1：
//
//
// 输入：grid = [[0,1],[1,0]]
// 输出：1
//
//
// 示例 2：
//
//
// 输入：grid = [[0,1,0],[0,0,0],[0,0,1]]
// 输出：2
//
//
// 示例 3：
//
//
// 输入：grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// 输出：1
//
//
//
//
// 提示：
//
//
// n == grid.length == grid[i].length
// 2 <= n <= 100
// grid[i][j] 为 0 或 1
// grid 中恰有两个岛
//
//
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 328 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int bfs(int **grid, int size, point_t p) {
    int f = 0, r = 0;
    point_t queue[size * size], cur;

    // 第一座岛入队
    grid[p.x][p.y] = -1;
    for (queue[r++] = p; f < r; ++f) {
        cur = queue[f];
        for (int i = 0; i < sizeof(wards) / sizeof(point_t); ++i) {
            point_t next = (point_t) { cur.x + wards[i].x, cur.y + wards[i].y };
            if (next.x < 0 || next.x >= size || next.y < 0 || next.y >= size) continue;
            if (grid[next.x][next.y] != 1) continue;
            grid[next.x][next.y] = -1, queue[r++] = next;
        }
    }
    for (int ans = -2, i = 0, tr;; --ans) {
        for (tr = r; i < tr; ++i) {
            cur = queue[i];
            for (int j = 0; j < sizeof(wards) / sizeof(point_t); ++j) {
                point_t next = (point_t) { cur.x + wards[j].x, cur.y + wards[j].y };
                if (next.x < 0 || next.x >= size || next.y < 0 || next.y >= size) continue;
                if (grid[next.x][next.y] == 1) return -ans - 2;
                if (grid[next.x][next.y] != 0) continue;
                grid[next.x][next.y] = ans, queue[r++] = next;
            }
        }
    }
    return -1;
}
int shortestBridge(int **grid, int size, int *colSize) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j]) {
                return bfs(grid, size, (point_t) { i, j });
            }
        }
    }
    return -1;
}
