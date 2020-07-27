//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
// 示例 1:
//
// 输入: "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//
// 示例 2:
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//
// 示例 3:
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//
// Related Topics 哈希表 双指针 字符串 Sliding Window
// 👍 4028 👎 0

int lengthOfLongestSubstring_01(char *s) {
    if (!s || !*s) return 0;

    int beg = 0, end = 0, len = 0;

    while (s[++end]) {
        int t;
        bool flag = true;
        for (t = end - 1; t >= beg; t--) {
            if (s[t] == s[end]) {
                flag = false;
                break;
            }
        }
        if (flag) { continue; }

        // update len
        if (len < end - beg) { len = end - beg; }
        if (beg < t) { beg = t; }
        beg++;
    }
    if (len < end - beg) { len = end - beg; }

    return len;
}

int lengthOfLongestSubstring_02(char *s) {
    if (!s || !*s) return 0;

    int beg, end, len = 0, map[128] = {0};

    for (beg = 0, end = 1; s[end] ; ++end) {
        map[s[end - 1]] = end;

        if (map[s[end]] > beg) {
            if (len < end - beg) {
                len = end - beg;
            }
            beg = map[s[end]];
        }
    }
    if (len < end - beg) len = end - beg;

    return len;
}

int (*lengthOfLongestSubstring)(char *) = lengthOfLongestSubstring_02;