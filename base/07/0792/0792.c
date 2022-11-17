// 给定字符串 s 和字符串数组 words, 返回 words[i] 中是s的子序列的单词个数 。
//
// 字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。
//
//
// 例如， “ace” 是 “abcde” 的子序列。
//
//
//
//
// 示例 1:
//
//
// 输入: s = "abcde", words = ["a","bb","acd","ace"]
// 输出: 3
// 解释: 有三个是s 的子序列的单词: "a", "acd", "ace"。
//
//
// Example 2:
//
//
// 输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
// 输出: 2
//
//
//
//
// 提示:
//
//
// 1 <= s.length <= 5 * 10⁴
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 50
// words[i]和 s 都只由小写字母组成。
//
//
//
// Related Topics 字典树 哈希表 字符串 排序 👍 284 👎 0

#define MAX 26
typedef struct {
    int index;
    char *str;
    UT_hash_handle hh;
} * hash_t, hash_node_t;
int numMatchingSubseq(char *s, char **words, int size) {
    int ans = 0;
    hash_node_t nodes[size];
    hash_t ss[MAX] = { NULL }, cur, next;
    for (int i = 0; i < size; ++i) {
        nodes[i] = (hash_node_t) { i, words[i] };
        HASH_ADD_INT(ss[words[i][0] - 'a'], index, &nodes[i]);
    }
    for (char *p = s; *p; ++p) {
        HASH_ITER(hh, ss[*p - 'a'], cur, next) {
            if (cur->str++, *cur->str != *(cur->str - 1)) {
                HASH_DEL(ss[*p - 'a'], cur);
                if (*cur->str) {
                    HASH_ADD_INT(ss[*cur->str - 'a'], index, cur);
                } else {
                    ans++;
                }
            }
        }
    }
    for (int i = 0; i < MAX; ++i) {
        HASH_CLEAR(hh, ss[i]);
    }
    return ans;
}