// 累加数 是一个字符串，组成它的数字可以形成累加序列。
//
// 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
//
// 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false
// 。
//
// 说明：累加序列里的数 不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
//
//
//
// 示例 1：
//
//
// 输入："112358"
// 输出：true
// 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//
//
// 示例 2：
//
//
// 输入："199100199"
// 输出：true
// 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
//
//
//
// 提示：
//
//
// 1 <= num.length <= 35
// num 仅由数字（0 - 9）组成
//
//
//
//
// 进阶：你计划如何处理由过大的整数输入导致的溢出?
// Related Topics 字符串 回溯 👍 242 👎 0

#define MAXN 35
typedef struct {
    int size;
    long data[MAXN];
} data_t;
bool dfs(char *num, int max, data_t *s) {
    if (s->size >= 3 && s->data[s->size - 1] != s->data[s->size - 2] + s->data[s->size - 3]) return false;
    if (*num == '\0') return s->size >= 3;

    s->data[s->size++] = *num - '0';
    if (dfs(num + 1, max, s)) return true;
    for (int i = 1; *num != '0' && num[i] && i <= max; ++i) {
        s->data[s->size - 1] *= 10, s->data[s->size - 1] += num[i] - '0';
        if (dfs(num + i + 1, max, s)) return true;
    }
    s->size--;

    return false;
}
bool isAdditiveNumber(char *num) {
    data_t stack = { 0 };
    return dfs(num, strlen(num) / 2, &stack);
}
