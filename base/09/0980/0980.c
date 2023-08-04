// 在二维网格 grid 上，有 4 种类型的方格：
//
//
// 1 表示起始方格。且只有一个起始方格。
// 2 表示结束方格，且只有一个结束方格。
// 0 表示我们可以走过的空方格。
// -1 表示我们无法跨越的障碍。
//
//
// 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
//
// 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
//
//
//
// 示例 1：
//
// 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// 输出：2
// 解释：我们有以下两条路径：
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//
// 示例 2：
//
// 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// 输出：4
// 解释：我们有以下四条路径：
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//
// 示例 3：
//
// 输入：[[0,1],[2,0]]
// 输出：0
// 解释：
// 没有一条路能完全穿过每一个空的方格一次。
// 请注意，起始和结束方格可以位于网格中的任意位置。
//
//
//
//
// 提示：
//
//
// 1 <= grid.length * grid[0].length <= 20
//
//
// Related Topics 位运算 数组 回溯 矩阵 👍 282 👎 0

#if 0
typedef struct {
    int x, y;
} point_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int dfs(int m, int n, int *grid[], point_t now, int left) {
    int ans = 0;
    if (grid[now.x][now.y] == 2) return !left;

    grid[now.x][now.y] = -1;
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = { now.x + wards[i].x, now.y + wards[i].y };
        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n || grid[next.x][next.y] == -1) continue;
        ans += dfs(m, n, grid, next, left - 1);
    }
    grid[now.x][now.y] = 0;
    return ans;
}
int uniquePathsIII(int **grid, int size, int *colSize) {
    point_t beg;
    int m = size, n = *colSize, left = m * n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) beg = (point_t) { i, j };
            if (grid[i][j] & 1) left--;
        }
    }
    return dfs(m, n, grid, beg, left);
}
#else
typedef struct {
    int x, y;
} point_t;
typedef struct {
    long key;
    int val;
    UT_hash_handle hh;
} *hash_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
hash_t hash_find(hash_t t, long key) {
    hash_t cur;
    HASH_FIND(hh, t, &key, sizeof(long), cur);
    return cur;
}
int hash_record(hash_t *t, long key, int val) {
    hash_t cur = hash_find(*t, key);
    if (cur) return val;
    cur = malloc(sizeof(*cur)), cur->key = key;
    HASH_ADD(hh, *t, key, sizeof(long), cur);
    return cur->val = val;
}
int dfs(int m, int n, int *grid[], hash_t *map, point_t now, int mask) {
    hash_t find;
    long hash = (1UL * now.x * n + now.y) << (m * n) | mask;
    if (grid[now.x][now.y] == 2) return !mask;
    if ((find = hash_find(*map, hash))) return find->val;

    int ans = 0;
    for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
        point_t next = { now.x + wards[i].x, now.y + wards[i].y };
        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
        if ((1 << (next.x * n + next.y) & mask) == 0) continue;
        ans += dfs(m, n, grid, map, next, 1 << (next.x * n + next.y) ^ mask);
    }
    return hash_record(map, hash, ans);
}
int uniquePathsIII(int **grid, int size, int *colSize) {
    point_t beg;
    hash_t hash = NULL, cur, next;
    int m = size, n = *colSize, mask = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) beg = (point_t) { i, j };
            if (grid[i][j] == 0 || grid[i][j] == 2) mask |= 1 << (i * n + j);
        }
    }
    int ans = dfs(m, n, grid, &hash, beg, mask);
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
#endif