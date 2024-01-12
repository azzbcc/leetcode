// 给你一个字符串 s 和一个整数 repeatLimit ，用 s 中的字符构造一个新字符串 repeatLimitedString ，
// 使任何字母 连续 出现的次数都不超过 repeatLimit 次。你不必使用 s 中的全部字符。
//
// 返回 字典序最大的 repeatLimitedString 。
//
// 如果在字符串 a 和 b 不同的第一个位置，字符串 a 中的字母在字母表中出现时间比字符串 b 对应的字母晚，
// 则认为字符串 a 比字符串 b 字典序更大。如果字符串中前 min(a.length, b.length) 个字符都相同，
// 那么较长的字符串字典序更大。
//
//
//
// 示例 1：
//
// 输入：s = "cczazcc", repeatLimit = 3
// 输出："zzcccac"
// 解释：使用 s 中的所有字符来构造 repeatLimitedString "zzcccac"。
// 字母 'a' 连续出现至多 1 次。
// 字母 'c' 连续出现至多 3 次。
// 字母 'z' 连续出现至多 2 次。
// 因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
// 该字符串是字典序最大的 repeatLimitedString ，所以返回 "zzcccac" 。
// 注意，尽管 "zzcccca" 字典序更大，但字母 'c' 连续出现超过 3 次，所以它不是一个有效的 repeatLimitedString 。
//
//
// 示例 2：
//
// 输入：s = "aababab", repeatLimit = 2
// 输出："bbabaa"
// 解释：
// 使用 s 中的一些字符来构造 repeatLimitedString "bbabaa"。
// 字母 'a' 连续出现至多 2 次。
// 字母 'b' 连续出现至多 2 次。
// 因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
// 该字符串是字典序最大的 repeatLimitedString ，所以返回 "bbabaa" 。
// 注意，尽管 "bbabaaa" 字典序更大，但字母 'a' 连续出现超过 2 次，所以它不是一个有效的 repeatLimitedString 。
//
//
//
//
// 提示：
//
//
// 1 <= repeatLimit <= s.length <= 10⁵
// s 由小写英文字母组成
//
//
// Related Topics 贪心 字符串 计数 堆（优先队列） 👍 34 👎 0

#define WIDTH 26
#define MAX   100000
char *repeatLimitedString(char *s, int limit) {
    static char str[MAX + 1];
    int st[WIDTH] = { 0 }, l = 0;
    for (int i = 0; s[i]; ++st[s[i++] - 'a']) {}
    for (int a = WIDTH - 1, b = a - 1, c = 0;;) {
        for (; a >= 0 && !st[a]; --a) {}
        for (b = fmin(b, a - 1); b >= 0 && !st[b]; --b) {}
        if (a < 0) break;

        if (c && str[l - 1] == 'a' + a) {
            if (c < limit) {
                c++, str[l++] = 'a' + a, --st[a];
            } else if (b >= 0) {
                c = 1, str[l++] = 'a' + b, --st[b];
            } else {
                break;
            }
        } else {
            c = 1, str[l++] = 'a' + a, --st[a];
        }
    }
    str[l] = '\0';
    return str;
}