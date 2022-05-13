// 字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。
// 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
//
//
//
// 示例 1:
//
// 输入:
// first = "pale" second = "ple"
// 输出: True
//
//
//
// 示例 2:
//
// 输入:
// first = "pales" second = "pal"
// 输出: False
//
// Related Topics 双指针 字符串 👍 169 👎 0

bool oneEditDiff(char *sa, int la, char *sb, int lb) {
    if (la < lb) return oneEditDiff(sb, lb, sa, la);
    if (la != lb + 1) return false;
    for (int i = 0, j = 0; i < la; ++i, ++j) {
        if (sa[i] == sb[j]) continue;
        if (sa[++i] != sb[j]) return false;
    }
    return true;
}
bool oneEditAway(char *first, char *second) {
    size_t lf = strlen(first), ls = strlen(second);
    if (lf != ls) return oneEditDiff(first, lf, second, ls);
    for (int i = 0, j = 0, diff = 0; first[i]; ++i, ++j) {
        if (first[i] == second[j]) continue;
        if (diff++) return false;
    }
    return true;
}
