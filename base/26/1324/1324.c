// 给你一个字符串 s。请你按照单词在 s 中的出现顺序将它们全部竖直返回。
// 单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。
// 每个单词只能放在一列上，每一列中也只能有一个单词。
//
//
//
// 示例 1：
//
// 输入：s = "HOW ARE YOU"
// 输出：["HAY","ORO","WEU"]
// 解释：每个单词都应该竖直打印。
// "HAY"
// "ORO"
// "WEU"
//
//
// 示例 2：
//
// 输入：s = "TO BE OR NOT TO BE"
// 输出：["TBONTB","OEROOE","   T"]
// 解释：题目允许使用空格补位，但不允许输出末尾出现空格。
// "TBONTB"
// "OEROOE"
// "   T"
//
//
// 示例 3：
//
// 输入：s = "CONTEST IS COMING"
// 输出：["CIC","OSO","N M","T I","E N","S G","T"]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 200
// s 仅含大写英文字母。
// 题目数据保证两个单词之间只有一个空格。
//
// Related Topics 字符串
// 👍 26 👎 0

#define MAXN 200
typedef struct {
    int beg, len;
} node_t;
char **fun(const char *s, node_t nodes[], int size, int len) {
    char **ans = malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        ans[i] = malloc((len + 1) * sizeof(char));
        sprintf(ans[i], "%*.s", len, " ");
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < nodes[i].len; ++j) {
            ans[j][i] = s[nodes[i].beg + j];
        }
    }
    for (int i = 0, l; i < size; ++i) {
        for (l = len - 1; isblank(ans[i][l]); l--) {}
        ans[i][l + 1] = '\0';
    }
    return ans;
}
char **printVertically(char *s, int *returnSize) {
    int len = 0, max = 0;
    node_t nodes[MAXN / 2 + 1] = { 0 };

    for (; isblank(*s); s++) {}
    for (int i = 0; !i || s[i - 1]; ++i) {
        if (isalpha(s[i])) {
            if (!i || isblank(s[i - 1])) nodes[len].beg = i;
            nodes[len].len++;
        } else if (nodes[len].len) {
            if (max < nodes[len].len) max = nodes[len].len;
            len++;
        }
    }
    return fun(s, nodes, *returnSize = max, len);
}