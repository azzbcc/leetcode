// 给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。
//
// 连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。
//
//
//
// 示例 1：
//
//
// 输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// 输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
// 解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
//     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
//     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
//
//
// 示例 2：
//
//
// 输入：words = ["cat","dog","catdog"]
// 输出：["catdog"]
//
//
//
// 提示：
//
//
// 1 <= words.length <= 10⁴
// 0 <= words[i].length <= 1000
// words[i] 仅由小写字母组成
// 0 <= sum(words[i].length) <= 10⁵
//
// Related Topics 深度优先搜索 字典树 数组 字符串 动态规划 👍 163 👎 0

#define WIDTH 26
typedef struct trie_node_t *trie_t;
struct trie_node_t {
    bool exist;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_insert(trie_t t, char *s) {
    trie_t cur = t;
    for (int i = 0; s[i]; cur = cur->next[s[i++] - 'a']) {
        if (!cur->next[s[i] - 'a']) cur->next[s[i] - 'a'] = trie_create();
    }
    cur->exist = true;
}
bool trie_check(trie_t t, char *str, size_t len) {
    trie_t cur = t;
    for (int i = 0; cur && i < len && str[i]; cur = cur->next[str[i++] - 'a']) {}
    return cur && cur->exist;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; ++i) {
        trie_free(t->next[i]);
    }
    free(t);
}
int cmp(const void *a, const void *b) {
    char *pa = *( char ** )a, *pb = *( char ** )b;
    size_t la = strlen(pa), lb = strlen(pb);
    return la != lb ? la - lb : strcmp(pa, pb);
}
char **findAllConcatenatedWordsInADict(char **words, int size, int *returnSize) {
    int len     = 0;
    trie_t trie = trie_create();
    char **ans  = malloc(size * sizeof(char *));

    qsort(words, size, sizeof(char *), cmp);
    for (int i = 0, l = 0; i < size; ++i) {
        for (; words[i][l]; ++l) {}
        if (!l) continue;

        bool dp[l + 1];
        memset(dp, false, sizeof(dp)), dp[0] = true;
        for (int j = 1; j <= l; ++j) {
            for (int k = j - 1; !dp[j] && k >= 0; --k) {
                if (dp[k] && trie_check(trie, words[i] + k, j - k)) dp[j] = true;
            }
        }
        if (dp[l]) ans[len++] = words[i];
        trie_insert(trie, words[i]);
    }
    trie_free(trie);
    *returnSize = len;
    return ans;
}