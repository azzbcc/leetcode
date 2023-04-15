// 有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi 的双向路径。
// 在每个花园中，你打算种下四种花之一。
//
// 另外，所有花园 最多 有 3 条路径可以进入或离开.
//
// 你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
//
// 以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。
// 花的种类用 1、2、3、4表示。保证存在答案。
//
//
//
// 示例 1：
//
//
// 输入：n = 3, paths = [[1,2],[2,3],[3,1]]
// 输出：[1,2,3]
// 解释：
// 花园 1 和 2 花的种类不同。
// 花园 2 和 3 花的种类不同。
// 花园 3 和 1 花的种类不同。
// 因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
//
//
// 示例 2：
//
//
// 输入：n = 4, paths = [[1,2],[3,4]]
// 输出：[1,2,1,2]
//
//
// 示例 3：
//
//
// 输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
// 输出：[1,2,3,4]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁴
// 0 <= paths.length <= 2 * 10⁴
// paths[i].length == 2
// 1 <= xi, yi <= n
// xi != yi
// 每个花园 最多 有 3 条路径可以进入或离开
//
//
// Related Topics 深度优先搜索 广度优先搜索 图 👍 170 👎 0

typedef struct {
    int from;
    int to[3], size;
    UT_hash_handle hh;
} *hash_t;
hash_t hash_find(hash_t t, int from) {
    hash_t find;
    HASH_FIND_INT(t, &from, find);
    return find;
}
void hash_record(hash_t *t, int from, int to) {
    hash_t cur = hash_find(*t, from);
    if (!cur) {
        cur = calloc(1, sizeof(*cur)), cur->from = from;
        HASH_ADD_INT(*t, from, cur);
    }
    cur->to[cur->size++] = to;
}
int *gardenNoAdj(int n, int **paths, int size, int *colSize, int *returnSize) {
    hash_t hash = NULL, cur, next;
    for (int i = 0; i < size; ++i) {
        hash_record(&hash, paths[i][0], paths[i][1]);
        hash_record(&hash, paths[i][1], paths[i][0]);
    }
    int *ans = calloc(*returnSize = n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        bool flags[5] = { false };
        if (cur = hash_find(hash, i + 1), !cur) {
            ans[i] = 1;
            continue;
        }
        for (int j = 0; j < cur->size; ++j) {
            flags[ans[cur->to[j] - 1]] = true;
        }
        for (int j = 1; j < 5; ++j) {
            if (flags[j]) continue;
            ans[i] = j;
            break;
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}