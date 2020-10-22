// 字符串 S
// 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//
//
//
// 示例 1：
//
// 输入：S = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca", "defegde", "hijhklij"。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//
//
//
// 提示：
//
//
// S的长度在[1, 500]之间。
// S只包含小写字母 'a' 到 'z' 。
//
// Related Topics 贪心算法 双指针
// 👍 310 👎 0

#define WIDTH 26

int *partitionLabels(char *S, int *returnSize) {
    int last[WIDTH] = { 0 };
    int len = 0, *ans = calloc(WIDTH, sizeof(int));

    for (int i = 0; S[i]; ++i) {
        last[S[i] - 'a'] = i;
    }

    for (int beg = 0, end; S[beg]; beg = end + 1) {
        end = last[S[beg] - 'a'];
        for (int i = beg + 1; i < end; ++i) {
            if (end < last[S[i] - 'a']) end = last[S[i] - 'a'];
        }
        ans[len++] = end - beg + 1;
    }
    *returnSize = len;

    return ans;
}
