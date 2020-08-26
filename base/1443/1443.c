// 给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从
// 节点 0 出发，请你返回最 少需要多少秒，可以收集到所有苹果，并回到节点 0 。
//
// 无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。除此以外，还有一个布尔数
// 组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。
//
//
//
// 示例 1：
//
//
//
// 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,fa
// lse,true,false,true,true,false]
// 输出：8
// 解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
//
//
// 示例 2：
//
//
//
// 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,fa
// lse,true,false,false,true,false]
// 输出：6
// 解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
//
//
// 示例 3：
//
// 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,fa
// lse,false,false,false,false,false]
// 输出：0
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10^5
// edges.length == n-1
// edges[i].length == 2
// 0 <= fromi, toi <= n-1
// fromi < toi
// hasApple.length == n
//
// Related Topics 树 深度优先搜索
// 👍 27 👎 0

int dfs(int n, int **edges, int now, bool *visited, bool *hasApple) {
    if (visited[now]) return 0;

    int ans = 0;

    visited[now] = true;
    for (int i = 0; i < n - 1; ++i) {
        if (edges[i][0] != now && edges[i][1] != now) continue;
        int next = now ^ edges[i][0] ^ edges[i][1];

        if (!visited[next]) {
            int tmp = dfs(n, edges, next, visited, hasApple);
            if (tmp > 0 || hasApple[next]) tmp += 2;
            ans += tmp;
        }
    }
    return ans;
}

int minTime(int n, int **edges, int edgesSize, int *edgesColSize, bool *hasApple, int hasAppleSize) {
    bool visited[n];
    for (int i = 0; i < n; visited[i++] = false) {}

    return dfs(n, edges, 0, visited, hasApple);
}