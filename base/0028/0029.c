// 实现 strStr() 函数。
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
// 果不存在，则返回 -1。
//
// 示例 1:
//
// 输入: haystack = "hello", needle = "ll"
// 输出: 2
//
//
// 示例 2:
//
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
//
//
// 说明:
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
// Related Topics 双指针 字符串
// 👍 531 👎 0

int strStr(char *haystack, char *needle) {
    if (!haystack || !needle) return -1;

    int next[0x10000] = { -1 }, pa = 0, pb = -1;
    while (needle[pa]) {
        if (pb == -1 || needle[pa] == needle[pb]) {
            pa += 1, pb += 1, next[pa] = pb;
        } else {
            pb = next[pb];
        }
    };
    for (pa = pb = 0; haystack[pa] && (pb < 0 || needle[pb]);) {
        if (pb == -1 || haystack[pa] == needle[pb]) {
            pa += 1, pb += 1;
        } else {
            pb = next[pb];
        }
    }

    if (pb >= 0 && !needle[pb]) return pa - pb;
    ;
    return -1;
}