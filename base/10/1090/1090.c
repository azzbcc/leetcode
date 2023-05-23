// 我们有一个 n 项的集合。给出两个整数数组 values 和 labels ，第 i 个元素的值和标签分别是 values[i] 和 labels[i]。
// 还会给出两个整数 numWanted 和 useLimit 。
//
// 从 n 个元素中选择一个子集 s :
//
//
// 子集 s 的大小 小于或等于 numWanted 。
// s 中 最多 有相同标签的 useLimit 项。
//
//
// 一个子集的 分数 是该子集的值之和。
//
// 返回子集 s 的最大 分数 。
//
//
//
// 示例 1：
//
//
// 输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
// 输出：9
// 解释：选出的子集是第一项，第三项和第五项。
//
//
// 示例 2：
//
//
// 输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
// 输出：12
// 解释：选出的子集是第一项，第二项和第三项。
//
//
// 示例 3：
//
//
// 输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
// 输出：16
// 解释：选出的子集是第一项和第四项。
//
//
//
//
// 提示：
//
//
// n == values.length == labels.length
// 1 <= n <= 2 * 10⁴
// 0 <= values[i], labels[i] <= 2 * 10⁴
// 1 <= numWanted, useLimit <= n
//
//
// Related Topics 贪心 数组 哈希表 计数 排序 👍 57 👎 0

#define MAXN 20000
typedef struct {
    int label, value;
} node_t;
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pb->value - pa->value;
}
int largestValsFromLabels(int *values, int size, int *labels, int labelsSize, int numWanted, int useLimit) {
    node_t nodes[size];
    int sc[MAXN + 1] = { 0 }, ans = 0;
    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { labels[i], values[i] };
    }
    qsort(nodes, size, sizeof(node_t), cmp);
    for (int i = 0; i < size && numWanted; ++i) {
        if (sc[nodes[i].label] >= useLimit) continue;
        sc[nodes[i].label]++, ans += nodes[i].value, numWanted--;
    }
    return ans;
}