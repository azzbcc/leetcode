// 有一份由 n 个问题组成的调查问卷，每个问题的答案要么是 0（no，否），要么是 1（yes，是）。
//
// 这份调查问卷被分发给 m 名学生和 m 名导师，学生和导师的编号都是从 0 到 m - 1 。学生的答案用一个二维整数数组 students
// 表示， 其中students[i] 是一个整数数组，包含第 i 名学生对调查问卷给出的答案（下标从 0
// 开始）。导师的答案用一个二维整数数组 mentors 表示， 其中mentors[j] 是一个整数数组，包含第 j
// 名导师对调查问卷给出的答案（下标从 0 开始）。
//
// 每个学生都会被分配给 一名 导师，而每位导师也会分配到 一名
// 学生。配对的学生与导师之间的兼容性评分等于学生和导师答案相同的次数。
//
//
// 例如，学生答案为[1, 0, 1] 而导师答案为 [0, 0, 1] ，那么他们的兼容性评分为 2 ，因为只有第二个和第三个答案相同。
//
//
// 请你找出最优的学生与导师的配对方案，以 最大程度上 提高 兼容性评分和 。
//
// 给你 students 和 mentors ，返回可以得到的 最大兼容性评分和 。
//
//
//
// 示例 1：
//
// 输入：students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
// 输出：8
// 解释：按下述方式分配学生和导师：
// - 学生 0 分配给导师 2 ，兼容性评分为 3 。
// - 学生 1 分配给导师 0 ，兼容性评分为 2 。
// - 学生 2 分配给导师 1 ，兼容性评分为 3 。
// 最大兼容性评分和为 3 + 2 + 3 = 8 。
//
// 示例 2：
//
// 输入：students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
// 输出：0
// 解释：任意学生与导师配对的兼容性评分都是 0 。
//
//
//
//
// 提示：
//
//
// m == students.length == mentors.length
// n == students[i].length == mentors[j].length
// 1 <= m, n <= 8
// students[i][k] 为 0 或 1
// mentors[j][k] 为 0 或 1
//
// Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 13 👎 0

#if 0
int maxCompatibilitySum(int **students, int size, int *colSize, int **mentors, int mentorsSize, int *mentorsColSize) {
    int grade[size][size], mask = 0x1 << size, dp[mask][mask];

    memset(dp, 0, sizeof(dp));
    memset(grade, 0, sizeof(grade));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < *colSize; ++k) {
                grade[i][j] += students[i][k] == mentors[j][k];
            }
        }
    }

    for (int i = 0; i < mask; ++i) {
        for (int ii = 0; ii < size; ++ii) {
            if ((i & 0x1 << ii) == 0) continue;
            for (int j = 0; j < mask; ++j) {
                if (__builtin_popcount(i) != __builtin_popcount(j)) continue;
                for (int jj = 0; jj < size; ++jj) {
                    if ((j & 0x1 << jj) == 0) continue;
                    dp[i][j] = fmax(dp[i][j], grade[ii][jj] + dp[0x1 << ii ^ i][0x1 << jj ^ j]);
                }
            }
        }
    }

    return dp[mask - 1][mask - 1];
}
#else
int maxCompatibilitySum(int **students, int size, int *colSize, int **mentors, int mentorsSize, int *mentorsColSize) {
    int grade[size][size], mask = 0x1 << size, dp[mask];

    memset(dp, 0, sizeof(dp));
    memset(grade, 0, sizeof(grade));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < *colSize; ++k) {
                grade[i][j] += students[i][k] == mentors[j][k];
            }
        }
    }

    for (int i = 0; i < mask; ++i) {
        int c = __builtin_popcount(i);
        for (int j = 0; j < size; ++j) {
            if ((i & 0x1 << j) == 0) continue;
            dp[i] = fmax(dp[i], dp[0x1 << j ^ i] + grade[c - 1][j]);
        }
    }

    return dp[mask - 1];
}
#endif