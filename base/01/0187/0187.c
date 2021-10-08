// 所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA
// 中的重复序列有时会对研究非常有帮助。
//
// 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
//
//
//
// 示例 1：
//
//
// 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// 输出：["AAAAACCCCC","CCCCCAAAAA"]
//
//
// 示例 2：
//
//
// 输入：s = "AAAAAAAAAAAAA"
// 输出：["AAAAAAAAAA"]
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 10⁵
// s[i] 为 'A'、'C'、'G' 或 'T'
//
// Related Topics 位运算 哈希表 字符串 滑动窗口 哈希函数 滚动哈希 👍 245 👎 0

#if 0
typedef struct {
    int count;
    char str[11];
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, const char *str) {
    hash_t cur;
    HASH_FIND(hh, *t, str, 10 * sizeof(char), cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->count = 0, sprintf(cur->str, "%.10s", str);
        HASH_ADD_STR(*t, str, cur);
    }
    cur->count += 1;
}
char **findRepeatedDnaSequences(char *s, int *returnSize) {
    size_t len = strlen(s);
    char *help[len + 1];
    hash_t hash = NULL, cur, next;

    for (int i = 0; i + 10 <= len; ++i) {
        hash_record(&hash, s + i);
    }

    len = 0;
    HASH_ITER(hh, hash, cur, next) {
        if (cur->count > 1) help[len++] = strdup(cur->str);
        HASH_DEL(hash, cur);
        free(cur);
    }

    char **ans = malloc((*returnSize = len) * sizeof(char *));
    memcpy(ans, help, len * sizeof(char *));
    return ans;
}
#else
#define MAXN 10000
typedef struct {
    int mask, count;
    UT_hash_handle hh;
} * hash_t;
char *help[MAXN], *MASK = "ACGT";
int ctoi(char ch) {
    return strchr(MASK, ch) - MASK;
}
void hash_record(hash_t *t, int mask) {
    hash_t cur;
    HASH_FIND_INT(*t, &mask, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->mask = mask, cur->count = 0;
        HASH_ADD_INT(*t, mask, cur);
    }
    cur->count += 1;
}
char *mask_dump(int mask) {
    static char str[11] = { '\0' };
    for (int i = 9; i >= 0; --i, mask >>= 2) {
        str[i] = MASK[mask & 0x3];
    }
    return strdup(str);
}
char **findRepeatedDnaSequences(char *s, int *returnSize) {
    int len = 0, mask = 0;
    hash_t hash = NULL, cur, next;

    for (int i = 0; s[i]; ++i) {
        mask = mask << 2 & 0xfffff | ctoi(s[i]);
        if (i < 9) continue;
        hash_record(&hash, mask);
    }
    HASH_ITER(hh, hash, cur, next) {
        if (cur->count > 1) help[len++] = mask_dump(cur->mask);
        HASH_DEL(hash, cur);
        free(cur);
    }

    char **ans = malloc((*returnSize = len) * sizeof(char *));
    memcpy(ans, help, len * sizeof(char *));
    return ans;
}
#endif