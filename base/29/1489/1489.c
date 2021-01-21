// 给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti]
// 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST)
// 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。
//
// 请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。
//
// 请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
//
//
//
// 示例 1：
//
//
//
// 输入：n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// 输出：[[0,1],[2,3,4,5]]
// 解释：上图描述了给定图。
// 下图是所有的最小生成树。
//
// 注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
// 边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
//
//
// 示例 2 ：
//
//
//
// 输入：n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
// 输出：[[],[0,1,2,3]]
// 解释：可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
//
//
//
//
// 提示：
//
//
// 2 <= n <= 100
// 1 <= edges.length <= min(200, n * (n - 1) / 2)
// edges[i].length == 3
// 0 <= fromi < toi < n
// 1 <= weighti <= 1000
// 所有 (fromi, toi) 数对都是互不相同的。
//
// Related Topics 深度优先搜索 并查集
// 👍 75 👎 0

typedef struct {
    int from, to, weight, index;
} line_t;
int cmp(const void *a, const void *b) {
    line_t *pa = ( line_t * )a, *pb = ( line_t * )b;
    return pa->weight - pb->weight;
}
int find(int ancestor[], int n) {
    if (ancestor[n] == n || ancestor[n] == -1) return ancestor[n] = n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int from, int to) {
    ancestor[find(ancestor, to)] = find(ancestor, from);
}
int **findCriticalAndPseudoCriticalEdges(int n, int **edges, int size, int *colSize, int *returnSize,
                                         int **returnColumnSizes) {

    // 边排序
    line_t lines[size];
    for (int i = 0; i < size; ++i) {
        lines[i] = (line_t) { edges[i][0], edges[i][1], edges[i][2], i };
    }
    qsort(lines, size, sizeof(line_t), cmp);

    // 并查集初始化
    int ancestor[n];
    int weight = 0, max_weight = 0;
    memset(ancestor, -1, sizeof(ancestor));
    for (int i = 0, line_count = 1; line_count < n && i < size; ++i) {
        if (find(ancestor, lines[i].from) == find(ancestor, lines[i].to)) continue;
        weight += max_weight = lines[i].weight;
        merge(ancestor, lines[i].from, lines[i].to);
    }
    for (; lines[size - 1].weight > max_weight; size--) {}

    int **ans          = malloc((*returnSize = 2) * sizeof(int *));
    *returnColumnSizes = malloc(2 * sizeof(int));
    for (int i = 0; i < 2; ++i) {
        (*returnColumnSizes)[i] = 0, ans[i] = malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; ++i) {
        int tmp_weight = 0, line_count = 0;
        memset(ancestor, -1, sizeof(ancestor));
        for (int j = 0; j < size; ++j) {
            if (i == j) continue;
            if (find(ancestor, lines[j].from) == find(ancestor, lines[j].to)) continue;
            line_count += 1, tmp_weight += lines[j].weight, merge(ancestor, lines[j].from, lines[j].to);
        }
        if (line_count + 1 != n || tmp_weight != weight) {
            // 当前是关键边
            ans[0][(*returnColumnSizes)[0]++] = lines[i].index;
            continue;
        }

        line_count = 1, tmp_weight = lines[i].weight;
        memset(ancestor, -1, sizeof(ancestor));
        merge(ancestor, lines[i].from, lines[i].to);
        for (int j = 0; j < size; ++j) {
            if (find(ancestor, lines[j].from) == find(ancestor, lines[j].to)) continue;
            line_count += 1, tmp_weight += lines[j].weight, merge(ancestor, lines[j].from, lines[j].to);
        }
        if (line_count + 1 == n && tmp_weight == weight) {
            // 当前是伪关键边
            ans[1][(*returnColumnSizes)[1]++] = lines[i].index;
        }
    }

    return ans;
}
