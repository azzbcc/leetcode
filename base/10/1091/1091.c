// 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。
//
// 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，
// 该路径同时满足下述要求：
//
//
// 路径途经的所有单元格都的值都是 0 。
// 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
//
//
// 畅通路径的长度 是该路径途经的单元格总数。
//
//
//
// 示例 1：
//
//
// 输入：grid = [[0,1],[1,0]]
// 输出：2
//
//
// 示例 2：
//
//
// 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
// 输出：4
//
//
// 示例 3：
//
//
// 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
// 输出：-1
//
//
//
//
// 提示：
//
//
// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] 为 0 或 1
//
//
// Related Topics 广度优先搜索 数组 矩阵 👍 272 👎 0

typedef struct {
    int x, y;
} point_t;
typedef struct {
    int step;
    point_t loc;
} node_t;
const point_t wards[] = { -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1 };
int shortestPathBinaryMatrix(int **grid, int size, int *colSize) {
    if (grid[0][0]) return -1;
    if (size == 1 && *colSize == 1) return 1;

    int front = 0, rear = 0;
    bool visited[size][*colSize];
    node_t queue[size * *colSize];

    memset(visited, false, sizeof(visited));
    for (visited[0][0] = true, queue[rear++] = (node_t) { 1, { 0, 0 } }; front < rear; ++front) {
        node_t cur = queue[front];
        if (grid[cur.loc.x][cur.loc.y]) continue;
        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            point_t next = (point_t) { cur.loc.x + wards[i].x, cur.loc.y + wards[i].y };
            if (next.x < 0 || next.x >= size || next.y < 0 || next.y >= *colSize) continue;
            if (visited[next.x][next.y] || grid[next.x][next.y]) continue;
            if (next.x == size - 1 && next.y == *colSize - 1) return cur.step + 1;
            visited[next.x][next.y] = true, queue[rear++] = (node_t) { cur.step + 1, next };
        }
    }
    return -1;
}
