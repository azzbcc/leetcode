// 给定一个非空字符串 s 和一个包含非空单词列表的字典
// wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的 句子。
//
// 说明：
//
//
// 分隔时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
//
//
// 示例 1：
//
// 输入:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// 输出:
// [
//  "cats and dog",
//  "cat sand dog"
// ]
//
//
// 示例 2：
//
// 输入:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// 输出:
// [
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
// ]
// 解释: 注意你可以重复使用字典中的单词。
//
//
// 示例 3：
//
// 输入:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出:
// []
//
// Related Topics 动态规划 回溯算法
// 👍 290 👎 0
#define WIDTH 26
#define INF   -1
#define MAXN  0x1000

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int index;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    trie_t t = calloc(1, sizeof(struct trie_node_t));
    t->index = INF;
    return t;
}
void trie_insert(trie_t t, const char *s, size_t index) {
    trie_t cur = t;
    for (int i = 0; s[i]; cur = cur->next[s[i++] - 'a']) {
        if (!cur->next[s[i] - 'a']) cur->next[s[i] - 'a'] = trie_create();
    }
    cur->index = index;
}
int trie_find(trie_t t, const char *s, int res[]) {
    int ans = 0;
    for (trie_t cur = t; cur; cur = cur->next[*s++ - 'a']) {
        if (cur->index != INF) res[ans++] = cur->index;
        if (!*s) break;
    }
    return ans;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}

int help_len     = 0;
char *help[MAXN] = { NULL };
void dfs(int m, int n, int dp[][n], char **words, int cur, int res[], int pos) {
    if (!cur) {
        char *str = NULL;
        assert(help_len < MAXN);
        help[help_len++] = str = calloc(pos + m, sizeof(char));
        for (int i = pos - 1; i >= 0; --i) {
            str += sprintf(str, "%s", words[res[i]]);
            if (i) *str++ = ' ';
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (dp[cur][i] == INF) continue;
        res[pos] = i;
        dfs(m, n, dp, words, dp[cur][i], res, pos + 1);
    }
}

char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize) {
    if (!wordDictSize) {
        *returnSize = 0;
        return NULL;
    }

    char **ans = NULL;
    trie_t t   = trie_create();
    size_t len = strlen(s), lens[wordDictSize];
    int c, res[len + wordDictSize], dp[len + 1][wordDictSize];

    // 生成前缀树
    for (int i = 0; i < wordDictSize; ++i) {
        lens[i] = strlen(wordDict[i]);
        trie_insert(t, wordDict[i], i);
    }

    memset(dp, INF, sizeof(dp));

    // 匹配初始化
    c = trie_find(t, s, res);
    for (int i = 0; i < c; i++) {
        dp[lens[res[i]]][res[i]] = 0;
    }

    // 匹配
    for (int i = 1; i < len; ++i) {
        bool exist = false;
        for (int j = 0; !exist && j < wordDictSize; exist = dp[i][j++] != INF) {}
        if (!exist) continue;

        c = trie_find(t, &s[i], res);
        // 遍历所有匹配结果
        for (int j = 0; j < c; ++j) {
            // 匹配超过了？
            if (i + lens[res[j]] > len) break;
            // 迁移结果
            dp[i + lens[res[j]]][res[j]] = i;
        }
    }

    trie_free(t);

    help_len = 0;
    dfs(len, wordDictSize, dp, wordDict, len, res, 0);

    *returnSize = help_len, ans = calloc(help_len, sizeof(char *));
    memcpy(ans, help, help_len * sizeof(char *));

    return ans;
}
