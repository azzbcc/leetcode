// 给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，
// 其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false 。
//
// 子字符串 是字符串中连续的字符序列。
//
//
//
// 示例 1：
//
//
// 输入：s = "0110", n = 3
// 输出：true
//
//
// 示例 2：
//
//
// 输入：s = "0110", n = 4
// 输出：false
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s[i] 不是 '0' 就是 '1'
// 1 <= n <= 10⁹
//
//
// Related Topics 字符串 👍 78 👎 0

bool valid(char *s, int len, int min, int max) {
    int count = 0;
    bool hash[max - min + 1];
    memset(hash, false, sizeof(hash));
    for (int r = 0, cur = 0; s[r]; ++r) {
        cur = cur * 2 + (s[r] - '0');
        if (r >= len) cur -= (s[r - len] - '0') << len;
        if (r >= len - 1 && cur >= min && cur <= max) {
            count += !hash[cur - min], hash[cur - min] = true;
        }
    }
    return count == max - min + 1;
}
bool queryString(char *s, int n) {
    int len = 20;
    if (n == 1) return strchr(s, '1') != NULL;
    for (; (1 << len) >= n; --len) {}
    return valid(s, len, 1 << (len - 1), (1 << len) - 1) && valid(s, len + 1, 1 << len, n);
}
