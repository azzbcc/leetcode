// 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
//
// 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
//
//
//
// 示例 1：
//
//
// 输入：s = "a1b2"
// 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
//
//
// 示例 2:
//
//
// 输入: s = "3z4"
// 输出: ["3z4","3Z4"]
//
//
//
//
// 提示:
//
//
// 1 <= s.length <= 12
// s 由小写英文字母、大写英文字母和数字组成
//
//
// Related Topics 位运算 字符串 回溯 👍 419 👎 0

#define MAX 12 + 1
char **letterCasePermutation(char *s, int *returnSize) {
    char str[MAX], **ans;
    int pos[MAX] = { 0 }, len = 0;
    for (int i = 0; (str[i] = s[i]); ++i) {
        if (isalpha(s[i])) pos[len++] = i;
    }
    ans = malloc((*returnSize = 0x1 << len) * sizeof(char *));
    for (int i = 0; i < 0x1 << len; ans[i++] = strdup(str)) {
        for (int j = 0; j < len; ++j) {
            str[pos[j]] = 0x20 & i << 5 >> j ^ s[pos[j]];
        }
    }
    return ans;
}
