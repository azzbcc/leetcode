// 给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn]
// 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。
//
// 给你五个整数 m、n、maxMove、startRow 以及 startColumn
// ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对109 + 7 取余 后的结果。
//
//
//
// 示例 1：
//
//
// 输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// 输出：6
//
//
// 示例 2：
//
//
// 输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// 输出：12
//
//
//
//
// 提示：
//
//
// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n
//
// Related Topics 动态规划
// 👍 150 👎 0

#define MOD 1000000007
typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int findPaths(int m, int n, int move, int row, int col) {
    if (!move) return 0;
    int dp[2][m][n], cur = 0;

    memset(dp[cur], 0, sizeof(dp[cur]));
    for (int i = 0; i < m; ++i) {
        dp[cur][i][0] += 1, dp[cur][i][n - 1] += 1;
    }
    for (int i = 0; i < n; ++i) {
        dp[cur][0][i] += 1, dp[cur][m - 1][i] += 1;
    }

    int ans = dp[cur][row][col];
    for (; move > 1; move--, cur = 1 - cur) {
        memset(dp[1 - cur], 0, sizeof(dp[1 - cur]));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                for (int i = 0; i < sizeof(wards) / sizeof(point_t); ++i) {
                    point_t next = (point_t) { x + wards[i].x, y + wards[i].y };
                    if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
                    dp[1 - cur][x][y] = (dp[1 - cur][x][y] + dp[cur][next.x][next.y]) % MOD;
                }
            }
        }
        ans = (ans + dp[1 - cur][row][col]) % MOD;
    }

    return ans;
}