// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
//
//
//
// 示例 1:
//
//
// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//
//
// 示例 2:
//
//
// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
//
//
//
//
// 提示:
//
//
// 1 <= s.length, p.length <= 3 * 10⁴
// s 和 p 仅包含小写字母
//
// Related Topics 哈希表 字符串 滑动窗口 👍 715 👎 0

#define WIDTH 26
int *findAnagrams(char *s, char *p, int *returnSize) {
    size_t sl = strlen(s), sp = strlen(p);
    if (sl < sp) return malloc(*returnSize = 0);

    int cc[WIDTH] = { 0 }, diff = 0;
    for (int i = 0; i < sp; ++i) {
        cc[s[i] - 'a']++, cc[p[i] - 'a']--;
    }
    for (int i = 0; i < WIDTH; diff += cc[i++] != 0) {}

    int help[sl], len = 0;
    if (!diff) help[len++] = 0;
    for (int i = 0, j = sp; j < sl; ++i, ++j) {
        if (s[i] != s[j]) {
            cc[s[i] - 'a']--, cc[s[j] - 'a']++;
            if (cc[s[i] - 'a'] == 0) {
                diff--;
            } else if (cc[s[i] - 'a'] == -1) {
                diff++;
            }
            if (cc[s[j] - 'a'] == 0) {
                diff--;
            } else if (cc[s[j] - 'a'] == 1) {
                diff++;
            }
        }
        if (!diff) help[len++] = i + 1;
    }

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    return ans;
}
