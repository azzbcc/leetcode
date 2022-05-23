// 你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：
//
//
// 0 表示障碍，无法触碰
// 1 表示地面，可以行走
// 比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
//
//
// 每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。
//
// 你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。
//
// 你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。
//
// 可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。
//
//
//
// 示例 1：
//
//
// 输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
// 输出：6
// 解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
//
// 示例 2：
//
//
// 输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
// 输出：-1
// 解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
//
//
// 示例 3：
//
//
// 输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
// 输出：6
// 解释：可以按与示例 1 相同的路径来砍掉所有的树。
// (0,0) 位置的树，可以直接砍去，不用算步数。
//
//
//
//
// 提示：
//
//
// m == forest.length
// n == forest[i].length
// 1 <= m, n <= 50
// 0 <= forest[i][j] <= 10⁹
//
// Related Topics 广度优先搜索 数组 矩阵 堆（优先队列） 👍 134 👎 0

typedef struct {
    int x, y;
} point_t;
typedef struct {
    point_t p;
    int weight;
} node_t;
const point_t wards[] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pa->weight - pb->weight;
}
int bfs(int **forest, int m, int n, point_t beg, point_t end) {
    bool visit[m][n];
    int front = 0, rear = 0;
    node_t now, queue[m * n];

    memset(visit, false, sizeof(visit));
    for (queue[rear++] = (node_t) { beg, 0 }, visit[beg.x][beg.y] = true; front < rear; ++front) {
        now = queue[front];
        if (now.p.x == end.x && now.p.y == end.y) return now.weight;
        for (int i = 0; i < sizeof(wards) / sizeof(point_t); ++i) {
            point_t next = (point_t) { now.p.x + wards[i].x, now.p.y + wards[i].y };
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (!forest[next.x][next.y] || visit[next.x][next.y]) continue;
            visit[next.x][next.y] = true, queue[rear++] = (node_t) { next, now.weight + 1 };
        }
    }
    return -1;
}
int cutOffTree(int **forest, int size, int *colSize) {
    point_t now = { 0 };
    int len = 0, ans = 0;
    node_t trees[size * *colSize];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < *colSize; ++j) {
            if (forest[i][j] <= 1) continue;
            trees[len++] = (node_t) { { i, j }, forest[i][j] };
        }
    }
    qsort(trees, len, sizeof(node_t), cmp);
    for (int i = 0, step; i < len; now = trees[i++].p, ans += step) {
        step = bfs(forest, size, *colSize, now, trees[i].p);
        if (step == -1) return -1;
    }
    return ans;
}
