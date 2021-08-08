// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t
// 所有字符的子串，则返回空字符串 "" 。
//
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
//
//
//
// 示例 1：
//
//
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
//
//
// 示例 2：
//
//
// 输入：s = "a", t = "a"
// 输出："a"
//
//
//
//
// 提示：
//
//
// 1 <= s.length, t.length <= 105
// s 和 t 由英文字母组成
//
//
//
// 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
// Related Topics 哈希表 双指针 字符串 Sliding Window
// 👍 859 👎 0

#define WIDTH 128
#define MAXN  100001

bool invalid(const int as[], const int at[]) {
    for (int i = 0; i < WIDTH; ++i) {
        if (as[i] < at[i]) return true;
    }
    return false;
}
char *minWindow(char *s, char *t) {
    int offset = 0, len = MAXN;
    int as[WIDTH] = { 0 }, at[WIDTH] = { 0 };
    for (int i = 0; t[i]; at[t[i++]]++) {}
    for (int l = 0, r = -1;; as[s[l++]]--) {
        for (as[s[++r]]++; s[r] && (as[s[r]] != at[s[r]] || invalid(as, at)); as[s[++r]]++) {}
        if (!s[r]) break;
        for (; l < r && (!at[s[l]] || as[s[l]] > at[s[l]]); as[s[l++]]--) {}
        if (len > r - l + 1) len = r - l + 1, offset = l;
    }
    if (len == MAXN) len = 0;

    char *ans = malloc(len + 1);
    snprintf(ans, len + 1, "%s", s + offset);
    return ans;
}
