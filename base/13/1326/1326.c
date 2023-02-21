// 在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。
//
// 花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。
//
// 给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i
// 处的水龙头，可以灌溉的区域为 [i - ranges[i], i + ranges[i]] 。
//
// 请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：n = 5, ranges = [3,4,1,1,0,0]
// 输出：1
// 解释：
// 点 0 处的水龙头可以灌溉区间 [-3,3]
// 点 1 处的水龙头可以灌溉区间 [-3,5]
// 点 2 处的水龙头可以灌溉区间 [1,3]
// 点 3 处的水龙头可以灌溉区间 [2,4]
// 点 4 处的水龙头可以灌溉区间 [4,4]
// 点 5 处的水龙头可以灌溉区间 [5,5]
// 只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。
//
//
// 示例 2：
//
//
// 输入：n = 3, ranges = [0,0,0,0]
// 输出：-1
// 解释：即使打开所有水龙头，你也无法灌溉整个花园。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁴
// ranges.length == n + 1
// 0 <= ranges[i] <= 100
//
//
// Related Topics 贪心 数组 动态规划 👍 185 👎 0

typedef struct {
    int l, r;
} node_t;
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pa->l - pb->l;
}
int minTaps(int n, int *ranges, int size) {
    node_t nodes[size];
    int ans = 0, max = 0, len = 0;
    for (int i = 0; i < size; ++i) {
        if (!ranges[i]) continue ;
        nodes[len++] = (node_t) { i - ranges[i], i + ranges[i] };
    }
    qsort(nodes, len, sizeof(node_t), cmp);
    for (int l = 0, tmax; l < len && max < n; ans += 1, max = tmax) {
        if (max < nodes[l].l) return -1;
        for (tmax = max; l < len && nodes[l].l <= max; tmax = fmax(tmax, nodes[l++].r)) {}
    }
    return max >= n ? ans : -1;
}
