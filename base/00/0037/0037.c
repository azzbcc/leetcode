// 编写一个程序，通过已填充的空格来解决数独问题。
//
// 一个数独的解法需遵循如下规则：
//
//
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//
//
// 空白格用 '.' 表示。
//
//
//
// 一个数独。
//
//
//
// 答案被标成红色。
//
// Note:
//
//
// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。
//
// Related Topics 哈希表 回溯算法
// 👍 565 👎 0

bool square[3][3][10] = { false }, vertical[9][10] = { false }, horizontal[9][10] = { false };
bool dfs(char **board, int x, int y) {
    if (x >= 9) return true;
    int nx = x + (y == 8), ny = (y + 1) % 9;
    if (isdigit(board[x][y])) return dfs(board, nx, ny);

    for (int i = 1; i <= 9; ++i) {
        if (square[x / 3][y / 3][i]) continue;
        if (vertical[x][i]) continue;
        if (horizontal[y][i]) continue;

        board[x][y] = i + '0', square[x / 3][y / 3][i] = vertical[x][i] = horizontal[y][i] = true;
        if (dfs(board, nx, ny)) return true;
        board[x][y] = '.', square[x / 3][y / 3][i] = vertical[x][i] = horizontal[y][i] = false;
    }
    return false;
}
void solveSudoku(char **board, int boardSize, int *boardColSize) {
    memset(square, 0, sizeof(square));
    memset(vertical, 0, sizeof(vertical));
    memset(horizontal, 0, sizeof(horizontal));
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0, n; j < boardSize; ++j) {
            if (!isdigit(board[i][j])) continue;
            n = board[i][j] - '0', square[i / 3][j / 3][n] = vertical[i][n] = horizontal[j][n] = true;
        }
    }

    dfs(board, 0, 0);
}
