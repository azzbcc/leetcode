// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//
//
// 上图为 8 皇后问题的一种解法。
//
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
//
// 示例:
//
// 输入: 4
// 输出: 2
// 解释: 4 皇后问题存在如下两个不同的解法。
// [
// [".Q..", // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.", // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
// ]
//
//
//
//
// 提示：
//
//
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或
// N
//-1 步，可进可退。（引用自 百度百科 - 皇后 ）
//
// Related Topics 回溯算法
// 👍 144 👎 0

bool check(const int map[], int now) {
    for (int i = 0; i < now; ++i) {
        if (abs(map[i] - map[now]) == now - i) return false;
    }
    return true;
}
void dfs(int n, int now, int map[], bool visited[], int *count) {
    if (now >= n) {
        ++*count;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        map[now] = i;
        if (!check(map, now)) continue;

        visited[i] = true;
        dfs(n, now + 1, map, visited, count);
        visited[i] = false;
    }
}
int totalNQueens(int n) {
    bool visited[n];
    int map[n], count = 0;
    for (int i = 0; i < n; visited[i++] = false) {}

    dfs(n, 0, map, visited, &count);

    return count;
}
