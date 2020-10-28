// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
// 示例:
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
// ]
//
// 说明：
//
//
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
//
// Related Topics 哈希表 字符串
// 👍 502 👎 0

#define WIDTH 26
#define SIZE  1000

typedef struct str_list {
    char *str;
    struct str_list *next;
} str_list_t;
typedef struct hash {
    char *key;
    int len;
    str_list_t *list;
    UT_hash_handle hh;
} * hash_t;

int cmp(const void *a, const void *b) {
    return *( char * )a - *( char * )b;
}
char *sorted_str(const char *str) {
    size_t len               = strlen(str);
    static char string[SIZE] = { '\0' };

    memcpy(string, str, len + 1);
    qsort(string, len, 1, cmp);

    return string;
}
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    char ***ans;
    hash_t t = NULL;
    str_list_t nodes[strsSize];

    for (int i = 0; i < strsSize; ++i) {
        hash_t cur = NULL;
        char *key  = sorted_str(strs[i]);

        nodes[i].str = strs[i], nodes[i].next = NULL;

        HASH_FIND_STR(t, key, cur);
        if (cur == NULL) {
            cur      = calloc(1, sizeof(struct hash));
            cur->key = strdup(key), cur->len = 1, cur->list = &nodes[i];
            HASH_ADD_STR(t, key, cur);
        } else {
            nodes[i].next = cur->list, cur->len++, cur->list = &nodes[i];
        }
    }

    // ans
    *returnSize = HASH_COUNT(t), ans = calloc(*returnSize, sizeof(char **)),
    *returnColumnSizes = calloc(*returnSize, sizeof(int));

    for (int i = 0, len; i < *returnSize; ++i) {
        hash_t cur = t;
        len = 0, (*returnColumnSizes)[i] = cur->len, ans[i] = calloc(cur->len, sizeof(char *));

        for (str_list_t *l = cur->list; l; l = l->next) {
            ans[i][len++] = l->str;
        }

        HASH_DEL(t, cur);
        free(cur->key);
        free(cur);
    }

    return ans;
}
