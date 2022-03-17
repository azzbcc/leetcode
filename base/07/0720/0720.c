// 给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words
// 词典中其他单词逐步添加一个字母组成。
//
// 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
//
//
//
// 示例 1：
//
//
// 输入：words = ["w","wo","wor","worl", "world"]
// 输出："world"
// 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
//
//
// 示例 2：
//
//
// 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// 输出："apple"
// 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
//
//
//
//
// 提示：
//
//
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 30
// 所有输入的字符串 words[i] 都只包含小写字母。
//
// Related Topics 字典树 数组 哈希表 字符串 排序 👍 231 👎 0

#define WIDTH 26
typedef struct trie_node_t *trie_t;
struct trie_node_t {
    char *str;
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
    cur->str = s;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
void dfs(trie_t t, int len, int *depth, char **ans) {
    if (*depth < len) *depth = len, *ans = t->str;
    for (int i = 0; i < WIDTH; ++i) {
        if (!t->next[i] || !t->next[i]->str) continue;
        dfs(t->next[i], len + 1, depth, ans);
    }
}
char *longestWord(char **words, int size) {
    int depth   = 0;
    char *ans   = "";
    trie_t trie = trie_create();

    for (int i = 0; i < size; trie_insert(trie, words[i++])) {}
    dfs(trie, 0, &depth, &ans);
    trie_free(trie);

    return ans;
}
