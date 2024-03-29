// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//
// 注意:
// 假设字符串的长度不会超过 1010。
//
// 示例 1:
//
//
// 输入:
//"abccccdd"
//
// 输出:
// 7
//
// 解释:
// 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
//
// Related Topics 哈希表
// 👍 220 👎 0

int longestPalindrome(char *s) {
    int times[52] = { 0 };

    while (*s) {
        if ('a' <= *s && *s <= 'z') {
            times[*s - 'a'] += 1;
        } else {
            times[*s - 'A' + 26] += 1;
        }
        s++;
    }

    int ans = 0;
    for (int i = 0; i < 52; ++i) {
        if (0 == (ans & 1)) ans |= times[i] % 2;
        ans += times[i] & 0xffe;
    }

    return ans;
}
