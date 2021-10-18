// 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true
// ；否则返回 false 。
//
// 交换字母的定义是取两个下标 i 和 j （下标从 0 开始），只要 i!=j 就交换 A[i] 和 A[j] 处的字符。例如，在 "abcd"
// 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
//
//
//
// 示例 1：
//
//
// 输入： A = "ab", B = "ba"
// 输出： true
// 解释： 你可以交换 A[0] = 'a' 和 A[1] = 'b' 生成 "ba"，此时 A 和 B 相等。
//
// 示例 2：
//
//
// 输入： A = "ab", B = "ab"
// 输出： false
// 解释： 你只能交换 A[0] = 'a' 和 A[1] = 'b' 生成 "ba"，此时 A 和 B 不相等。
//
//
// 示例 3:
//
//
// 输入： A = "aa", B = "aa"
// 输出： true
// 解释： 你可以交换 A[0] = 'a' 和 A[1] = 'a' 生成 "aa"，此时 A 和 B 相等。
//
// 示例 4：
//
//
// 输入： A = "aaaaaaabc", B = "aaaaaaacb"
// 输出： true
//
//
// 示例 5：
//
//
// 输入： A = "", B = "aa"
// 输出： false
//
//
//
//
// 提示：
//
//
// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A 和 B 仅由小写字母构成。
//
// Related Topics 哈希表 字符串 👍 157 👎 0

#define WIDTH 26
bool buddyStrings(char *s, char *goal) {
    bool repeat = false;
    int len = 0, diff = 0, pos[3] = { 0 };
    for (int dict[WIDTH] = { 0 }; diff <= 2 && s[len] && goal[len]; ++len) {
        repeat |= dict[s[len] - 'a']++;
        if (s[len] != goal[len]) pos[diff++] = len;
    }
    if (diff == 0 && repeat) diff = 2;
    if (diff != 2) return false;
    if (s[len] || goal[len]) return false;
    return s[pos[0]] == goal[pos[1]] && s[pos[1]] == goal[pos[0]];
}
