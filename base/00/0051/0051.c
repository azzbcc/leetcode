// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//
//
// 上图为 8 皇后问题的一种解法。
//
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
//
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
//
// 示例：
//
// 输入：4
// 输出：[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
// ]
// 解释: 4 皇后问题存在两个不同的解法。
//
//
//
//
// 提示：
//
//
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
//
// Related Topics 回溯算法
// 👍 552 👎 0
#define MAXN 14200
int help_len      = 0;
char **help[MAXN] = { NULL };
bool check(const int map[], int now) {
    for (int i = 0; i < now; ++i) {
        if (abs(map[i] - map[now]) == now - i) return false;
    }
    return true;
}
void record(const int map[], int n) {
    char **ans = calloc(n, sizeof(char *));
    for (int i = 0; i < n; ++i) {
        ans[i] = calloc(n + 1, sizeof(char));
        for (int j = 0; j < n; ++j) {
            ans[i][j] = j == map[i] ? 'Q' : '.';
        }
        ans[i][n] = '\0';
    }
    help[help_len] = ans;
    assert(help_len++ < MAXN);
}
void dfs(int n, int now, int map[], bool visited[]) {
    if (now >= n) {
        record(map, n);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        map[now] = i;
        if (!check(map, now)) continue;

        visited[i] = true;
        dfs(n, now + 1, map, visited);
        visited[i] = false;
    }
}
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    int map[n];
    bool visited[n];
    for (int i = 0; i < n; visited[i++] = false) {}

    help_len = 0;
    dfs(n, 0, map, visited);

    char ***ans = calloc(help_len, sizeof(char **));
    memcpy(ans, help, help_len * sizeof(char **));

    *returnSize = help_len, *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; ++i) {
        (*returnColumnSizes)[i] = n;
    }

    return ans;
}
