// 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
//
// 示例 1:
//
// 输入: n = 12
// 输出: 3
// 解释: 12 = 4 + 4 + 4.
//
// 示例 2:
//
// 输入: n = 13
// 输出: 2
// 解释: 13 = 4 + 9.
// Related Topics 广度优先搜索 数学 动态规划
// 👍 648 👎 0

int numSquares(int n) {
    int help[n + 1];

    memset(help, 0, sizeof(help));
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i + j * j <= n; ++j) {
            if (!help[i + j * j] || help[i + j * j] > help[i] + 1) help[i + j * j] = help[i] + 1;
        }
    }

    return help[n];
}
