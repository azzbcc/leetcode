// 有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：
//
//
// 一块砖直接连接到网格的顶部，或者
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
//
//
// 给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli)
// 位置上的砖块时，对应位置的砖块（若存在）会消
// 失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。
//
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
//
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
//
//
//
// 示例 1：
//
//
// 输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
// 输出：[2]
// 解释：
// 网格开始为：
// [[1,0,0,0]，
//  [1,1,1,0]]
// 消除 (1,0) 处加粗的砖块，得到网格：
// [[1,0,0,0]
//  [0,1,1,0]]
// 两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
// [[1,0,0,0],
//  [0,0,0,0]]
// 因此，结果为 [2] 。
//
//
// 示例 2：
//
//
// 输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
// 输出：[0,0]
// 解释：
// 网格开始为：
// [[1,0,0,0],
//  [1,1,0,0]]
// 消除 (1,1) 处加粗的砖块，得到网格：
// [[1,0,0,0],
//  [1,0,0,0]]
// 剩下的砖都很稳定，所以不会掉落。网格保持不变：
// [[1,0,0,0],
//  [1,0,0,0]]
// 接下来消除 (1,0) 处加粗的砖块，得到网格：
// [[1,0,0,0],
//  [0,0,0,0]]
// 剩下的砖块仍然是稳定的，所以不会有砖块掉落。
// 因此，结果为 [0,0] 。
//
//
//
// 提示：
//
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// grid[i][j] 为 0 或 1
// 1 <= hits.length <= 4 * 104
// hits[i].length == 2
// 0 <= xi <= m - 1
// 0 <= yi <= n - 1
// 所有 (xi, yi) 互不相同
//
// Related Topics 并查集
// 👍 114 👎 0

typedef struct {
    int x, y;
} point_t;

const point_t wards[] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int find(int ancestor[], int n) {
    if (ancestor[n] == -1 || ancestor[n] == n) return ancestor[n] = n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int children[], int a, int b) {
    int pa = find(ancestor, a), pb = find(ancestor, b);
    if (pa == pb) return;
    for (int tmp = pa; pa > pb; pa = pb, pb = tmp) {}
    ancestor[pa] = pb, children[pb] += children[pa] + 1;
}
int *hitBricks(int **grid, int gridSize, int *gridColSize, int **hits, int hitsSize, int *hitsColSize,
               int *returnSize) {
    int *ans = malloc((*returnSize = hitsSize) * sizeof(int));
    int m = gridSize, n = *gridColSize, stable = m * n, map[m][n], ancestor[stable + 1], children[stable + 1];

    // 并查集初始化
    memset(ancestor, -1, sizeof(ancestor));
    memset(children, 0, sizeof(children));
    // 地图拷贝
    for (int i = 0; i < m; ++i) {
        memcpy(map[i], grid[i], n * sizeof(int));
    }
    // 打破所有需要的砖块
    for (int i = 0; i < hitsSize; ++i) {
        map[hits[i][0]][hits[i][1]] = 0;
    }
    // 靠近墙面砖块标记为稳定
    for (int i = 0; i < n; ++i) {
        if (map[0][i]) merge(ancestor, children, i, stable);
    }
    // 对剩余的砖块标记
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!map[i][j]) continue;
            for (int k = 0; k < sizeof(wards) / sizeof(wards[0]); ++k) {
                point_t next = (point_t) { i + wards[k].x, j + wards[k].y };
                if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n || !map[next.x][next.y]) continue;
                merge(ancestor, children, i * n + j, next.x * n + next.y);
            }
        }
    }
    // 逆序补回砖块
    for (int i = hitsSize - 1, last = children[stable]; i >= 0; --i, last = children[stable]) {
        point_t *hit = ( point_t * )hits[i];

        // 砖块补回
        if (grid[hit->x][hit->y]) {
            map[hit->x][hit->y] = 1;
            for (int j = 0; j < sizeof(wards) / sizeof(wards[0]); ++j) {
                point_t next = (point_t) { hit->x + wards[j].x, hit->y + wards[j].y };
                if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n || !map[next.x][next.y]) continue;
                merge(ancestor, children, hit->x * n + hit->y, next.x * n + next.y);
            }
            // 靠近墙面砖块标记为稳定
            if (!hit->x) merge(ancestor, children, hit->x * n + hit->y, stable);
        }
        ans[i] = children[stable] > last ? children[stable] - last - 1 : 0;
    }

    return ans;
}