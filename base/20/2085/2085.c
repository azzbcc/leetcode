// 给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。
//
//
//
// 示例 1：
//
//
// 输入：words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
// 输出：2
// 解释：
// - "leetcode" 在两个数组中都恰好出现一次，计入答案。
// - "amazing" 在两个数组中都恰好出现一次，计入答案。
// - "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
// - "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
// 所以，有 2 个字符串在两个数组中都恰好出现了一次。
//
//
// 示例 2：
//
//
// 输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
// 输出：0
// 解释：没有字符串在两个数组中都恰好出现一次。
//
//
// 示例 3：
//
//
// 输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
// 输出：1
// 解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
//
//
//
//
// 提示：
//
//
// 1 <= words1.length, words2.length <= 1000
// 1 <= words1[i].length, words2[j].length <= 30
// words1[i] 和 words2[j] 都只包含小写英文字母。
//
//
// Related Topics 数组 哈希表 字符串 计数 👍 25 👎 0

typedef struct {
    char *str;
    int count;
    UT_hash_handle hh;
} hash_t;
void hash_record(hash_t **t, hash_t *node, int plus) {
    hash_t *cur;
    HASH_FIND_STR(*t, node->str, cur);
    if (!cur) {
        cur = node;
        HASH_ADD_STR(*t, str, cur);
    }
    cur->count += plus;
}
int countWords(char **words1, int words1Size, char **words2, int words2Size) {
    int ans = 0;
    hash_t *cur, *next, *hash = NULL;
    hash_t nodes[words1Size + words2Size];
    for (int i = 0; i < words1Size; ++i) {
        nodes[i] = (hash_t) { words1[i] };
        hash_record(&hash, &nodes[i], 1);
    }
    for (int i = 0; i < words2Size; ++i) {
        nodes[words1Size + i] = (hash_t) { words2[i] };
        hash_record(&hash, &nodes[words1Size + i], 1000);
    }
    HASH_ITER(hh, hash, cur, next) ans += cur->count == 1001;
    HASH_CLEAR(hh, hash);
    return ans;
}
