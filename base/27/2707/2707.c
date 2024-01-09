// 给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。
// 你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在dictionary 中出现过。
// s 中可能会有一些 额外的字符 不在任何子字符串中。
//
// 请你采取最优策略分割 s ，使剩下的字符 最少 。
//
//
//
// 示例 1：
//
// 输入：s = "leetscode", dictionary = ["leet","code","leetcode"]
// 输出：1
// 解释：将 s 分成两个子字符串：下标从 0 到 3 的 "leet" 和下标从 5 到 8 的 "code" 。
// 只有 1 个字符没有使用（下标为 4），所以我们返回 1 。
//
//
// 示例 2：
//
// 输入：s = "sayhelloworld", dictionary = ["hello","world"]
// 输出：3
// 解释：将 s 分成两个子字符串：下标从 3 到 7 的 "hello" 和下标从 8 到 12 的 "world" 。
// 下标为 0 ，1 和 2 的字符没有使用，所以我们返回 3 。
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] 和 s 只包含小写英文字母。
// dictionary 中的单词互不相同。
//
//
// Related Topics 字典树 数组 哈希表 字符串 动态规划 👍 62 👎 0

#define WIDTH 26
typedef struct trie_node_t *trie_t;
struct trie_node_t {
    int len;
    trie_t next[WIDTH];
};
trie_t trie_create() {
    return calloc(1, sizeof(struct trie_node_t));
}
void trie_insert(trie_t t, char *s) {
    int len;
    trie_t cur = t;
    for (len = 0; s[len]; cur = cur->next[s[len++] - 'a']) {
        if (!cur->next[s[len] - 'a']) cur->next[s[len] - 'a'] = trie_create();
    }
    cur->len = len;
}
void trie_free(trie_t t) {
    if (!t) return;
    for (int i = 0; i < WIDTH; trie_free(t->next[i++])) {}
    free(t);
}
int minExtraChar(char *s, char **dictionary, int size) {
    size_t len = strlen(s);
    int dp[len + 1];
    trie_t t = trie_create(), p;

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < size; trie_insert(t, dictionary[i++])) {}
    for (int i = 0; i < len; ++i) {
        p = t, dp[i + 1] = fmin(dp[i + 1], dp[i] + 1);
        for (int j = 0; p && s[i + j]; ++j) {
            p = p->next[s[i + j] - 'a'];
            if (p && p->len) dp[i + p->len] = fmin(dp[i + p->len], dp[i]);
        }
    }
    trie_free(t);
    return dp[len];
}
