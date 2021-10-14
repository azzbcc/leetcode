// 「以扣会友」线下活动所在场地由若干主题空间与走廊组成，场地的地图记作由一维字符串型数组 `grid`，字符串中仅包含
// `"0"～"5"` 这 6 个字符。 地图上每一个字符代表面积为 1 的区域，其中 `"0"`
// 表示走廊，其他字符表示主题空间。相同且连续（连续指上、下、左、右四个方向连接）的字符组成同一个主题空间。
//
//
// 假如整个 `grid` 区域的外侧均为走廊。请问，不与走廊直接相邻的主题空间的最大面积是多少？如果不存在这样的空间请返回`0`。
//
// **示例 1:**
// >输入：`grid = ["110","231","221"]`
// >
// >输出：`1`
// >
// >解释：4 个主题空间中，只有 1 个不与走廊相邻，面积为 1。
// >![image.png](https://pic.leetcode-cn.com/1613708145-rscctN-image.png)
//
//
// **示例 2:**
// >输入：`grid = ["11111100000","21243101111","21224101221","11111101111"]`
// >
// >输出：`3`
// >
// >解释：8 个主题空间中，有 5 个不与走廊相邻，面积分别为 3、1、1、1、2，最大面积为 3。
// >![image.png](https://pic.leetcode-cn.com/1613707985-KJyiXJ-image.png)
//
//
// **提示：**
// - `1 <= grid.length <= 500`
// - `1 <= grid[i].length <= 500`
// - `grid[i][j]` 仅可能是 `"0"～"5"`
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 7 👎 0

typedef struct {
    int ancestor;
    int area;
    char type;
    bool neighbor;
} node_t;
int find(node_t nodes[], int n) {
    if (nodes[n].ancestor == n) return n;
    return nodes[n].ancestor = find(nodes, nodes[n].ancestor);
}
void merge(node_t nodes[], int from, int to) {
    int a = find(nodes, from), b = find(nodes, to);
    if (nodes[a].ancestor == b) return;

    nodes[a].ancestor = b;
    nodes[b].area += nodes[a].area;
    nodes[b].neighbor |= nodes[a].neighbor;
}
int largestArea(char **grid, int size) {
    size_t m = size, n = strlen(grid[0]);
    node_t nodes[m * n];
    int ans = 0;

    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            int now = x * n + y;
            nodes[now] = (node_t) { now, 1, grid[x][y], grid[x][y] == '0' || x == 0 || x == m - 1 || y == 0 || y == n - 1 };
            if (x > 0 && (nodes[now].type == '0' || nodes[now - n].type == '0' || nodes[now].type == nodes[now - n].type)) merge(nodes, now, now - n);
            if (y > 0 && (nodes[now].type == '0' || nodes[now - 1].type == '0' || nodes[now].type == nodes[now - 1].type)) merge(nodes, now, now - 1);
        }
    }
    for (int i = 0; i < m * n; ++i) {
        if (find(nodes, i) != i) continue;
        if (nodes[i].neighbor) continue;
        ans = fmax(ans, nodes[i].area);
    }

    return ans;
}