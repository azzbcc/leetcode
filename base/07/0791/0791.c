// 字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
//
// S
// 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
//
// 返回任意一种符合条件的字符串T。
//
//
// 示例:
// 输入:
// S = "cba"
// T = "abcd"
// 输出: "cbad"
// 解释:
// S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a".
// 由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
//
//
// 注意:
//
//
// S的最大长度为26，其中没有重复的字符。
// T的最大长度为200。
// S和T只包含小写字符。
//
// Related Topics 字符串
// 👍 73 👎 0

#define WIDTH 26

int ss[WIDTH];
int cmp(const void *a, const void *b) {
    int pa = *( char * )a - 'a', pb = *( char * )b - 'a';
    if (ss[pa] == ss[pb]) return pa - pb;
    return ss[pa] - ss[pb];
}
char *customSortString(char *S, char *T) {
    memset(ss, -1, sizeof(ss));

    for (int i = 0; S[i]; ++i) {
        ss[S[i] - 'a'] = i;
    }
    qsort(T, strlen(T), sizeof(char), cmp);

    return T;
}
