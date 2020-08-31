// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
//
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//
// 示例:
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
// 运行你的函数后，矩阵变为：
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//
// 解释:
//
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O'
// 相连的 'O' 最终都会被
// 填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// Related Topics 深度优先搜索 广度优先搜索 并查集
// 👍 296 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void dfs(char **board, int m, int n, point_t now) {
    if (now.x < 0 || now.x >= m || now.y < 0 || now.y >= n) return;
    if (board[now.x][now.y] != 'O') return;

    board[now.x][now.y] = '.';
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = now;
        next.x += wards[i].x;
        next.y += wards[i].y;

        dfs(board, m, n, next);
    }
}

void solve(char **board, int boardSize, int *boardColSize) {
    if (boardSize < 3 || !boardColSize || *boardColSize < 3) return;

    point_t start;
    for (int i = 0; i < boardSize + *boardColSize - 2; ++i) {
        if (i < boardSize) {
            start.x = i, start.y = 0;
        } else {
            start.x = boardSize - 1, start.y = i - boardSize + 1;
        }
        dfs(board, boardSize, *boardColSize, start);
        if (i < *boardColSize - 1) {
            start.x = 0, start.y = i + 1;
        } else {
            start.x = i - *boardColSize + 2, start.y = *boardColSize - 1;
        }
        dfs(board, boardSize, *boardColSize, start);
    }

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < *boardColSize; ++j) {
            board[i][j] = board[i][j] == '.' ? 'O' : 'X';
        }
    }
}
