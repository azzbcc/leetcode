// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//
// 换句话说，第一个字符串的排列之一是第二个字符串的子串。
//
// 示例1:
//
//
// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").
//
//
//
//
// 示例2:
//
//
// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False
//
//
//
//
// 注意：
//
//
// 输入的字符串只包含小写字母
// 两个字符串的长度都在 [1, 10,000] 之间
//
// Related Topics 双指针 Sliding Window
// 👍 256 👎 0

#define WIDTH 26
bool checkInclusion(char *s1, char *s2) {
    int len, sc[WIDTH] = { 0 };
    bool st[WIDTH] = { false };
    for (len = 0; s1[len]; len++) {
        st[s1[len] - 'a'] = true, sc[s1[len] - 'a']++;
    }
    for (int beg = 0, end = 0; s2[end]; ++end) {
        if (st[s2[end] - 'a']) {
            for (; !sc[s2[end] - 'a']; sc[s2[beg++] - 'a']++) {}
            sc[s2[end] - 'a']--;
        } else {
            for (; beg < end; sc[s2[beg++] - 'a']++) {}
            beg++;
        }
        if (len == end - beg + 1) return true;
    }
    return false;
}
