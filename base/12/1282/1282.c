// 有 n 个人被分成数量未知的组。每个人都被标记为一个从 0 到 n - 1 的唯一ID 。
//
// 给定一个整数数组 groupSizes ，其中
// groupSizes[i] 是第 i 个人所在的组的大小。例如，如果 groupSizes[1] = 3 ，则第 1 个人必须位于大小为 3 的组中。
//
// 返回一个组列表，使每个人 i 都在一个大小为
// groupSizes[i] 的组中。
//
// 每个人应该 恰好只 出现在 一个组 中，并且每个人必须在一个组中。如果有多个答案，返回其中 任何 一个。可以 保证 给定输入
// 至少有一个 有效的解。
//
//
//
// 示例 1：
//
//
// 输入：groupSizes = [3,3,3,3,3,1,3]
// 输出：[[5],[0,1,2],[3,4,6]]
// 解释：
// 第一组是 [5]，大小为 1，groupSizes[5] = 1。
// 第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
// 第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。
// 其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
//
//
// 示例 2：
//
//
// 输入：groupSizes = [2,1,3,3,3,2]
// 输出：[[1],[0,5],[2,3,4]]
//
//
//
//
// 提示：
//
//
// groupSizes.length == n
// 1 <= n <= 500
// 1 <= groupSizes[i] <= n
//
//
// Related Topics 数组 哈希表 👍 90 👎 0

typedef struct {
    int key;
    UT_hash_handle hh;
} node_t, *hash_t;
int **groupThePeople(int *groupSizes, int size, int *returnSize, int **returnColumnSizes) {
    int len = 0;
    node_t nodes[size];
    hash_t hash[size + 1], cur, next;

    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { i };
        HASH_ADD_INT(hash[groupSizes[i]], key, &nodes[i]);
    }
    for (int i = 1; i <= size; len += HASH_COUNT(hash[i]) / i, ++i) {}
    int **ans          = malloc((*returnSize = len) * sizeof(int *));
    *returnColumnSizes = malloc(len * sizeof(int));
    for (int i = 0, pos = 0, j = 0; i <= size; ++i) {
        if (!hash[i]) continue;
        HASH_ITER(hh, hash[i], cur, next) {
            if (!j) ans[pos] = malloc(((*returnColumnSizes)[pos] = i) * sizeof(int));
            ans[pos][j++] = cur->key;
            HASH_DEL(hash[i], cur);
            if (j == i) pos++, j = 0;
        }
    }
    return ans;
}
