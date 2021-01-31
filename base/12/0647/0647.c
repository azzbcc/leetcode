// 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//
//
// 示例 1：
//
// 输入："abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"
//
//
// 示例 2：
//
// 输入："aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
//
//
//
// 提示：
//
//
// 输入的字符串长度不会超过 1000 。
//
// Related Topics 字符串 动态规划
// 👍 329 👎 0
#define MAXN      2001
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int countSubstrings(char *s) {
    int manachers[MAXN] = { 0 }, sum = 0;
    char str[MAXN + 1] = "#", *ps = str;

    while ((*++ps = *s++) && (*++ps = '#')) {}
    *ps = '\0'; // 重要，保证39行以及48行循环终止

    for (int mid = 0, end = 0, i = 1; str[i]; sum += (manachers[i++] + 1) / 2) {
        if (i < end) {
            manachers[i] = MIN(manachers[mid * 2 - i], end - i);
            if (manachers[mid * 2 - i] != end - i) continue;
        } else {
            end = i;
        }

        mid = i;
        for (int beg = mid * 2 - end; beg > 0 && str[--beg] == str[end + 1]; end++) {}
        manachers[i] = end - mid;
    }

    return sum;
}
