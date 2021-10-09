// 给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。
//
// 实现 SummaryRanges 类：
//
//
//
//
// SummaryRanges() 使用一个空数据流初始化对象。
// void addNum(int val) 向数据流中加入整数 val 。
// int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
//
//
//
//
// 示例：
//
//
// 输入：
// ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum",
// "getIntervals", "addNum", "getIntervals"]
// [[], [1], [], [3], [], [7], [], [2], [], [6], []]
// 输出：
// [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3],
// [6, 7]]]
//
// 解释：
//  SummaryRanges summaryRanges = new SummaryRanges();
//  summaryRanges.addNum(1);      // arr = [1]
//  summaryRanges.getIntervals(); // 返回 [[1, 1]]
//  summaryRanges.addNum(3);      // arr = [1, 3]
//  summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
//  summaryRanges.addNum(7);      // arr = [1, 3, 7]
//  summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
//  summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
//  summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
//  summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
//  summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
//
//
//
//
// 提示：
//
//
// 0 <= val <= 10⁴
// 最多调用 addNum 和 getIntervals 方法 3 * 10⁴ 次
//
//
//
//
//
//
// 进阶：如果存在大量合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?
// Related Topics 设计 二分查找 有序集合 👍 101 👎 0

#define MAXN 10000
typedef struct {
    int max;
    int l, r;
    bool record;
} SummaryRanges;
SummaryRanges *summaryRangesCreate() {
    return calloc(MAXN + 3, sizeof(SummaryRanges));
}
void summaryRangesAddNum(SummaryRanges *ranges, int val) {
    int l = val, r = val;
    SummaryRanges *left = &ranges[val], *now = left + 1, *right = now + 1;
    if (now->record) return;
    if (left->record) l = left->l;
    if (right->record) r = right->r;
    ranges[val + 1].record = true, ranges->max = fmax(ranges->max, r);
    ranges[l + 1] = (SummaryRanges) { ranges->max, l, r, true };
    ranges[r + 1] = (SummaryRanges) { ranges->max, l, r, true };
}
int **summaryRangesGetIntervals(SummaryRanges *ranges, int *retSize, int **retColSize) {
    int len = 0, *help[MAXN], **ans;
    for (int pos = 1; pos <= ranges->max + 1; ++pos) {
        if (!ranges[pos].record) continue;
        help[len] = malloc(2 * sizeof(int)), help[len][0] = ranges[pos].l, help[len][1] = ranges[pos].r;
        len += 1, pos = ranges[pos].r + 1;
    }
    ans = malloc((*retSize = len) * sizeof(int *)), *retColSize = malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        ans[i] = help[i], (*retColSize)[i] = 2;
    }
    return ans;
}
void summaryRangesFree(SummaryRanges *ranges) {
    free(ranges);
}
