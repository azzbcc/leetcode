// 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
//
// 示例1:
//
// 输入: pattern = "abba", str = "dog cat cat dog"
// 输出: true
//
// 示例 2:
//
// 输入:pattern = "abba", str = "dog cat cat fish"
// 输出: false
//
// 示例 3:
//
// 输入: pattern = "aaaa", str = "dog cat cat dog"
// 输出: false
//
// 示例 4:
//
// 输入: pattern = "abba", str = "dog dog dog dog"
// 输出: false
//
// 说明:
// 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。
// Related Topics 哈希表
// 👍 248 👎 0

#define WIDTH 26

bool wordPattern(char *pattern, char *str) {
    int st[WIDTH] = { 0 }, lp = 0, ls = 0;

    for (int c = 0; pattern[lp]; ++lp) {
        if (st[pattern[lp] - 'a']) continue;
        st[pattern[lp] - 'a'] = ++c;
    }

    char *save_ptr = NULL, *s = strtok_r(str, " ", &save_ptr);
    for (char *sp[WIDTH] = { NULL }; ls < lp && s; ls++, s = strtok_r(NULL, " ", &save_ptr)) {
        int index = st[pattern[ls] - 'a'] - 1;
        if (!sp[index]) {
            for (int i = 0; i < index; ++i) {
                if (!strcmp(sp[i], s)) return false;
            }
            sp[index] = s;
        } else {
            if (strcmp(sp[index], s) != 0) return false;
        }
    }

    return lp == ls && !s;
}
