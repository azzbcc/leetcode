// 给出一个字符串 s（仅含有小写英文字母和括号）。
//
// 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
//
// 注意，您的结果中 不应 包含任何括号。
//
//
//
// 示例 1：
//
// 输入：s = "(abcd)"
// 输出："dcba"
//
//
// 示例 2：
//
// 输入：s = "(u(love)i)"
// 输出："iloveu"
//
//
// 示例 3：
//
// 输入：s = "(ed(et(oc))el)"
// 输出："leetcode"
//
//
// 示例 4：
//
// 输入：s = "a(bcdefghijkl(mno)p)q"
// 输出："apmnolkjihgfedcbq"
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 2000
// s 中只有小写英文字母和括号
// 我们确保所有括号都是成对出现的
//
// Related Topics 栈
// 👍 141 👎 0

#define MAXN 2000
char *reverseParentheses(char *s) {
    static char str[MAXN + 1];
    int len = 0, pair[MAXN] = { 0 }, stack[MAXN] = { 0 }, top = -1;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            int j   = stack[top--];
            pair[i] = j, pair[j] = i;
        }
    }
    for (int i = 0, step = 1; s[i]; i += step) {
        if (s[i] == '(' || s[i] == ')') {
            i = pair[i], step = -step;
        } else {
            str[len++] = s[i];
        }
    }
    str[len] = '\0';
    return str;
}
