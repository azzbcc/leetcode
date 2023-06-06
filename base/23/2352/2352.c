// 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。
//
// 如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
//
//
//
// 示例 1：
//
//
//
//
// 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
// 输出：1
// 解释：存在一对相等行列对：
// - (第 2 行，第 1 列)：[2,7,7]
//
//
// 示例 2：
//
//
//
//
// 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// 输出：3
// 解释：存在三对相等行列对：
// - (第 0 行，第 0 列)：[3,1,2,2]
// - (第 2 行, 第 2 列)：[2,4,2,2]
// - (第 3 行, 第 2 列)：[2,4,2,2]
//
//
//
//
// 提示：
//
//
// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 10⁵
//
//
// Related Topics 数组 哈希表 矩阵 模拟 👍 51 👎 0

#define MAXN 200
typedef struct {
    int data[MAXN];
    int count;
    UT_hash_handle hh;
} *hash_t, node_t;
int equalPairs(int **grid, int size, int *colSize) {
    hash_t hash = NULL, cur, next;
    int ans = 0, len = size * sizeof(int);
    for (int i = 0, tmp[size]; i < size; ++i) {
        for (int j = 0; j < size; tmp[j] = grid[j][i], ++j) {}
        HASH_FIND(hh, hash, tmp, len, cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->count = 0;
            memcpy(cur->data, tmp, len);
            HASH_ADD(hh, hash, data, len, cur);
        }
        cur->count += 1;
    }
    for (int i = 0; i < size; ++i) {
        HASH_FIND(hh, hash, grid[i], len, cur);
        if (!cur) continue;
        ans += cur->count;
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
