// 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
//
//
//
// 示例 1：
//
//
// 输入：s = "owoztneoer"
// 输出："012"
//
//
// 示例 2：
//
//
// 输入：s = "fviefuro"
// 输出："45"
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 10⁵
// s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一
// s 保证是一个符合题目要求的字符串
//
// Related Topics 哈希表 数学 字符串 👍 114 👎 0

#define WIDTH 26
#define MAXN  10
char *originalDigits(char *s) {
    struct {
        char ch;
        int digit;
    } help[MAXN] = { { 'g', 8 }, { 'u', 4 }, { 'w', 2 }, { 'x', 6 }, { 'z', 0 },
                     { 'f', 5 }, { 'h', 3 }, { 'o', 1 }, { 's', 7 }, { 'e', 9 } };
    int len = 0, cs[WIDTH] = { 0 }, cc[MAXN] = { 0 };
    char *digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (char *p = s; *p; cs[*p++ - 'a']++) {}
    for (int i = 0; i < MAXN; ++i) {
        len += cc[help[i].digit] = cs[help[i].ch - 'a'];
        if (cc[help[i].digit] == 0) continue;
        for (char *p = digits[help[i].digit]; *p; ++p) {
            cs[*p - 'a'] -= cc[help[i].digit];
        }
    }

    char *ans = malloc((len + 1) * sizeof(char)), *p = ans;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < cc[i]; *p++ = '0' + i, ++j) {}
    }
    *p = '\0';
    return ans;
}