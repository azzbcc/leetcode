// 给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回
// true 。
//
// 井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。
//
// 以下是井字游戏的规则：
//
//
// 玩家轮流将字符放入空位（' '）中。
// 玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
// 'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
// 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
// 当所有位置非空时，也算为游戏结束。
// 如果游戏结束，玩家不允许再放置字符。
//
//
//
//
// 示例 1：
//
//
// 输入：board = ["O  ","   ","   "]
// 输出：false
// 解释：玩家 1 总是放字符 "X" 。
//
//
// 示例 2：
//
//
// 输入：board = ["XOX"," X ","   "]
// 输出：false
// 解释：玩家应该轮流放字符。
//
// 示例 3：
//
//
// 输入：board = ["XXX","   ","OOO"]
// 输出：false
//
//
// Example 4:
//
//
// 输入：board = ["XOX","O O","XOX"]
// 输出：true
//
//
//
//
// 提示：
//
//
// board.length == 3
// board[i].length == 3
// board[i][j] 为 'X'、'O' 或 ' '
//
// Related Topics 数组 字符串 👍 64 👎 0

bool validTicTacToe(char **board, int size) {
    int lx = 0, lo = 0;
    lx += board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X';
    lx += board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X';
    lo += board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O';
    lo += board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O';
    for (int i = 0; i < size; ++i) {
        lx += board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X';
        lx += board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X';
        lo += board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O';
        lo += board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O';
    }
    if (lx && lo) return false;

    int cx = 0, co = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cx += board[i][j] == 'X';
            co += board[i][j] == 'O';
        }
    }
    if (lx && cx != co + 1) return false;
    if (lo && cx != co) return false;
    if (cx < co || cx > co + 1) return false;

    return true;
}