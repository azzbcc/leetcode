// 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col)
// 的高度。 一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0
// 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
//
// 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
//
// 请你返回从左上角走到右下角的最小 体力消耗值 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
// 输出：2
// 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
// 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
//
//
// 示例 2：
//
//
//
//
// 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
// 输出：1
// 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
//
//
// 示例 3：
//
//
// 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// 输出：0
// 解释：上图所示路径不需要消耗任何体力。
//
//
//
//
// 提示：
//
//
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
//
// Related Topics 深度优先搜索 并查集 图 二分查找
// 👍 101 👎 0

typedef struct {
    int a, b, weight;
} line_t;
int weight(int h1, int h2) {
    for (int tmp = h1; tmp < h2; h1 = h2, h2 = tmp) {}
    return h1 - h2;
}
int cmp(const void *a, const void *b) {
    line_t *pa = ( line_t * )a, *pb = ( line_t * )b;
    return pa->weight - pb->weight;
}
int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int from, int to) {
    ancestor[find(ancestor, to)] = find(ancestor, from);
}
int minimumEffortPath(int **heights, int size, int *colSize) {
    int m = size, n = *colSize, ancestor[m * n];
    if (m == 1 && n == 1) return 0;
    line_t lines[(m - 1) * n + m * (n - 1)], *horizontal = lines, *vertical = lines + (m - 1) * n, *ans = NULL;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ancestor[i * n + j] = i * n + j;
        }
    }
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            horizontal[i * n + j] = (line_t) { i * n + j, (i + 1) * n + j, weight(heights[i][j], heights[i + 1][j]) };
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            vertical[i * m + j] = (line_t) { j * n + i, j * n + i + 1, weight(heights[j][i], heights[j][i + 1]) };
        }
    }
    qsort(lines, (m - 1) * n + m * (n - 1), sizeof(line_t), cmp);
    for (ans = lines;; ans++) {
        merge(ancestor, ans->a, ans->b);
        if (find(ancestor, 0) == find(ancestor, m * n - 1)) break;
    }

    return ans->weight;
}