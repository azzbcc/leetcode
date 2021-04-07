// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
// 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
//
//
//
// 示例 1：
//
//
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//
// 示例 2：
//
//
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
//
//
// 提示：
//
//
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104
//
// Related Topics 排序 数组
// 👍 889 👎 0

int cmp(const void *a, const void *b) {
    int *pa = *( int ** )a, *pb = *( int ** )b;
    if (pa[0] == pb[0]) return pb[1] - pa[1];
    return pa[0] - pb[0];
}
int **merge(int **intervals, int size, int *colSize, int *returnSize, int **returnColumnSizes) {
    int *help[size], len = 0, **ans;

    qsort(intervals, size, sizeof(int *), cmp);
    for (int i = 0; i < size; ++i) {
        if (!len || intervals[i][0] > help[len - 1][1]) {
            help[len] = malloc(2 * sizeof(int));
            memcpy(help[len++], intervals[i], 2 * sizeof(int));
        } else if (help[len - 1][1] < intervals[i][1]) {
            help[len - 1][1] = intervals[i][1];
        }
    }

    ans = malloc((*returnSize = len) * sizeof(int *));
    *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        (*returnColumnSizes)[i] = 2, ans[i] = help[i];
    }

    return ans;
}