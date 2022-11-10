// 给定一个二维网格 grid ，其中：
//
//
// '.' 代表一个空房间
// '#' 代表一堵
// '@' 是起点
// 小写字母代表钥匙
// 大写字母代表锁
//
//
// 我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
//
// 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，字母表中的前 k
// 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
//
// 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：grid = ["@.a.#","###.#","b.A.B"]
// 输出：8
// 解释：目标是获得所有钥匙，而不是打开所有锁。
//
//
// 示例 2：
//
//
//
//
// 输入：grid = ["@..aA","..B#.","....b"]
// 输出：6
//
//
// 示例 3:
//
//
// 输入: grid = ["@Aa"]
// 输出: -1
//
//
//
// 提示：
//
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 30
// grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
// 钥匙的数目范围是 [1, 6]
// 每个钥匙都对应一个 不同 的字母
// 每个钥匙正好打开一个对应的锁
//
//
// Related Topics 位运算 广度优先搜索 数组 矩阵 👍 148 👎 0

typedef struct {
    int x, y, mask, step;
} status_t;
const int wards[] = { -1, 0, 1, 0, -1 };
int shortestPathAllKeys(char **grid, int size) {
    status_t beg;
    int m = size, n = strlen(grid[0]), key = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '@') {
                beg = (status_t) { i, j };
            } else if (islower(grid[i][j])) {
                key += 1;
            }
        }
    }

    int f = 0, r = 0;
    bool visit[m][n][0x1 << key];
    status_t queue[m * n * 0x1 << key];
    memset(visit, false, sizeof(visit));

    for (queue[r++] = beg, visit[beg.x][beg.y][0] = true; f < r; ++f) {
        status_t now = queue[f];
        if (now.mask + 1 == 0x1 << key) return now.step;
        for (int i = 0; i < 4; ++i) {
            status_t next = (status_t) { now.x + wards[i], now.y + wards[i + 1], now.mask, now.step + 1 };
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (islower(grid[next.x][next.y])) next.mask |= 0x1 << (grid[next.x][next.y] - 'a');
            if (visit[next.x][next.y][next.mask] || grid[next.x][next.y] == '#') continue;
            if (isupper(grid[next.x][next.y]) && 0 == (0x1 << (grid[next.x][next.y] - 'A') & next.mask)) continue;
            visit[next.x][next.y][next.mask] = true, queue[r++] = next;
        }
    }
    return -1;
}
