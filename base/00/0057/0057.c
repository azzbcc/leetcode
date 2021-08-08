// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
//
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
//
//
//
// 示例 1：
//
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出：[[1,5],[6,9]]
//
//
// 示例 2：
//
// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 输出：[[1,2],[3,10],[12,16]]
// 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
//
//
//
//
// 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
// Related Topics 排序 数组
// 👍 259 👎 0

int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize,
             int *returnSize, int **returnColumnSizes) {
    int left = 0, right = intervalsSize - 1, len = intervalsSize;
    int **ans = malloc((len + 1) * sizeof(int *));

    for (int r = intervalsSize - 1, mid; left <= r;) {
        mid = (left + r) / 2;
        if (intervals[mid][1] >= newInterval[0]) {
            r = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    for (int l = 0, mid; l <= right;) {
        mid = (l + right) / 2;
        if (intervals[mid][0] <= newInterval[1]) {
            l = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (left <= right && intervals[left][0] > newInterval[0]) intervals[left][0] = newInterval[0];
    if (left <= right && intervals[right][1] < newInterval[1]) intervals[right][1] = newInterval[1];

    if (left > right) {
        len += 1;
        if (left) memcpy(ans, intervals, left * sizeof(int *));
        if (left < intervalsSize) memcpy(ans + left + 1, &intervals[left], (intervalsSize - left) * sizeof(int *));
        ans[left] = newInterval;
    } else if (left < right) {
        len -= right - left;
        memcpy(ans, intervals, left * sizeof(int *));
        memcpy(ans + left, &intervals[right], (len - left) * sizeof(int *));
        ans[left][0] = intervals[left][0];
    } else {
        memcpy(ans, intervals, len * sizeof(int *));
    }

    *returnSize = len, *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0; i < len; (*returnColumnSizes)[i++] = 2) {}

    return ans;
}
