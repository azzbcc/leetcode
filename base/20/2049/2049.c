// 给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。
// 同时给你一个下标从 0 开始的整数数组 parents表示这棵 树，其中 parents[i] 是节点 i 的父节点。
// 由于节点 0 是根，所以 parents[0] == -1 。
//
// 一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数。
// 求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若干个 非空 子树，
// 这个节点的 分数 为所有这些子树 大小的乘积 。
//
// 请你返回有 最高得分 节点的 数目 。
//
//
//
// 示例 1:
//
//
//
// 输入：parents = [-1,2,0,2,0]
// 输出：3
// 解释：
// - 节点 0 的分数为：3 * 1 = 3
// - 节点 1 的分数为：4 = 4
// - 节点 2 的分数为：1 * 1 * 2 = 2
// - 节点 3 的分数为：4 = 4
// - 节点 4 的分数为：4 = 4
// 最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
//
//
// 示例 2：
//
//
//
// 输入：parents = [-1,2,0]
// 输出：2
// 解释：
// - 节点 0 的分数为：2 = 2
// - 节点 1 的分数为：2 = 2
// - 节点 2 的分数为：1 * 1 = 1
// 最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
//
//
//
//
// 提示：
//
//
// n == parents.length
// 2 <= n <= 10⁵
// parents[0] == -1
// 对于 i != 0 ，有 0 <= parents[i] <= n - 1
// parents 表示一棵二叉树。
//
// Related Topics 树 深度优先搜索 数组 二叉树 👍 90 👎 0

typedef struct __tag_node node_t;
struct __tag_node {
    int child_count;
    node_t *child[2];
};
int dfs(node_t *root, int n, long *max, int *ans) {
    if (!root) return 0;
    long count = 0, score = 1;
    for (int i = 0, c; i < root->child_count; ++i) {
        c = dfs(root->child[i], n, max, ans);
        score *= c, count += c;
    }
    if (count + 1 < n) score *= n - count - 1;
    if (*max <= score) *ans = 1 + (*max == score ? *ans : 0), *max = score;
    return count + 1;
}
int countHighestScoreNodes(int *parents, int size) {
    int ans;
    long max = -1;
    node_t nodes[size], *root = NULL;

    memset(nodes, 0, sizeof(nodes));
    for (int i = 0; i < size; ++i) {
        if (parents[i] == -1) {
            root = &nodes[i];
        } else {
            nodes[parents[i]].child[nodes[parents[i]].child_count++] = &nodes[i];
        }
    }
    dfs(root, size, &max, &ans);
    return ans;
}
