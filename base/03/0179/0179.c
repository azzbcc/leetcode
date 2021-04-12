// 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//
//
//
// 示例 1：
//
//
// 输入：nums = [10,2]
// 输出："210"
//
// 示例 2：
//
//
// 输入：nums = [3,30,34,5,9]
// 输出："9534330"
//
//
// 示例 3：
//
//
// 输入：nums = [1]
// 输出："1"
//
//
// 示例 4：
//
//
// 输入：nums = [10]
// 输出："10"
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
//
// Related Topics 排序
// 👍 580 👎 0

#define MAXN 100
#define MAXM (10 + 1)

typedef struct {
    int len;
    char str[MAXM];
} node_t;
node_t help[MAXN];
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    char sa[2][pa->len + pb->len + 1];
    sprintf(sa[0], "%s%s", pa->str, pb->str);
    sprintf(sa[1], "%s%s", pb->str, pa->str);
    return strcmp(sa[1], sa[0]);
}
char *largestNumber(int *nums, int size) {
    static char ans[MAXN * MAXM];
    for (int i = 0; i < size; ++i) {
        help[i].len = sprintf(help[i].str, "%d", nums[i]);
    }
    qsort(help, size, sizeof(node_t), cmp);
    char *p = ans;
    for (int i = 0; i < size; ++i) {
        p += sprintf(p, "%s", help[i].str);
    }
    if (ans[0] == '0') ans[1] = '\0';

    return ans;
}
