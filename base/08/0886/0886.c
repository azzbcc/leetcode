// 给定一组 n 人（编号为 1, 2, ..., n），
// 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。
//
// 给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和
// bi的人归入同一组。当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
//
//
//
//
//
//
// 示例 1：
//
//
// 输入：n = 4, dislikes = [[1,2],[1,3],[2,4]]
// 输出：true
// 解释：group1 [1,4], group2 [2,3]
//
//
// 示例 2：
//
//
// 输入：n = 3, dislikes = [[1,2],[1,3],[2,3]]
// 输出：false
//
//
// 示例 3：
//
//
// 输入：n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// 输出：false
//
//
//
//
// 提示：
//
//
// 1 <= n <= 2000
// 0 <= dislikes.length <= 10⁴
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= n
// ai < bi
// dislikes 中每一组都 不同
//
//
//
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 243 👎 0

typedef struct list_node list_t;
struct list_node {
    int val;
    list_t *next;
};
void map_add(list_t *map[], int a, int b, list_t *node) {
    node->val = b, node->next = map[a], map[a] = node;
}
bool dfs(list_t *map[], int colors[], int cur, int color) {
    colors[cur] = color;
    for (list_t *p = map[cur]; p; p = p->next) {
        if (colors[p->val] && colors[cur] == colors[p->val]) return false;
        if (!colors[p->val] && !dfs(map, colors, p->val, -color)) return false;
    }
    return true;
}
bool possibleBipartition(int n, int **dislikes, int size, int *colSize) {
    if (!size) return true;

    int colors[n];
    list_t nodes[size * 2], *map[n];
    memset(map, 0, sizeof(map));
    memset(colors, 0, sizeof(colors));
    for (int i = 0; i < size; ++i) {
        map_add(map, dislikes[i][0] - 1, dislikes[i][1] - 1, &nodes[2 * i + 0]);
        map_add(map, dislikes[i][1] - 1, dislikes[i][0] - 1, &nodes[2 * i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        if (!colors[i] && !dfs(map, colors, i, 1)) return false;
    }
    return true;
}
