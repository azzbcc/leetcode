// 在一个 n x n 的矩阵 grid 中，除了在数组 mines 中给出的元素为 0，其他每个元素都为 1。mines[i] = [xi,
// yi]表示grid[xi][yi] == 0
//
// 返回 grid 中包含 1 的最大的 轴对齐 加号标志的阶数 。如果未找到加号标志，则返回 0 。
//
// 一个 k 阶由 1 组成的 “轴对称”加号标志 具有中心网格 grid[r][c] == 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为
// k-1，由 1 组成的臂。注意，只有加号标志的所有网格要求为 1 ，别的网格可能为 0 也可能为 1 。
//
//
//
// 示例 1：
//
//
//
//
// 输入: n = 5, mines = [[4, 2]]
// 输出: 2
// 解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
//
//
// 示例 2：
//
//
//
//
// 输入: n = 1, mines = [[0, 0]]
// 输出: 0
// 解释: 没有加号标志，返回 0 。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 500
// 1 <= mines.length <= 5000
// 0 <= xi, yi < n
// 每一对 (xi, yi) 都 不重复
//
//
// Related Topics 数组 动态规划 👍 132 👎 0

#define MAXN 500
typedef struct {
    int val;
    UT_hash_handle hh;
} hash_t;
int orderOfLargestPlusSign(int n, int **mines, int size, int *colSize) {
    int dp[n][n], ans         = 0;
    hash_t nodes[size], *hash = NULL;
    memset(dp, 0x7f, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        nodes[i].val = mines[i][0] * MAXN + mines[i][1];
        HASH_ADD_INT(hash, val, &nodes[i]);
    }
#define CAL()                                                                                                          \
    do {                                                                                                               \
        hash_t *cur = NULL;                                                                                            \
        int val     = x * MAXN + y;                                                                                    \
        HASH_FIND_INT(hash, &val, cur);                                                                                \
        if (cur) c = 0;                                                                                                \
        dp[x][y] = fmin(dp[x][y], c);                                                                                  \
    } while (0)
    for (int x = 0; x < n; ++x) {
        for (int y = 0, c = 0; y < n; ++y, ++c) {
            CAL();
        }
        for (int y = n - 1, c = 0; y >= 0; --y, ++c) {
            CAL();
        }
    }
    for (int y = 0; y < n; ++y) {
        for (int x = 0, c = 0; x < n; ++x, ++c) {
            CAL();
        }
        for (int x = n - 1, c = 0; x >= 0; --x, ++c) {
            CAL();
        }
    }
    HASH_CLEAR(hh, hash);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            ans = fmax(ans, dp[x][y]);
        }
    }
    return ans;
}