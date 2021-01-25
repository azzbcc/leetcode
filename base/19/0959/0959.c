// 在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
//
// （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
//
// 返回区域的数目。
//
//
//
//
//
//
// 示例 1：
//
// 输入：
// [
//  " /",
//  "/ "
// ]
// 输出：2
// 解释：2x2 网格如下：
//
//
// 示例 2：
//
// 输入：
// [
//  " /",
//  "  "
// ]
// 输出：1
// 解释：2x2 网格如下：
//
//
// 示例 3：
//
// 输入：
// [
//  "\\/",
//  "/\\"
// ]
// 输出：4
// 解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
// 2x2 网格如下：
//
//
// 示例 4：
//
// 输入：
// [
//  "/\\",
//  "\\/"
// ]
// 输出：5
// 解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
// 2x2 网格如下：
//
//
// 示例 5：
//
// 输入：
// [
//   "//",
//   "/ "
// ]
// 输出：3
// 解释：2x2 网格如下：
//
//
//
//
//
// 提示：
//
//
// 1 <= grid.length == grid[0].length <= 30
// grid[i][j] 是 '/'、'\'、或 ' '。
//
// Related Topics 深度优先搜索 并查集 图
// 👍 169 👎 0

int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
int merge(int ancestor[], int a, int b) {
    a = find(ancestor, a), b = find(ancestor, b);
    if (a != b) ancestor[b] = a;
    return a != b;
}
int merge_square(int ancestor[], int node, char current) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        ancestor[4 * node + i] = 4 * node + i;
    }
    if (current == '/' || current == ' ') {
        count += merge(ancestor, 4 * node + 0, 4 * node + 1);
        count += merge(ancestor, 4 * node + 2, 4 * node + 3);
    }
    if (current == '\\' || current == ' ') {
        count += merge(ancestor, 4 * node + 0, 4 * node + 3);
        count += merge(ancestor, 4 * node + 1, 4 * node + 2);
    }
    return count;
}
int regionsBySlashes(char **grid, int size) {
    int ancestor[size * size * 4], count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; grid[i][j]; ++j) {
            count += merge_square(ancestor, i * size + j, grid[i][j]);
            if (i) count += merge(ancestor, 4 * ((i - 1) * size + j) + 2, 4 * (i * size + j) + 0);
            if (j) count += merge(ancestor, 4 * (i * size +( j - 1)) + 3, 4 * (i * size + j) + 1);
        }
    }

    return size * size * 4 - count;
}
