// 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除
// s中的某些字符得到。
//
// 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
//
//
//
// 示例 1：
//
//
// 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// 输出："apple"
//
//
// 示例 2：
//
//
// 输入：s = "abpcplea", dictionary = ["a","b","c"]
// 输出："a"
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 1000
// s 和 dictionary[i] 仅由小写英文字母组成
//
// Related Topics 数组 双指针 字符串 排序 👍 200 👎 0

typedef struct {
    int len;
    char *str;
} string_t;
bool match(char *s, char *d) {
    for (; *s && *d; ++s) {
        if (*s == *d) ++d;
    }
    return *d == '\0';
}
int cmp(const void *a, const void *b) {
    string_t *pa = ( string_t * )a, *pb = ( string_t * )b;
    if (pa->len == pb->len) return strcmp(pa->str, pb->str);
    return pb->len - pa->len;
}
char *findLongestWord(char *s, char **dictionary, int size) {
    string_t ss[size];
    int len = strlen(s);
    for (int i = 0; i < size; ++i) {
        ss[i] = (string_t) { strlen(dictionary[i]), dictionary[i] };
    }
    qsort(ss, size, sizeof(string_t), cmp);
    for (int i = 0; i < size; ++i) {
        if (ss[i].len > len) continue;
        if (match(s, ss[i].str)) return ss[i].str;
    }
    return "";
}