// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
// 示例:
//
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
// Related Topics 字符串 回溯算法
// 👍 819 👎 0

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXN 0x1000
int help_len     = 0;
char *help[MAXN] = { NULL };
void dfs(char *digit, char *str, int pos) {
    if (!*digit) {
        help[help_len] = strdup(str);
        assert(help_len++ < MAXN);
        return;
    }

    int d                = *digit - '2';
    static char *array[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    for (int i = 0; array[d][i]; ++i) {
        str[pos] = array[d][i];
        dfs(digit + 1, str, pos + 1);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    char str[256] = { '\0' };

    *returnSize = 0;
    if (!*digits) return NULL;

    help_len = 0;
    dfs(digits, str, 0);

    *returnSize = help_len;
    char **ans  = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}
