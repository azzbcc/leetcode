// 给你一个 n 个节点的树（也就是一个无环连通无向图），节点编号从 0 到 n - 1 ，且恰好有 n - 1
// 条边，每个节点有一个值。树的 根节点 为 0号点。
//
// 给你一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj] 表示节点 uj
// 和节点 vj 在树中有一条边。
//
// 当 gcd(x, y) == 1 ，我们称两个数 x 和 y 是 互质的 ，其中 gcd(x, y) 是 x 和 y 的 最大公约数 。
//
// 从节点 i 到 根 最短路径上的点都是节点 i 的祖先节点。一个节点 不是 它自己的祖先节点。
//
// 请你返回一个大小为 n 的数组 ans ，其中 ans[i]是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是
// 互质的，如果不存在这样的祖先节点，ans[i] 为 -1 。
//
//
//
// 示例 1：
//
//
//
//
// 输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
// 输出：[-1,0,0,1]
// 解释：上图中，每个节点的值在括号中表示。
// - 节点 0 没有互质祖先。
// - 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
// - 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0
// 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
// - 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1
// 是离它最近的符合要求的祖先节点。
//
//
//
// 示例 2：
//
//
//
//
// 输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
// 输出：[-1,0,-1,0,0,0,-1]
//
//
//
//
// 提示：
//
//
// nums.length == n
// 1 <= nums[i] <= 50
// 1 <= n <= 105
// edges.length == n - 1
// edges[j].length == 2
// 0 <= uj, vj < n
// uj != vj
//
// Related Topics 树 深度优先搜索 广度优先搜索 数学
// 👍 4 👎 0

#define MAXN 100000
#define MAXM 50

bool map[MAXM + 1][MAXM + 1];
int pos[MAXM + 1];   // 上一次出现该值的点下标
int depth[MAXN + 1]; // 当前节点深度
int idx, h[MAXN + 1], e[MAXN * 2], ne[MAXN * 2];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int *init(int size) {
    int *ans = malloc(size * sizeof(int));

    idx = depth[0] = 0;
    memset(h, -1, size * sizeof(int));
    memset(pos, -1, sizeof(pos));
    memset(ans, -1, size * sizeof(int));
    for (int i = 1; i <= MAXM; ++i) {
        for (int j = 1; j <= MAXM; ++j) {
            map[i][j] = gcd(i, j) == 1;
        }
    }
    return ans;
}
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(const int nums[], int cur, int parent, int res[]) {
    int old = pos[nums[cur]];
    for (int i = 1; i <= MAXM; ++i) {
        if (!map[nums[cur]][i]) continue;
        if (pos[i] == -1) continue;
        if (res[cur] == -1 || depth[res[cur]] < depth[pos[i]]) res[cur] = pos[i];
    }

    pos[nums[cur]] = cur;
    for (int i = h[cur]; i >= 0; i = ne[i]) {
        if (e[i] == parent) continue;
        depth[e[i]] = depth[cur] + 1;
        dfs(nums, e[i], cur, res);
    }
    pos[nums[cur]] = old;
}
int *getCoprimes(int *nums, int numsSize, int **edges, int edgesSize, int *edgesColSize, int *returnSize) {
    int *ans = init(*returnSize = numsSize);
    for (int i = 0; i < edgesSize; ++i) {
        add(edges[i][0], edges[i][1]);
        add(edges[i][1], edges[i][0]);
    }
    dfs(nums, 0, -1, ans);
    return ans;
}
