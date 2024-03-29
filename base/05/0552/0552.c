// 可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//
// 'A'：Absent，缺勤
// 'L'：Late，迟到
// 'P'：Present，到场
//
//
// 如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//
//
// 按 总出勤 计，学生缺勤（'A'）严格 少于两天。
// 学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//
//
// 给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量
// 。答案可能很大，所以返回对 10⁹ + 7取余 的结果。
//
//
//
// 示例 1：
//
//
// 输入：n = 2
// 输出：8
// 解释：
// 有 8 种长度为 2 的记录将被视为可奖励：
// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// 只有"AA"不会被视为可奖励，因为缺勤次数为 2 次（需要少于 2 次）。
//
//
// 示例 2：
//
//
// 输入：n = 1
// 输出：3
//
//
// 示例 3：
//
//
// 输入：n = 10101
// 输出：183236316
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁵
//
// Related Topics 动态规划 👍 211 👎 0

#if 0
#define MOD 1000000007
int checkRecord(int n) {
    int dp[2][2][3] = { 1 }, cur = 0;

    for (; n--; cur = 1 - cur) {
        memset(dp[1 - cur], 0, sizeof(dp[cur]));
        // end with a
        for (int i = 0; i < 3; ++i) {
            dp[1 - cur][1][0] = (dp[1 - cur][1][0] + dp[cur][0][i]) % MOD;
        }
        // end with p
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[1 - cur][i][0] = (dp[1 - cur][i][0] + dp[cur][i][j]) % MOD;
            }
        }
        // end with l
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < 3; j++) {
                dp[1 - cur][i][j] = (dp[1 - cur][i][j] + dp[cur][i][j - 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans = (ans + dp[cur][i][j]) % MOD;
        }
    }
    return ans;
}
#else
#define MOD 1000000007
typedef struct {
    int row, col;
    long data[6][6];
} matrix_t;
matrix_t mul(matrix_t a, matrix_t b) {
    matrix_t result = { a.row, b.col };
    for (int i = 0; i < a.row; ++i) {
        for (int j = 0; j < b.col; ++j) {
            for (int k = 0; k < a.col; ++k) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] %= MOD;
        }
    }
    return result;
}
int checkRecord(int n) {
    matrix_t ans  = { 1, 6, .data[0][0] = 1 };
    matrix_t base = { 6,
                      6,
                      { { 1, 1, 0, 1, 0, 0 },
                        { 1, 0, 1, 1, 0, 0 },
                        { 1, 0, 0, 1, 0, 0 },
                        { 0, 0, 0, 1, 1, 0 },
                        { 0, 0, 0, 1, 0, 1 },
                        { 0, 0, 0, 1, 0, 0 } } };
    for (n++; n > 0; n /= 2) {
        if (n & 1) ans = mul(ans, base);
        base = mul(base, base);
    }
    return ans.data[0][3];
}
#endif