// 有一个需要密码才能打开的保险箱。密码是 n 位数, 密码的每一位是 k 位序列 0, 1, ..., k-1 中的一个 。
//
// 你可以随意输入密码，保险箱会自动记住最后 n 位输入，如果匹配，则能够打开保险箱。
//
// 举个例子，假设密码是 "345"，你可以输入 "012345" 来打开它，只是你输入了 6 个字符.
//
// 请返回一个能打开保险箱的最短字符串。
//
//
//
// 示例1:
//
// 输入: n = 1, k = 2
// 输出: "01"
// 说明: "10"也可以打开保险箱。
//
//
//
//
// 示例2:
//
// 输入: n = 2, k = 2
// 输出: "00110"
// 说明: "01100", "10011", "11001" 也能打开保险箱。
//
//
//
//
// 提示：
//
//
// n 的范围是 [1, 4]。
// k 的范围是 [1, 10]。
// k^n 最大可能为 4096。
//
//
//
// Related Topics 深度优先搜索 数学
// 👍 49 👎 0

void dfs(int k, int base, bool map[][k], int now, char **p) {
    int next_prefix = now % base * k;
    for (int i = 0; i < k; ++i) {
        if (map[now][i]) continue;
        map[now][i] = true;
        dfs(k, base, map, next_prefix + i, p);
    }
    *(*p)++ = '0' + now % k;
}
char *crackSafe(int n, int k) {
    int base = 1;
    for (int i = 1; i < n; base *= k, ++i) {}

    char *ans = calloc(base * k + n, sizeof(char)), *p = ans;

    if (n <= 1) {
        for (int i = 0; i < k; ans[i] = '0' + i, ++i) {}
    } else {
        bool map[base][k];
        memset(map, 0, sizeof(map));
        dfs(k, base / k, map, 0, &p);
        for (int i = 2; i < n; *p++ = '0', ++i) {}
    }

    return ans;
}