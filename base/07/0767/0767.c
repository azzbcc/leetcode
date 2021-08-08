//给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//
// 若可行，输出任意可行的结果。若不可行，返回空字符串。
//
// 示例 1:
//
//
//输入: S = "aab"
//输出: "aba"
//
//
// 示例 2:
//
//
//输入: S = "aaab"
//输出: ""
//
//
// 注意:
//
//
// S 只包含小写字母并且长度在[1, 500]区间内。
//
// Related Topics 堆 贪心算法 排序 字符串
// 👍 189 👎 0
#define WIDTH 26

typedef struct {
    int ch, count;
} node_t;

static int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pb->count - pa->count;
}
char *reorganizeString(char *S) {
    int len;
    node_t nodes[WIDTH] = { 0 };

    for (int i = 0; i < WIDTH; ++i) {
        nodes[i].ch = 'a' + i;
    }
    for (len = 0; S[len]; ++len) {
        nodes[S[len] - 'a'].count++;
    }

    qsort(nodes, WIDTH, sizeof(node_t), cmp);
    if ((len + 1) / 2 < nodes[0].count) return "";

    for (int i = 0, j = 0; i < WIDTH && nodes[i].count; j += 2) {
        if (j >= len) j = 1;
        S[j] = ( char )nodes[i].ch;
        if (!--nodes[i].count) i++;
    }

    return S;
}