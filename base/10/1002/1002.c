// 给定仅有小写字母组成的字符串数组
// A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
// 次，但不 是 4 次，则需要在最终答案中包含该字符 3 次。
//
// 你可以按任意顺序返回答案。
//
//
//
// 示例 1：
//
// 输入：["bella","label","roller"]
// 输出：["e","l","l"]
//
//
// 示例 2：
//
// 输入：["cool","lock","cook"]
// 输出：["c","o"]
//
//
//
//
// 提示：
//
//
// 1 <= A.length <= 100
// 1 <= A[i].length <= 100
// A[i][j] 是小写字母
//
// Related Topics 数组 哈希表
// 👍 138 👎 0

#define WIDTH 26
#define MAXN  100

void init(char *s, int res[WIDTH]) {
    for (; *s; res[*s++ - 'a']++) {}
}
char **commonChars(char **A, int ASize, int *returnSize) {
    char **ans, *help[MAXN];
    int cs[WIDTH] = { 0 }, len = 0;

    init(A[0], cs);
    for (int i = 1; i < ASize; ++i) {
        int ct[WIDTH] = { 0 };

        init(A[i], ct);
        for (int j = 0; j < WIDTH; ++j) {
            if (cs[j] > ct[j]) cs[j] = ct[j];
        }
    }

    for (int i = 0; i < WIDTH; ++i) {
        for (; cs[i]--; len++) {
            help[len]    = calloc(2, sizeof(char));
            help[len][0] = 'a' + i;
        }
    }

    *returnSize = len, ans = calloc(len, sizeof(char *));
    memcpy(ans, help, len * sizeof(char *));

    return ans;
}