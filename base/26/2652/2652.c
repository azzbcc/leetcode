// 给你一个正整数 n ，请你计算在 [1，n] 范围内能被 3、5、7 整除的所有整数之和。
//
// 返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。
//
//
//
// 示例 1：
//
// 输入：n = 7
// 输出：21
// 解释：在 [1, 7] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7 。数字之和为 21 。
//
//
// 示例 2：
//
// 输入：n = 10
// 输出：40
// 解释：在 [1, 10] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9、10 。数字之和为 40 。
//
//
// 示例 3：
//
// 输入：n = 9
// 输出：30
// 解释：在 [1, 9] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9 。数字之和为 30 。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10³
//
//
// Related Topics 数学 👍 56 👎 0

#define MAXN 105
typedef struct {
    int c, sum;
} node_t;
node_t help[MAXN + 1];
static void init() {
    static bool initial = false;
    if (initial) return;

    initial = true;
    help[0] = (node_t) { 1, 0 };
    for (int i = 1; i < MAXN; ++i) {
        help[i] = help[i - 1];
        if (i % 3 && i % 5 && i % 7) continue;
        help[i].c++, help[i].sum += i;
    }
    help[MAXN] = help[MAXN - 1];
}
int sumOfMultiples(int n) {
    init();

    int nc  = n / MAXN;
    int ans = nc * help[MAXN].sum + nc * (nc - 1) * (MAXN * help[MAXN].c) / 2;
    ans += help[n % MAXN].c * MAXN * nc + help[n % MAXN].sum;
    return ans;
}
