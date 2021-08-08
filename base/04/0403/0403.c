// 一只青蛙想要过河。
// 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。青蛙可以跳上石子，但是不可以跳入水中。
//
// 给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。
//
// 开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。
//
// 如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。
// 另请注意，青蛙只能向前方（终点的方向）跳跃。
//
//
//
//
// 示例 1：
//
//
// 输入：stones = [0,1,3,5,6,8,12,17]
// 输出：true
// 解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2
// 个单位到第 4 块石子, 然 后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8
// 个石子（即最后一块石子）。
//
// 示例 2：
//
//
// 输入：stones = [0,1,2,3,4,8,9,11]
// 输出：false
// 解释：这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。
//
//
//
// 提示：
//
//
// 2 <= stones.length <= 2000
// 0 <= stones[i] <= 231 - 1
// stones[0] == 0
//
// Related Topics 动态规划
// 👍 237 👎 0

typedef struct {
    int step;
    UT_hash_handle hh;
} * hash_t;
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int find(int arr[], int beg, int size, int key) {
    int *p = bsearch(&key, arr + beg, size - beg, sizeof(int), cmp);
    return p ? p - arr : -1;
}
void hash_record(hash_t *t, int step) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &step, cur);
    if (cur) return;
    cur = malloc(sizeof(*cur)), cur->step = step;
    HASH_ADD_INT(*t, step, cur);
}
bool canCross(int *stones, int size) {
    hash_t dp[size], cur, next;

    memset(dp, 0, sizeof(dp));
    hash_record(&dp[0], 0);
    for (int i = 0; i + 1 < size; ++i) {
        HASH_ITER(hh, dp[i], cur, next) {
            for (int step = cur->step - 1, index; step <= cur->step + 1; ++step) {
                if (step <= 0) continue;
                index = find(stones, i, size, stones[i] + step);
                if (index > i) hash_record(&dp[index], step);
            }
            HASH_DEL(dp[i], cur);
            free(cur);
        }
    }
    hash_t end = dp[size - 1];
    if (!end) return false;
    HASH_ITER(hh, end, cur, next) {
        HASH_DEL(end, cur);
        free(cur);
    }
    return true;
}