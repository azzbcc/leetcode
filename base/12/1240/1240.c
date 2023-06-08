// 你是一位施工队的工长，根据设计师的要求准备为一套设计风格独特的房子进行室内装修。
//
// 房子的客厅大小为 n x m，为保持极简的风格，需要使用尽可能少的 正方形 瓷砖来铺盖地面。
//
// 假设正方形瓷砖的规格不限，边长都是整数。
//
// 请你帮设计师计算一下，最少需要用到多少块方形瓷砖？
//
//
//
// 示例 1：
//
//
//
// 输入：n = 2, m = 3
// 输出：3
// 解释：3 块地砖就可以铺满卧室。
//      2 块 1x1 地砖
//      1 块 2x2 地砖
//
// 示例 2：
//
//
//
// 输入：n = 5, m = 8
// 输出：5
//
//
// 示例 3：
//
//
//
// 输入：n = 11, m = 13
// 输出：6
//
//
//
//
// 提示：
//
//
// 1 <= n <= 13
// 1 <= m <= 13
//
//
// Related Topics 动态规划 回溯 👍 163 👎 0

#if 0
typedef struct {
    int x, y;
} point_t;
void dfs(int n, int m, int map[n][m], point_t now, int cur, int *ans) {
    for (; now.x < n && now.y < m && map[now.x][now.y];) {
        if (++now.y < m) continue;
        ++now.x, now.y = 0;
    }
    if (now.x == n) *ans = cur - 1;
    if (cur >= *ans) return;
    bool check = true;
    for (int width = 1;; ++width) {
        check = now.x + width - 1 < n && now.y + width - 1 < m && !map[now.x + width - 1][now.y + width - 1];
        for (int offset = 0; check && offset < width; ++offset) {
            check = !map[now.x + width - 1][now.y + offset] && !map[now.x + offset][now.y + width - 1];
        }
        if (!check) break;
        // 记录
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < width; ++y) {
                map[now.x + x][now.y + y] = cur;
            }
        }
        // 递归
        dfs(n, m, map, now, cur + 1, ans);
        // 恢复
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < width; ++y) {
                map[now.x + x][now.y + y] = 0;
            }
        }
    }
}
int tilingRectangle(int n, int m) {
    if (n == m) return 1;
    int map[n][m];
    memset(map, 0, sizeof(map));

    int ans = n * m + 1;
    dfs(n, m, map, (point_t) { 0, 0 }, 1, &ans);

    return ans;
}
#else
typedef struct {
    int x, y;
} point_t;
void dfs(int n, int m, bool map[n][m], point_t now, int cur, int *ans) {
    for (; now.x < n && now.y < m && map[now.x][now.y];) {
        if (++now.y < m) continue;
        ++now.x, now.y = 0;
    }
    if (now.x == n) *ans = cur - 1;
    if (cur >= *ans) return;

    // 贪心最大边
    int width = fmin(n - now.x, m - now.y);
    for (bool check; check = true, width; --width) {
        for (int x = width - 1; check && x >= 0; --x) {
            for (int y = width - 1; check && y >= 0; --y) {
                check = !map[now.x + x][now.y + y];
            }
        }
        if (check) break;
    }
    // 记录
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < width; ++y) {
            map[now.x + x][now.y + y] = true;
        }
    }
    for (; width; --width) {
        // 递归
        dfs(n, m, map, now, cur + 1, ans);
        // 恢复冗余边
        for (int offset = 0; offset < width; ++offset) {
            map[now.x + width - 1][now.y + offset] = map[now.x + offset][now.y + width - 1] = 0;
        }
    }
}
int tilingRectangle(int n, int m) {
    bool map[n][m];
    int ans = n * m + 1;

    memset(map, false, sizeof(map));
    dfs(n, m, map, (point_t) { 0, 0 }, 1, &ans);

    return ans;
}
#endif
