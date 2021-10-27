// 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
//
// 返回所有可能的结果。答案可以按 任意顺序 返回。
//
//
//
// 示例 1：
//
//
// 输入：s = "()())()"
// 输出：["(())()","()()()"]
//
//
// 示例 2：
//
//
// 输入：s = "(a)())()"
// 输出：["(a())()","(a)()()"]
//
//
// 示例 3：
//
//
// 输入：s = ")("
// 输出：[""]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 25
// s 由小写英文字母以及括号 '(' 和 ')' 组成
// s 中至多含 20 个括号
//
// Related Topics 广度优先搜索 字符串 回溯 👍 561 👎 0

typedef struct {
    char *str;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, const char *str) {
    hash_t cur;
    HASH_FIND_STR(*t, str, cur);
    if (cur) return;
    cur = malloc(sizeof(*cur)), cur->str = strdup(str);
    HASH_ADD_STR(*t, str, cur);
}
void dfs(hash_t *t, char *s, int l, int r, char res[], int pos, int weight) {
    if (!*s) {
        if (!l && !r) res[pos] = '\0', hash_record(t, res);
        return;
    }
    if (*s != ')') {
        res[pos] = *s, dfs(t, s + 1, l, r, res, pos + 1, weight + (*s == '('));
        if (*s == '(' && l) dfs(t, s + 1, l - 1, r, res, pos, weight);
    } else {
        if (weight) res[pos] = *s, dfs(t, s + 1, l, r, res, pos + 1, weight - 1);
        if (r) dfs(t, s + 1, l, r - 1, res, pos, weight);
    }
}
char **removeInvalidParentheses(char *s, int *returnSize) {
    int l = 0, r = 0, len = 0;
    hash_t hash = NULL, cur, next;
    for (; s[len]; ++len) {
        if (s[len] != '(' && s[len] != ')') continue;
        if (s[len] == '(' || l) {
            l += s[len] == '(' ? 1 : -1;
        } else {
            r += 1;
        }
    }

    char res[len + 1];
    dfs(&hash, s, l, r, res, 0, 0);

    int i      = 0;
    char **ans = malloc((*returnSize = HASH_COUNT(hash)) * sizeof(char *));

    HASH_ITER(hh, hash, cur, next) {
        ans[i++] = cur->str;
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
