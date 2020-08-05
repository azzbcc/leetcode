//编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。
//
// 示例 1:
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
//
//
// 示例 2:
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
//
//
// 说明:
//
// 所有输入只包含小写字母 a-z 。
// Related Topics 字符串
// 👍 1199 👎 0

char *longestCommonPrefix(char **strs, int strsSize) {
    int pos               = 0;
    static char ans[1024] = { '\0' };

    while (strsSize && strs[0][pos]) {
        for (int i = 1; i < strsSize; ++i) {
            if (strs[i][pos] != strs[0][pos]) {
                ans[pos] = '\0';
                return ans;
            }
        }
        ans[pos] = strs[0][pos];
        pos += 1;
    }

    ans[pos] = '\0';
    return ans;
}
