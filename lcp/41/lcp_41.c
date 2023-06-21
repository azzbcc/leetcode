// 在 `n*m` 大小的棋盘中，有黑白两种棋子，黑棋记作字母 `"X"`, 白棋记作字母 `"O"`，空余位置记作 `"."`。
// 当落下的棋子与其他相同颜色的棋子在行、列或对角线完全包围（中间不存在空白位置）另一种颜色的棋子，则可以翻转这些棋子的颜色。
//
// ![1.gif](https://pic.leetcode-cn.com/1630396029-eTgzpN-6da662e67368466a96d203f67bb6e793.gif){:height=170px}
// ![2.gif](https://pic.leetcode-cn.com/1630396240-nMvdcc-8e4261afe9f60e05a4f740694b439b6b.gif){:height=170px}
// ![3.gif](https://pic.leetcode-cn.com/1630396291-kEtzLL-6fcb682daeecb5c3f56eb88b23c81d33.gif){:height=170px}
//
// 「力扣挑战赛」黑白翻转棋项目中，将提供给选手一个未形成可翻转棋子的棋盘残局，其状态记作 `chessboard`。
// 若下一步可放置一枚黑棋，请问选手最多能翻转多少枚白棋。
//
// **注意：**
// - 若翻转白棋成黑棋后，棋盘上仍存在可以翻转的白棋，将可以 **继续** 翻转白棋
// - 输入数据保证初始棋盘状态无可以翻转的棋子且存在空余位置
//
// **示例 1：**
//
// > 输入：`chessboard = ["....X.","....X.","XOOO..","......","......"]`
// >
// > 输出：`3`
// >
// > 解释：
// > 可以选择下在 `[2,4]` 处，能够翻转白方三枚棋子。
//
// **示例 2：**
//
// > 输入：`chessboard = [".X.",".O.","XO."]`
// >
// > 输出：`2`
// >
// > 解释：
// > 可以选择下在 `[2,2]` 处，能够翻转白方两枚棋子。
// >
// ![2126c1d21b1b9a9924c639d449cc6e65.gif](https://pic.leetcode-cn.com/1626683255-OBtBud-2126c1d21b1b9a9924c639d449cc6e65.gif)
//
// **示例 3：**
//
// > 输入：`chessboard = [".......",".......",".......","X......",".O.....","..O....","....OOX"]`
// >
// > 输出：`4`
// >
// > 解释：
// > 可以选择下在 `[6,3]` 处，能够翻转白方四枚棋子。
// >
// ![803f2f04098b6174397d6c696f54d709.gif](https://pic.leetcode-cn.com/1630393770-Puyked-803f2f04098b6174397d6c696f54d709.gif)
//
// **提示：**
// - `1 <= chessboard.length, chessboard[i].length <= 8`
// - `chessboard[i]` 仅包含 `"."、"O"` 和 `"X"`
//
// Related Topics 广度优先搜索 数组 矩阵 👍 51 👎 0

typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
bool valid(int m, int n, char map[m][n], point_t now, point_t ward) {
    for (;;) {
        now.x += ward.x, now.y += ward.y;
        if (0 > now.x || now.x >= m || 0 > now.y || now.y >= n) break;
        if (map[now.x][now.y] == 'X') return true;
        if (map[now.x][now.y] == '.') return false;
    }
    return false;
}
int dfs(int m, int n, char **board, point_t start) {
    int ans = 0;
    char map[m][n];
    point_t queue[m * n];
    for (int i = 0; i < m; ++i) {
        memcpy(map[i], board[i], n * sizeof(char));
    }

    queue[0] = start, map[start.x][start.y] = 'X';
    for (int front = 0, rear = 1; front < rear; ++front) {
        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            if (!valid(m, n, map, queue[front], wards[i])) continue;
            point_t next = { queue[front].x + wards[i].x, queue[front].y + wards[i].y };
            for (; map[next.x][next.y] != 'X'; ++ans) {
                queue[rear++] = next, map[next.x][next.y] = 'X';
                next.x += wards[i].x, next.y += wards[i].y;
            }
        }
    }
    return ans;
}
int flipChess(char **chessboard, int size) {
    int m = size, n = strlen(chessboard[0]), ans = 0;
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (chessboard[x][y] != '.') continue;
            ans = fmax(ans, dfs(m, n, chessboard, (point_t) { x, y }));
        }
    }
    return ans;
}