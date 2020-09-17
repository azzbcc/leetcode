//在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。
//
// 输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N)
// 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边
// 不属于树中已存在的边。
//
// 结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v
// 的一个父节点。
//
//
// 返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
//
// 示例 1:
//
// 输入: [[1,2], [1,3], [2,3]]
// 输出: [2,3]
// 解释: 给定的有向图如下:
//   1
//  / \
// v   v
// 2-->3
//
//
// 示例 2:
//
// 输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// 输出: [4,1]
// 解释: 给定的有向图如下:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3
//
//
// 注意:
//
//
// 二维数组大小的在3到1000范围内。
// 二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。
//
// Related Topics 树 深度优先搜索 并查集 图
// 👍 134 👎 0

bool check_circle(int arrived[], int size, int now, bool circled[]) {
    if (!now) return false;
    if (circled[now]) return true;
    circled[now] = true;
    if (check_circle(arrived, size, arrived[now], circled)) return true;
    return circled[now] = false;
}
int *findRedundantDirectedConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize) {
    bool circled[edgesSize + 1];
    int mul_i = 0; // 导致节点入度为2的边的下标
    int cir_i = 0; // 图中存在环，所有在环上的边中，记录最后一个的下标
    int *ans, arrived[edgesSize + 1];

    // 查找入度为2的点
    memset(arrived, 0, (edgesSize + 1) * sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        if (arrived[edges[i][1]]) {
            mul_i = i;
        } else {
            arrived[edges[i][1]] = edges[i][0];
        }
    }
    // 查找环路
    memset(circled, 0, (edgesSize + 1) * sizeof(bool));
    for (int i = 0; i < edgesSize; ++i) {
        if (!check_circle(arrived, edgesSize, i + 1, circled)) continue;
        for (int j = 0; j < edgesSize; ++j) {
            if (circled[edges[j][0]] && circled[edges[j][1]]) cir_i = j;
        }
        break;
    }

    *returnSize = 2, ans = calloc(2, sizeof(int));
    if (mul_i && cir_i) {
        // 存在入度为2的节点，且图中有环，当前边必然不是冗余边
        ans[0] = arrived[edges[mul_i][1]], ans[1] = edges[mul_i][1];
    } else if (mul_i) {
        // 存在入度为2的节点，且图中没有环，当前边必然是冗余边
        ans[0] = edges[mul_i][0], ans[1] = edges[mul_i][1];
    } else {
        // 所有节点入度为1，必然存在环，环中任意一个节点可移除
        memcpy(ans, edges[cir_i], 2 * sizeof(int));
    }

    return ans;
}