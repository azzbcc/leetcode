// 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//
// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
//
//
//
// 示例 1：
//
// 输入：
//  s = "barfoothefoobarman",
//  words = ["foo","bar"]
// 输出：[0,9]
// 解释：
// 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
// 输出的顺序不重要, [9,0] 也是有效答案。
//
//
// 示例 2：
//
// 输入：
//  s = "wordgoodgoodgoodbestword",
//  words = ["word","good","best","word"]
// 输出：[]
//
// Related Topics 哈希表 双指针 字符串
// 👍 362 👎 0

#define WIDTH 26
#define MAXN  0xffff

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int count;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_insert(trie_t t, const char *s, size_t len) {
    trie_t cur = t;
    for (int i = 0; i < len; cur = cur->next[s[i++] - 'a']) {
        if (!cur->next[s[i] - 'a']) cur->next[s[i] - 'a'] = trie_create();
    }
    cur->count += 1;
}
trie_t trie_find(trie_t t, const char *s, size_t len) {
    trie_t cur = t;
    for (int i = 0; i < len && cur; cur = cur->next[s[i++] - 'a']) {}
    return cur;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    trie_t cur, t        = trie_create();
    int *ans, help[MAXN] = { 0 }, help_len = 0;
    size_t len_w = strlen(words[0]), len_s = strlen(s);
    for (int i = 0; i < wordsSize; trie_insert(t, words[i++], len_w)) {}

    for (int i = 0, beg, end, matched; i < len_w; ++i) {
        for (beg = i, end = i, matched = 0; beg + len_w * wordsSize <= len_s;) {
            for (; matched < wordsSize; ++matched) {
                cur = trie_find(t, &s[end], len_w);
                if (!cur || !cur->count) break;
                cur->count -= 1, end += len_w;
            }
            if (matched == wordsSize) {
                matched -= 1, help[help_len++] = beg;
                trie_insert(t, &s[beg], len_w);
                beg += len_w;
            } else if (!cur) {
                for (matched = 0; (cur = trie_find(t, &s[beg], len_w)); beg += len_w) {
                    cur->count += 1;
                }
                beg = end = end + len_w;
            } else {
                for (; !cur->count; beg += len_w, matched--) {
                    trie_insert(t, &s[beg], len_w);
                }
            }
        }
        for (; beg < end && (cur = trie_find(t, &s[beg], len_w)); beg += len_w) {
            cur->count += 1;
        }
    }

    trie_free(t);

    *returnSize = help_len, ans = calloc(help_len, sizeof(int));
    memcpy(ans, help, help_len * sizeof(int));

    return ans;
}
