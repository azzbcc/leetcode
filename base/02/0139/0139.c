// 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
// 说明：
//
//
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
//
//
// 示例 1：
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//
//
// 示例 2：
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
//
//
// 示例 3：
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false
//
// Related Topics 动态规划
// 👍 687 👎 0

#define MAXN  1000
#define WIDTH 128

typedef struct trie_node {
    bool exists;
    struct trie_node *next[WIDTH];
} * trie_t;
trie_t trie_create() {
    trie_t t = calloc(1, sizeof(struct trie_node));

    t->exists = false;
    for (int i = 0; i < WIDTH; ++i) {
        t->next[i] = NULL;
    }
    return t;
}
void trie_add(trie_t t, char *s) {
    for (; *s; s++) {
        if (!t->next[*s]) t->next[*s] = trie_create();
        t = t->next[*s];
    }
    t->exists = true;
}
void trie_dump(trie_t t, char *res, int len) {
    if (t->exists) {
        res[len] = '\0';
        puts(res);
    }
    for (int i = 0; i < WIDTH; ++i) {
        if (t->next[i]) {
            res[len] = i;
            trie_dump(t->next[i], res, len + 1);
        }
    }
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; ++i) {
        trie_free(t->next[i]);
    }
    free(t);
}
bool dfs(trie_t t, char *s) {
    if (!*s) return true;

    for (trie_t tmp = t->next[*s]; tmp && *s; tmp = tmp->next[*++s]) {
        if (tmp->exists && dfs(t, s + 1)) return true;
    }
    return false;
}
bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    trie_t t = trie_create();
    for (int i = 0; i < wordDictSize; ++i) {
        trie_add(t, wordDict[i]);
    }

    bool ans = dfs(t, s);

    trie_free(t);

    return ans;
}
