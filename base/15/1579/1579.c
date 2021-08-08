// Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3 种类型的边：
//
//
// 类型 1：只能由 Alice 遍历。
// 类型 2：只能由 Bob 遍历。
// 类型 3：Alice 和 Bob 都可以遍历。
//
//
// 给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请
// 你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob
// 都可以到达所有其他节点，则认为图 是可以完全遍历的。
//
// 返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。
//
//
//
// 示例 1：
//
//
//
// 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// 输出：2
// 解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob
// 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所 以可以删除的最大边数是 2 。
//
//
// 示例 2：
//
//
//
// 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// 输出：0
// 解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
//
//
// 示例 3：
//
//
//
// 输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// 输出：-1
// 解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点 1 。因此，图无法完全遍历。
//
//
//
// 提示：
//
//
// 1 <= n <= 10^5
// 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
// edges[i].length == 3
// 1 <= edges[i][0] <= 3
// 1 <= edges[i][1] < edges[i][2] <= n
// 所有元组 (typei, ui, vi) 互不相同
//
// Related Topics 并查集
// 👍 60 👎 0

int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
int merge(int ancestor[], int u, int v) {
    u = find(ancestor, u), v = find(ancestor, v);
    if (u != v) ancestor[u] = ancestor[v];
    return u != v;
}
int maxNumEdgesToRemove(int n, int **edges, int size, int *colSize) {
    int alice[n + 1], bob[n + 1], common_use = 0, alice_use = 0, bob_use = 0;
    for (int i = 1; i <= n; ++i) {
        alice[i] = i, bob[i] = i;
    }
    for (int i = 0, u, v; i < size; ++i) {
        if (edges[i][0] != 3) continue;
        u = edges[i][1], v = edges[i][2];
        if (find(alice, u) == find(alice, v)) continue;
        common_use++, merge(alice, u, v), merge(bob, u, v);
    }
    for (int i = 0, u, v; i < size; ++i) {
        u = edges[i][1], v = edges[i][2];
        if (edges[i][0] == 1) {
            alice_use += merge(alice, u, v);
        } else if (edges[i][0] == 2) {
            bob_use += merge(bob, u, v);
        }
    }
    if (alice_use != bob_use || alice_use + common_use + 1 < n) return -1;
    return size - common_use - alice_use - bob_use;
}
