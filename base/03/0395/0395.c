// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于
// k。返回这一子串的长度。
//
//
//
// 示例 1：
//
//
// 输入：s = "aaabb", k = 3
// 输出：3
// 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
//
//
// 示例 2：
//
//
// 输入：s = "ababbc", k = 2
// 输出：5
// 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
//
//
//
// 提示：
//
//
// 1 <= s.length <= 104
// s 仅由小写英文字母组成
// 1 <= k <= 105
//
// Related Topics 递归 分治算法 Sliding Window
// 👍 351 👎 0

#define WIDTH 26
#define MAXN  500

int longestString(const char *s, int l, int r, int k) {
    if (l == r) return 0;
    if (r - l < k) return 0;
    int st[WIDTH] = { 0 }, stack[MAXN][2], count = 0;
    for (int i = l; i < r; st[s[i++] - 'a']++) {}
    for (stack[count][0] = stack[count][1] = l; stack[count][1] < r; ++stack[count][1]) {
        if (st[s[stack[count][1]] - 'a'] < k) {
            if (stack[count][0] < stack[count][1]) {
                count++;
                stack[count][1] = stack[count - 1][1];
            }
            stack[count][0] = stack[count][1] + 1;
        }
    }
    if (stack[count][0] == l) return r - l;

    int ans = 0;
    count += stack[count][0] < stack[count][1];
    for (int i = 0, tmp; i < count; ++i) {
        tmp = longestString(s, stack[i][0], stack[i][1], k);
        if (ans < tmp) ans = tmp;
    }
    return ans;
}
int longestSubstring(char *s, int k) {
    return longestString(s, 0, strlen(s), k);
}