//给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
//
// 形式上，斐波那契式序列是一个非负整数列表 F，且满足：
//
//
// 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
// F.length >= 3；
// 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
//
//
// 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
//
// 返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。
//
//
//
// 示例 1：
//
// 输入："123456579"
//输出：[123,456,579]
//
//
// 示例 2：
//
// 输入: "11235813"
//输出: [1,1,2,3,5,8,13]
//
//
// 示例 3：
//
// 输入: "112358130"
//输出: []
//解释: 这项任务无法完成。
//
//
// 示例 4：
//
// 输入："0123"
//输出：[]
//解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
//
//
// 示例 5：
//
// 输入: "1101111"
//输出: [110, 1, 111]
//解释: 输出 [11,0,11,11] 也同样被接受。
//
//
//
//
// 提示：
//
//
// 1 <= S.length <= 200
// 字符串 S 中只含有数字。
//
// Related Topics 贪心算法 字符串 回溯算法
// 👍 69 👎 0
static uint32_t arr[200] = { 0 };
bool dfs(const char *s, uint8_t max_len, uint8_t pos, int *len) {
    if (!*s) {
        if (pos > 2) *len = pos;
        return pos > 2;
    }

    uint32_t tsum = 0;
    if (pos >= 2) tsum = arr[pos - 1] + arr[pos - 2];
    if (tsum > INT32_MAX) return false;

    for (uint32_t i = 0, sum = 0; s[i] && i <= max_len && sum <= INT32_MAX / 10 && (!i || sum); ++i) {
        sum *= 10, sum += s[i] - '0';

        if (sum > INT32_MAX) break;
        if (pos >= 2 && sum > tsum) break;
        if (pos >= 2 && sum < tsum) continue;

        arr[pos] = sum;
        if (dfs(s + i + 1, max_len, pos + 1, len)) return true;
    }
    return false;
}
int *splitIntoFibonacci(char *s, int *len) {
    *len = 0;
    dfs(s, strlen(s) / 2, 0, len);

    int *ans = calloc(*len, sizeof(int));
    memcpy(ans, arr, *len * sizeof(int));

    return ans;
}
