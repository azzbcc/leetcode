//给你两个二进制字符串，返回它们的和（用二进制表示）。
//
// 输入为 非空 字符串且只包含数字 1 和 0。
//
//
//
// 示例 1:
//
// 输入: a = "11", b = "1"
//输出: "100"
//
// 示例 2:
//
// 输入: a = "1010", b = "1011"
//输出: "10101"
//
//
//
// 提示：
//
//
// 每个字符串仅由字符 '0' 或 '1' 组成。
// 1 <= a.length, b.length <= 10^4
// 字符串如果不是 "0" ，就都不含前导零。
//
// Related Topics 数学 字符串
// 👍 526 👎 0

int max(int a, int b) {
    return a > b ? a : b;
}
void reverse(char *s, int beg, int end) {
    for (char ch; beg < end; ++beg, --end) {
        ch = s[beg], s[beg] = s[end], s[end] = ch;
    }
}
char *addBinary(char *a, char *b) {
    size_t la = strlen(a), lb = strlen(b), l = 0;

    char *ans = malloc((max(la, lb) + 2) * sizeof(char));
    for (int i = la - 1, j = lb - 1, ret = 0; i >= 0 || j >= 0 || ret; --i, --j) {
        if (i >= 0) ret += a[i] - '0';
        if (j >= 0) ret += b[j] - '0';

        ans[l++] = '0' + ret % 2, ret /= 2;
    }
    ans[l] = '\0';
    reverse(ans, 0, l - 1);

    return ans;
}