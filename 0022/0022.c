//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
//
// 示例：
//
// 输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
//
// Related Topics 字符串 回溯算法
// 👍 1202 👎 0
#define MAX 208012

void dfs(char *str, int pos, int n, int left, int check, int *retSize, char *retArr[MAX]) {
    if (pos >= 2 * n) {
        retArr[(*retSize)++] = strdup(str);
        assert(*retSize <= MAX);
        return;
    }

    if (left < n) {
        str[pos] = '(';
        dfs(str, pos + 1, n, left + 1, check + 1, retSize, retArr);
    }
    if (check > 0 && pos - left < n) {
        str[pos] = ')';
        dfs(str, pos + 1, n, left, check - 1, retSize, retArr);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    char *arr[MAX] = { NULL }, str[MAX] = { 0 }, **ans = NULL;

    *returnSize = 0;
    dfs(str, 0, n, 0, 0, returnSize, arr);

    ans = calloc(*returnSize, sizeof(char *));
    memcpy(ans, arr, *returnSize * sizeof(char *));

    return ans;
}
