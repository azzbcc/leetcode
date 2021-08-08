// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
// 回文串 是正着读和反着读都一样的字符串。
//
//
//
// 示例 1：
//
//
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
//
//
// 示例 2：
//
//
// 输入：s = "a"
// 输出：[["a"]]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 16
// s 仅由小写英文字母组成
//
// Related Topics 深度优先搜索 动态规划 回溯算法
// 👍 590 👎 0

#define MAXN      0x10000
#define MAXM      16
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct dp_node dp_t;
typedef struct node {
    char *str;
    dp_t *next;
} node_t;
struct dp_node {
    int count;
    node_t nodes[MAXM];
};

char **help[MAXN];
int manacher[2 * MAXM + 1];
int help_len, help_col[MAXN];
bool check(int beg, int len) {
    return manacher[beg * 2 + len] >= len;
}
void init(char *s, int len) {
    char *str = calloc(2 * len + 2, sizeof(char));

    str[0] = '#';
    for (char *ps = str, *ts = s; (*++ps = *ts++);) {
        *++ps = '#';
    }
    for (int mid = 0, end = 0, i = 0; str[i]; i++) {
        if (i < end) {
            manacher[i] = MIN(manacher[mid * 2 - i], end - i);
            if (manacher[mid * 2 - i] != end - i) continue;
        } else {
            end = i;
        }

        mid = i;
        for (int beg = mid * 2 - end; beg > 0 && str[--beg] == str[end + 1]; end++) {}
        manacher[i] = end - mid;
    }
    free(str);
}
void record(node_t *nodes[], int len) {
    char **ans = malloc(len * sizeof(char *));
    for (int i = 0; i < len; ++i) {
        ans[i] = strdup(nodes[i]->str);
    }
    help[help_len] = ans, help_col[help_len] = len, help_len++;
}
void dfs(dp_t *dp, node_t *nodes[], int len) {
    if (!dp) {
        record(nodes, len);
        return;
    }
    for (int i = 0; i < dp->count; ++i) {
        nodes[len] = &dp->nodes[i];
        dfs(dp->nodes[i].next, nodes, len + 1);
    }
}
char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    size_t len = strlen(s);
    dp_t dp[len];
    node_t *nodes[len];

    init(s, len);
    for (int i = 0; i < len; ++i) {
        dp[i].count = 0;
        for (int l = 1; i + l <= len; ++l) {
            if (!check(i, l)) continue;
            node_t *node = &dp[i].nodes[dp[i].count++];
            node->str    = malloc((l + 1) * sizeof(char));
            node->next   = i + l < len ? &dp[i + l] : NULL;
            snprintf(node->str, l + 1, "%s", s + i);
        }
    }

    help_len = 0;
    dfs(dp, nodes, 0);

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < dp[i].count; ++j) {
            free(dp[i].nodes[j].str);
        }
    }

    char ***ans = malloc((*returnSize = help_len) * sizeof(char **));

    *returnColumnSizes = malloc(help_len * sizeof(int));
    memcpy(*returnColumnSizes, help_col, help_len * sizeof(int));
    memcpy(ans, help, help_len * sizeof(char **));

    return ans;
}
