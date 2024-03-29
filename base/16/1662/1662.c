// 给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
//
// 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
//
//
//
// 示例 1：
//
//
// 输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
// 输出：true
// 解释：
// word1 表示的字符串为 "ab" + "c" -> "abc"
// word2 表示的字符串为 "a" + "bc" -> "abc"
// 两个字符串相同，返回 true
//
// 示例 2：
//
//
// 输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
// 输出：false
//
//
// 示例 3：
//
//
// 输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
// 输出：true
//
//
//
//
// 提示：
//
//
// 1 <= word1.length, word2.length <= 10³
// 1 <= word1[i].length, word2[i].length <= 10³
// 1 <= sum(word1[i].length), sum(word2[i].length) <= 10³
// word1[i] 和 word2[i] 由小写字母组成
//
//
// Related Topics 数组 字符串 👍 49 👎 0

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2, int word2Size) {
    int p1 = 0, p2 = 0;
    for (int q1 = 0, q2 = 0; p1 < word1Size && p2 < word2Size;) {
        if (word1[p1][q1] != word2[p2][q2]) return false;
        if (word1[p1][++q1] == '\0') p1++, q1 = 0;
        if (word2[p2][++q2] == '\0') p2++, q2 = 0;
    }
    return p1 == word1Size && p2 == word2Size;
}
