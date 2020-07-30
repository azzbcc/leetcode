//我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。
//
// 例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueCh
// ars(s) = 5 。
//
// 本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s
// 的子字符串。注意，某些子字符串可能是重复的，
//但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。
//
// 由于答案可能非常大，请将结果 mod 10 ^ 9 + 7 后再返回。
//
//
//
// 示例 1：
//
// 输入: "ABC"
//输出: 10
//解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
//     其中，每一个子串都由独特字符构成。
//     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
//
//
// 示例 2：
//
// 输入: "ABA"
//输出: 8
//解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
//
//
// 示例 3：
//
// 输入：s = "LEETCODE"
//输出：92
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 10^4
// s 只包含大写英文字符
//
// Related Topics 双指针
// 👍 55 👎 0
#define MAX 10000
#define MOD 1000000007
int uniqueLetterString(char *str) {
    int at[26] = { 0 }, last[MAX] = { 0 }, sum = 0, ans = 0;

    for (int i = 0; str[i]; ++i) {
        last[i]          = at[str[i] - 'A'];
        at[str[i] - 'A'] = i + 1;

        sum += i + 1;
        if (last[i] > 0) {
            sum -= 2 * last[i] - last[last[i] - 1];
        }

        ans += sum, ans %= MOD;
    }

    return ans;
}