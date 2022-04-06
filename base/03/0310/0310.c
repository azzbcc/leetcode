// 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
//
// 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges
// 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
//
// 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为
// h。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
//
// 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。树的 高度
// 是指根节点和叶子节点之间最长向下路径上边的数量。
//
//
//
// 示例 1：
//
//
// 输入：n = 4, edges = [[1,0],[1,2],[1,3]]
// 输出：[1]
// 解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
//
// 示例 2：
//
//
// 输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// 输出：[3,4]
//
//
//
//
//
//
//
// 提示：
//
//
// 1 <= n <= 2 * 10⁴
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// 所有 (ai, bi) 互不相同
// 给定的输入 保证 是一棵树，并且 不会有重复的边
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 536 👎 0

#define MAXN 20000
#define MAXM 2 * MAXN
int idx, h[MAXN + 1], e[MAXM], ne[MAXM];
void edge_record(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int *findMinHeightTrees(int n, int **edges, int size, int *colSize, int *returnSize) {
    if (n == 1) return calloc(*returnSize = 1, sizeof(int));

    int degree[n];
    memset(degree, 0, sizeof(degree));
    idx = 0, memset(h, -1, (n + 1) * sizeof(int));
    for (int i = 0; i < size; ++i) {
        int from = edges[i][0], to = edges[i][1];
        edge_record(from, to);
        edge_record(to, from);
        degree[from]++, degree[to]++;
    }

    int queue[n], front = 0, rear = 0;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) queue[rear++] = i;
    }

    for (; rear < n;) {
        for (int tmp = rear; front < tmp; ++front) {
            for (int i = h[queue[front]]; i >= 0; i = ne[i]) {
                if (--degree[e[i]] == 1) queue[rear++] = e[i];
            }
        }
    }

    int *ans = malloc((*returnSize = rear - front) * sizeof(int));
    memcpy(ans, queue + front, (rear - front) * sizeof(int));
    return ans;
}