// 外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。
//
// 字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：
//
//
// 单词 word 中包含谜面 puzzle 的第一个字母。
// 单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
// 例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"
//（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
//
//
// 返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i]
// 所对应的谜底的单词数目。
//
//
//
// 示例：
//
// 输入：
// words = ["aaaa","asas","able","ability","actt","actor","access"],
// puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
// 输出：[1,1,3,2,4,0]
// 解释：
// 1 个单词可以作为 "aboveyz" 的谜底 : "aaaa"
// 1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
// 3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
// 2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
// 4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
// 没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
//
//
//
//
// 提示：
//
//
// 1 <= words.length <= 10^5
// 4 <= words[i].length <= 50
// 1 <= puzzles.length <= 10^4
// puzzles[i].length == 7
// words[i][j], puzzles[i][j] 都是小写英文字母。
// 每个 puzzles[i] 所包含的字符都不重复。
//
// Related Topics 位运算 哈希表
// 👍 116 👎 0

#define WIDTH 26
#define MAXN  7

typedef struct {
    int mask;
    int count;
    UT_hash_handle hh;
} hash_t;
void hash_record(hash_t **hash, int mask) {
    hash_t *cur;
    HASH_FIND_INT(*hash, &mask, cur);
    if (!cur) {
        cur = malloc(sizeof(hash_t)), cur->mask = mask, cur->count = 0;
        HASH_ADD_INT(*hash, mask, cur);
    }
    cur->count += 1;
}
int hash_count(hash_t *hash, int mask) {
    hash_t *cur;
    HASH_FIND_INT(hash, &mask, cur);
    return cur ? cur->count : 0;
}
void hash_clean(hash_t *hash) {
    hash_t *cur, *next;
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    HASH_CLEAR(hh, hash);
}
void word_record(hash_t **hash, char *s) {
    int c = 0, mask = 0;
    bool flags[WIDTH] = { false };
    for (int ch; c <= MAXN && *s; s++) {
        if (flags[ch = *s - 'a']) continue;
        flags[ch] = true, mask |= 1 << ch, c++;
    }
    if (c <= MAXN) hash_record(hash, mask);
}
int word_count(hash_t *hash, char *s) {
    int count = 0, mask = 0, index = 1 << (*s - 'a');
    for (; *s; mask |= 1 << (*s++ - 'a')) {}
    for (int m = mask; m; m = (m - 1) & mask) {
        if ((m & index) == 0) continue;
        count += hash_count(hash, m);
    }
    return count;
}
int *findNumOfValidWords(char **words, int wordsSize, char **puzzles, int puzzlesSize, int *returnSize) {
    hash_t *hash = NULL;
    int *ans     = malloc((*returnSize = puzzlesSize) * sizeof(int));
    for (int i = 0; i < wordsSize; ++i) {
        word_record(&hash, words[i]);
    }
    for (int i = 0; i < puzzlesSize; ++i) {
        ans[i] = word_count(hash, puzzles[i]);
    }
    hash_clean(hash);
    return ans;
}
