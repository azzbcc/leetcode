// 有两只老鼠和 n 块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。
//
// 下标为 i 处的奶酪被吃掉的得分为：
//
//
// 如果第一只老鼠吃掉，则得分为 reward1[i] 。
// 如果第二只老鼠吃掉，则得分为 reward2[i] 。
//
//
// 给你一个正整数数组 reward1 ，一个正整数数组 reward2 ，和一个非负整数 k 。
//
// 请你返回第一只老鼠恰好吃掉 k 块奶酪的情况下，最大 得分为多少。
//
//
//
// 示例 1：
//
//
// 输入：reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
// 输出：15
// 解释：这个例子中，第一只老鼠吃掉第 2 和 3 块奶酪（下标从 0 开始），第二只老鼠吃掉第 0 和 1 块奶酪。
// 总得分为 4 + 4 + 3 + 4 = 15 。
// 15 是最高得分。
//
//
// 示例 2：
//
//
// 输入：reward1 = [1,1], reward2 = [1,1], k = 2
// 输出：2
// 解释：这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0 开始），第二只老鼠不吃任何奶酪。
// 总得分为 1 + 1 = 2 。
// 2 是最高得分。
//
//
//
//
// 提示：
//
//
// 1 <= n == reward1.length == reward2.length <= 10⁵
// 1 <= reward1[i], reward2[i] <= 1000
// 0 <= k <= n
//
//
// Related Topics 贪心 数组 排序 堆（优先队列） 👍 12 👎 0

typedef struct {
    int r1, r2, diff;
} node_t;
void quick_search(node_t nodes[], int l, int r, int k) {
    // choose mid
    int ll = l, rr = r;
    node_t base = nodes[ll];
    for (; ll < rr;) {
        for (; ll < rr && nodes[rr].diff <= base.diff; --rr) {}
        if (ll < rr) nodes[ll++] = nodes[rr];
        for (; ll < rr && nodes[ll].diff > base.diff; ++ll) {}
        if (ll < rr) nodes[rr--] = nodes[ll];
    }
    nodes[ll] = base;
    if (ll > k) {
        quick_search(nodes, l, ll - 1, k);
    } else if (ll < k - 1) {
        quick_search(nodes, ll + 1, r, k);
    }
}
int miceAndCheese(int *reward1, int size, int *reward2, int reward2Size, int k) {
    int ans = 0;
    node_t nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { reward1[i], reward2[i], reward1[i] - reward2[i] };
    }
    if (k && k < size) quick_search(nodes, 0, size - 1, k);
    for (int i = 0; i < size; ++i) {
        ans += i < k ? nodes[i].r1 : nodes[i].r2;
    }
    return ans;
}