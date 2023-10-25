// 给你一个正整数 n ，请你返回 n 的 惩罚数 。
//
// n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：
//
//
// 1 <= i <= n
// i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。
//
//
//
//
// 示例 1：
//
//
// 输入：n = 10
// 输出：182
// 解释：总共有 3 个整数 i 满足要求：
// - 1 ，因为 1 * 1 = 1
// - 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
// - 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
// 因此，10 的惩罚数为 1 + 81 + 100 = 182
//
//
// 示例 2：
//
//
// 输入：n = 37
// 输出：1478
// 解释：总共有 4 个整数 i 满足要求：
// - 1 ，因为 1 * 1 = 1
// - 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
// - 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
// - 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
// 因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478
//
//
//
//
// 提示：
//
//
// 1 <= n <= 1000
//
//
// Related Topics 数学 回溯 👍 50 👎 0

static int len = 0, help[128];
bool dfs(int target, char *str, int cur) {
    if (!*str) return cur == target;
    for (int i = 0, tmp = 0; str[i]; ++i) {
        if (tmp *= 10, tmp += str[i] - '0', cur + tmp > target) break;
        if (dfs(target, str + i + 1, cur + tmp)) return true;
    }
    return false;
}
void init() {
    char tmp[32];
    static bool initial = false;
    if (initial) return;

    initial = true;
    for (int i = 1; i <= 1000; ++i) {
        sprintf(tmp, "%d", i * i);
        if (dfs(i, tmp, 0)) help[len++] = i;
    }
}
int punishmentNumber(int n) {
    int ans = 0;

    init();
    for (int i = 0; i < len && help[i] <= n; ans += help[i] * help[i], ++i) {}
    return ans;
}
