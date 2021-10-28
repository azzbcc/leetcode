// 给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。
//
// 如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。
//
//
//
//
//
//
// 示例 1：
//
// 输入：1
// 输出：true
//
//
// 示例 2：
//
// 输入：10
// 输出：false
//
//
// 示例 3：
//
// 输入：16
// 输出：true
//
//
// 示例 4：
//
// 输入：24
// 输出：false
//
//
// 示例 5：
//
// 输入：46
// 输出：true
//
//
//
//
// 提示：
//
//
// 1 <= N <= 10^9
//
// Related Topics 数学 计数 枚举 排序 👍 85 👎 0

#define MAXN 30
typedef struct {
    int len;
    char data[10];
} dict_t;
dict_t dict[MAXN];
int cmp(const void *a, const void *b) {
    return *( char * )a - *( char * )b;
}
void init() {
    static bool initial = false;
    if (initial) return;
    initial = true;
    for (int i = 0; i < MAXN; ++i) {
        dict[i].len = sprintf(dict[i].data, "%d", 0x1 << i);
        qsort(dict[i].data, dict[i].len, sizeof(char), cmp);
    }
}
bool reorderedPowerOf2(int n) {
    dict_t d = { sprintf(d.data, "%d", n) };

    init();
    qsort(d.data, d.len, sizeof(char), cmp);

    for (int i = 0; i < MAXN; ++i) {
        if (d.len < dict[i].len) break;
        if (d.len > dict[i].len) continue;
        if (strncmp(d.data, dict[i].data, d.len) == 0) return true;
    }
    return false;
}
