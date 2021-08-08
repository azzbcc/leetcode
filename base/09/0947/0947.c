// n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
//
// 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。
//
// 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。
//
//
//
//
// 示例 1：
//
//
// 输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// 输出：5
// 解释：一种移除 5 块石头的方法如下所示：
// 1. 移除石头 [2,2] ，因为它和 [2,1] 同行。
// 2. 移除石头 [2,1] ，因为它和 [0,1] 同列。
// 3. 移除石头 [1,2] ，因为它和 [1,0] 同行。
// 4. 移除石头 [1,0] ，因为它和 [0,0] 同列。
// 5. 移除石头 [0,1] ，因为它和 [0,0] 同行。
// 石头 [0,0] 不能移除，因为它没有与另一块石头同行/列。
//
// 示例 2：
//
//
// 输入：stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// 输出：3
// 解释：一种移除 3 块石头的方法如下所示：
// 1. 移除石头 [2,2] ，因为它和 [2,0] 同行。
// 2. 移除石头 [2,0] ，因为它和 [0,0] 同列。
// 3. 移除石头 [0,2] ，因为它和 [0,0] 同行。
// 石头 [0,0] 和 [1,1] 不能移除，因为它们没有与另一块石头同行/列。
//
// 示例 3：
//
//
// 输入：stones = [[0,0]]
// 输出：0
// 解释：[0,0] 是平面上唯一一块石头，所以不可以移除它。
//
//
//
// 提示：
//
//
// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 104
// 不会有两块石头放在同一个坐标点上
//
// Related Topics 深度优先搜索 并查集
// 👍 142 👎 0
typedef struct {
    int key, index;
    UT_hash_handle hh;
} hash_t;

void hash_record(hash_t **table, int key, int val) {
    hash_t *cur = malloc(sizeof(hash_t));
    cur->key = key, cur->index = val;
    HASH_ADD_INT(*table, key, cur);
}
int hash_val(hash_t *table, int key) {
    hash_t *search = NULL;
    HASH_FIND_INT(table, &key, search);
    return search ? search->index : -1;
}
void hash_destroy(hash_t *table) {
    hash_t *cur = NULL, *next = NULL;
    HASH_ITER(hh, table, cur, next) {
        HASH_DEL(table, cur);
        free(cur);
    }
}
int find(int ancestor[], int n) {
    if (ancestor[n] == n) return n;
    return ancestor[n] = find(ancestor, ancestor[n]);
}
void merge(int ancestor[], int from, int to) {
    ancestor[find(ancestor, to)] = find(ancestor, from);
}
int removeStones(int **stones, int size, int *colSize) {
    int ancestor[size], ans = 0;
    hash_t *row_hash = NULL, *col_hash = NULL;

    for (int i = 0, row, col; i < size; ++i) {
        ancestor[i] = i;
        if (row = hash_val(row_hash, stones[i][0]), row >= 0) {
            merge(ancestor, row, i);
        } else {
            hash_record(&row_hash, stones[i][0], i);
        }
        if (col = hash_val(col_hash, stones[i][1]), col >= 0) {
            merge(ancestor, col, i);
        } else {
            hash_record(&col_hash, stones[i][1], i);
        }
    }
    for (int i = 0; i < size; ++i) {
        ans += find(ancestor, i) != i;
    }
    hash_destroy(row_hash);
    hash_destroy(col_hash);

    return ans;
}
