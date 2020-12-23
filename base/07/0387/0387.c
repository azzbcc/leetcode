// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//
//
//
// 示例：
//
// s = "leetcode"
// 返回 0
//
// s = "loveleetcode"
// 返回 2
//
//
//
//
// 提示：你可以假定该字符串只包含小写字母。
// Related Topics 哈希表 字符串
// 👍 327 👎 0

#define WIDTH 26

int firstUniqChar(char *s) {
    int sc[WIDTH] = { 0 };
    for (int i = 0; s[i]; ++i) {
        sc[s[i] - 'a']++;
    }
    for (int i = 0; s[i]; ++i) {
        if (sc[s[i] - 'a'] == 1) return i;
    }

    return -1;
}