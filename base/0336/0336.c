
// 给定一组 互不相同 的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
//
//
//
// 示例 1：
//
// 输入：["abcd","dcba","lls","s","sssll"]
// 输出：[[0,1],[1,0],[3,2],[2,4]]
// 解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
// 示例 2：
//
// 输入：["bat","tab","cat"]
// 输出：[[0,1],[1,0]]
// 解释：可拼接成的回文串为 ["battab","tabbat"]
// Related Topics 字典树 哈希表 字符串
// 👍 131 👎 0

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define NONE  INT32_MIN
#define WIDTH 26
#define MAXN  0xffff

typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int pos;
    trie_t next[WIDTH];
};
int help[MAXN][2] = { 0 }, help_len = 0;

trie_t trie_create() {
    trie_t t = calloc(1, sizeof(struct trie_node_t));

    t->pos = NONE;
    for (int i = 0; i < WIDTH; ++i) {
        t->next[i] = NULL;
    }

    return t;
}
void trie_insert(trie_t t, char *s, int pos, int *len) {
    trie_t cur = t;

    *len = 0;
    while (*s) {
        if (!cur->next[*s - 'a']) cur->next[*s - 'a'] = trie_create();
        cur = cur->next[*s - 'a'];
        s++, (*len)++;
    }
    cur->pos = pos;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; ++i) {
        trie_free(t->next[i]);
    }
    free(t);
}
bool isPalindrome(const char *str, int beg, int end) {
    while (beg < end) {
        if (str[beg++] != str[end--]) return false;
    }
    return true;
}
void record(int a, int b) {
    help[help_len][0] = a;
    help[help_len][1] = b;
    assert(help_len++ < MAXN);
}
trie_t trie_reverse_search(trie_t t, const char *str, int beg, int end) {
    trie_t cur = t;

    while (cur && end-- > beg) {
        cur = cur->next[str[end] - 'a'];
    }
    return cur;
}
int **palindromePairs(char **words, int wordsSize, int *returnSize, int **returnColumnSizes) {
    trie_t trip = trie_create();
    int **ans = NULL, lens[MAXN] = { 0 };

    for (int i = 0; i < wordsSize; ++i) {
        trie_insert(trip, words[i], i, &lens[i]);
    }
    help_len = 0;
    for (int i = 0; i < wordsSize; ++i) {
        // 查找当前串逆序
        trie_t reverse = trie_reverse_search(trip, words[i], 0, lens[i]);
        if (reverse && reverse->pos >= 0 && reverse->pos < i) {
            record(i, reverse->pos);
            record(reverse->pos, i);
        }

        // 字符串前半部分是回文
        for (int j = 0; j < lens[i]; ++j) {
            if (isPalindrome(words[i], 0, j)) {
                trie_t left = trie_reverse_search(trip, words[i], j + 1, lens[i]);
                if (left && left->pos >= 0 && left->pos != i) {
                    record(left->pos, i);
                }
            }
        }

        // 字符串后半部分是回文
        for (int j = 0; j < lens[i]; ++j) {
            if (isPalindrome(words[i], j, lens[i] - 1)) {
                trie_t right = trie_reverse_search(trip, words[i], 0, j);
                if (right && right->pos >= 0 && right->pos != i) {
                    record(i, right->pos);
                }
            }
        }
    }

    trie_free(trip);

    *returnSize = help_len;
    ans = calloc(help_len, sizeof(int *)), *returnColumnSizes = calloc(help_len, sizeof(int));
    for (int i = 0; i < help_len; ++i) {
        (*returnColumnSizes)[i] = 2;

        ans[i] = calloc(2, sizeof(int));
        memcpy(ans[i], help[i], 2 * sizeof(int));
    }
    return ans;
}