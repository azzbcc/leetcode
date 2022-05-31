// 现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
//
// 给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
//
// 请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 ""
// 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
//
// 字符串 s 字典顺序小于 字符串 t 有两种情况：
//
//
// 在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
// 如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。
//
//
//
//
// 示例 1：
//
//
// 输入：words = ["wrt","wrf","er","ett","rftt"]
// 输出："wertf"
//
//
// 示例 2：
//
//
// 输入：words = ["z","x"]
// 输出："zx"
//
//
// 示例 3：
//
//
// 输入：words = ["z","x","z"]
// 输出：""
// 解释：不存在合法字母顺序，因此返回 "" 。
//
//
//
//
// 提示：
//
//
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] 仅由小写英文字母组成
//
//
//
//
// 注意：本题与主站 269 题相同： https://leetcode-cn.com/problems/alien-dictionary/
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 数组 字符串 👍 49 👎 0

#define MAXN  100
#define WIDTH 26
typedef enum {
    NONE,
    VISITING,
    VISITED,
} state_t;
typedef struct {
    char from, to;
    bool deleted;
} pair_t;
typedef struct {
    int size;
    pair_t pairs[MAXN];
} node_t;
pair_t pair_get(char *a, char *b) {
    for (int i = 0; a[i] || b[i]; ++i) {
        if (a[i] == b[i]) continue;
        return (pair_t) { a[i], b[i] };
    }
    return (pair_t) { '\0' };
}
bool dfs(char cur, bool exists[], state_t state[], node_t *node, char *ans, int *index) {
    if (state[cur - 'a']) return false;
    state[cur - 'a'] = VISITING;
    for (int i = 0; i < node->size; ++i) {
        if (node->pairs[i].deleted) continue;
        if (node->pairs[i].from != cur) continue;
        if (!dfs(node->pairs[i].to, exists, state, node, ans, index)) return false;
    }

    state[cur - 'a'] = VISITED, exists[cur - 'a'] = false, ans[--*index] = cur;
    for (int i = 0; i < node->size; ++i) {
        if (node->pairs[i].deleted) continue;
        if (node->pairs[i].from == cur || node->pairs[i].to == cur) node->pairs[i].deleted = true;
    }
    return true;
}
char *alienOrder(char **words, int size) {
    static char str[WIDTH + 1] = { '\0' };
    node_t node[1]             = { 0 };
    state_t state[WIDTH]       = { NONE };
    bool exists[WIDTH]         = { false };
    for (int i = 0; words[0][i]; exists[words[0][i++] - 'a'] = true) {}
    for (int i = 1; i < size; ++i) {
        for (int j = 0; words[i][j]; exists[words[i][j++] - 'a'] = true) {}
        node->pairs[node->size] = pair_get(words[i - 1], words[i]);
        if (!node->pairs[node->size].to && node->pairs[node->size].from) return "";
        if (node->pairs[node->size].from) node->size++;
    }

    int index = WIDTH;
    for (int i = 0; i < WIDTH; ++i) {
        if (!exists[i]) continue;
        if (!dfs('a' + i, exists, state, node, str, &index)) return "";
    }
    return &str[index];
}
