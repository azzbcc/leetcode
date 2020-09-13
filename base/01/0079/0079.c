//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//
//
// 示例:
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false
//
//
//
// 提示：
//
//
// board 和 word 中只包含大写和小写英文字母。
// 1 <= board.length <= 200
// 1 <= board[i].length <= 200
// 1 <= word.length <= 10^3
//
// Related Topics 数组 回溯算法
// 👍 595 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
bool dfs(char **board, int m, int n, char *word, point_t now, bool visited[m][n]) {
    if (!*word) return true;
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = { now.x + wards[i].x, now.y + wards[i].y };
        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
        if (visited[next.x][next.y] || board[next.x][next.y] != *word) continue;
        visited[next.x][next.y] = true;
        if (dfs(board, m, n, word + 1, next, visited)) return true;
        visited[next.x][next.y] = false;
    }
    return false;
}
bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    bool visited[boardSize][*boardColSize];
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < *boardColSize; ++j) {
            if (board[i][j] != *word) continue;
            memset(visited, 0, sizeof(visited));
            visited[i][j] = true;
            if (dfs(board, boardSize, *boardColSize, word + 1, (point_t) { i, j }, visited)) return true;
        }
    }
    return false;
}
