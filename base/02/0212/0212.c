// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
//
// 单词必须按照字母顺序，通过 相邻的单元格
// 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//
//
//
// 示例 1：
//
//
// 输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
// ["oath","pea","eat","rain"] 输出：["eat","oath"]
//
//
// 示例 2：
//
//
// 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
// 输出：[]
//
//
//
//
// 提示：
//
//
// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] 是一个小写英文字母
// 1 <= words.length <= 3 * 10⁴
// 1 <= words[i].length <= 10
// words[i] 由小写英文字母组成
// words 中的所有字符串互不相同
//
// Related Topics 字典树 数组 字符串 回溯 矩阵 👍 472 👎 0

typedef struct trie_node_t {
    char ch, *str;
    UT_hash_handle hh;
    struct trie_node_t *next;
} * trie_t;
void trie_record(trie_t *trie, char *str) {
    trie_t cur = NULL, *t = trie;
    for (char *p = str; *p; ++p) {
        HASH_FIND(hh, *t, p, sizeof(char), cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->ch = *p, cur->str = NULL, cur->next = NULL;
            HASH_ADD(hh, *t, ch, sizeof(char), cur);
        }
        t = &cur->next;
    }
    cur->str = str;
}
void trie_free(trie_t t) {
    trie_t cur, next;
    HASH_ITER(hh, t, cur, next) {
        HASH_DEL(t, cur);
        trie_free(cur->next);
        free(cur);
    }
}

#define MAXN 3000
typedef struct {
    int x, y;
} point_t;
int help_len;
char *help[MAXN];
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
void dfs(int m, int n, char **board, trie_t t, point_t now, bool visited[m][n]) {
    trie_t cur, next;
    if (t->str) help[help_len++] = t->str, t->str = NULL;
    visited[now.x][now.y] = true;
    HASH_ITER(hh, t->next, cur, next) {
        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            point_t ne = (point_t) { now.x + wards[i].x, now.y + wards[i].y };
            if (ne.x < 0 || ne.x >= m || ne.y < 0 || ne.y >= n) continue;
            if (visited[ne.x][ne.y] || board[ne.x][ne.y] != cur->ch) continue;
            dfs(m, n, board, cur, ne, visited);
        }
    }
    visited[now.x][now.y] = false;
}
char **findWords(char **board, int size, int *colSize, char **words, int wordsSize, int *returnSize) {
    trie_t trie = NULL, cur;
    bool visited[size][*colSize];

    help_len = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < wordsSize; ++i) {
        trie_record(&trie, words[i]);
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            HASH_FIND(hh, trie, &board[i][j], sizeof(char), cur);
            if (!cur) continue;
            dfs(size, *colSize, board, cur, (point_t) { i, j }, visited);
        }
    }
    trie_free(trie);

    char **ans = malloc((*returnSize = help_len) * sizeof(char *));
    memcpy(ans, help, help_len * sizeof(sizeof(char *)));

    return ans;
}
