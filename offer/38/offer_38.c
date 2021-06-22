// 输入一个字符串，打印出该字符串中字符的所有排列。
//
//
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
//
//
//
// 示例:
//
// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]
//
//
//
//
// 限制：
//
// 1 <= s 的长度 <= 8
// Related Topics 回溯算法
// 👍 314 👎 0

#define MAXN 8 + 1
#define MAXM 40320

int help_len;
char *help[MAXM];
static int cmp(const void *a, const void *b) {
    return *( char * )a - *( char * )b;
}
void dfs(const char *s, int cur, bool visit[], char res[]) {
    if (!s[cur]) {
        help[help_len++] = strdup(res);
        return;
    }
    for (int i = 0; s[i]; ++i) {
        if (visit[i] || i && s[i] == s[i - 1] && !visit[i - 1]) continue;
        visit[i] = true, res[cur] = s[i];
        dfs(s, cur + 1, visit, res);
        visit[i] = false;
    }
}
char **permutation(char *s, int *returnSize) {
    int len          = strlen(s);
    bool visit[MAXN] = { false };
    char str[len + 1], res[len + 1];

    memcpy(str, s, sizeof(str));
    qsort(str, len, sizeof(char), cmp);

    help_len = 0, res[len] = '\0';
    dfs(str, 0, visit, res);

    char **ans = malloc((*returnSize = help_len) * sizeof(char *));
    memcpy(ans, help, help_len * (sizeof(char *)));
    return ans;
}
