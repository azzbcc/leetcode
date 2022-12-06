// 给你一个字符串 word ，该字符串由数字和小写英文字母组成。
//
// 请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123 34 8 34"
// 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。
//
// 返回对 word 完成替换后形成的 不同 整数的数目。
//
// 只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。
//
//
//
// 示例 1：
//
//
// 输入：word = "a123bc34d8ef34"
// 输出：3
// 解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
//
//
// 示例 2：
//
//
// 输入：word = "leet1234code234"
// 输出：2
//
//
// 示例 3：
//
//
// 输入：word = "a1b01c001"
// 输出：1
// 解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
//
//
//
//
// 提示：
//
//
// 1 <= word.length <= 1000
// word 由数字和小写英文字母组成
//
//
// Related Topics 哈希表 字符串 👍 53 👎 0

#define MAXN 1000
typedef struct {
    char str[MAXN + 1];
    UT_hash_handle hh;
} *hash_t;
void hash_record(hash_t *t, char *str) {
    hash_t find = NULL;
    HASH_FIND_STR(*t, str, find);
    if (find) return;
    find = malloc(sizeof(*find));
    strcpy(find->str, str);
    HASH_ADD_STR(*t, str, find);
}
int numDifferentIntegers(char *word) {
    int len = 0;
    char str[MAXN + 1];
    hash_t cur, next, hash = NULL;
    for (char *p = word; *p; ++p) {
        if (isdigit(*p)) {
            if (len == 1 && str[0] == '0') len--;
            str[len++] = *p;
        } else if (len) {
            str[len] = '\0', len = 0;
            hash_record(&hash, str);
        }
    }
    str[len] = '\0';
    if (len) hash_record(&hash, str);

    int ans = HASH_COUNT(hash);
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
