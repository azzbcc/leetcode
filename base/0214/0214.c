// 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
//
// 示例 1:
//
// 输入: "aacecaaa"
// 输出: "aaacecaaa"
//
//
// 示例 2:
//
// 输入: "abcd"
// 输出: "dcbabcd"
// Related Topics 字符串
// 👍 219 👎 0
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
char *shortestPalindrome(char *s) {
    size_t len = strlen(s);
    char *str  = calloc(2 * len + 2, sizeof(char));

    str[0] = '#';
    for (char *ps = str, *ts = s; (*++ps = *ts++);) {
        *++ps = '#';
    }

    int manachers[len + 1], max = 0;
    for (int mid = 0, end = 0, i = 0; i <= len; i++) {
        if (i < end) {
            manachers[i] = MIN(manachers[mid * 2 - i], end - i);
            if (manachers[mid * 2 - i] != end - i) continue;
        } else {
            end = i;
        }

        mid = i;
        for (int beg = mid * 2 - end; beg > 0 && str[--beg] == str[end + 1]; end++) {}
        manachers[i] = end - mid;

        if (manachers[i] == i) max = i;
    }

    for (char *ps = str; len || (*ps = s[max++]); ps++) {
        if (len) *ps = s[--len];
    }

    return str;
}
