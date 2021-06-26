// 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
//
// 一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
//
// 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
//
// 给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
//
// 示例：
//
//
// 输入：board = [[1,2,3],[4,0,5]]
// 输出：1
// 解释：交换 0 和 5 ，1 步完成
//
//
//
// 输入：board = [[1,2,3],[5,4,0]]
// 输出：-1
// 解释：没有办法完成谜板
//
//
//
// 输入：board = [[4,1,2],[5,0,3]]
// 输出：5
// 解释：
// 最少完成谜板的最少移动次数是 5 ，
// 一种移动路径:
// 尚未移动: [[4,1,2],[5,0,3]]
// 移动 1 次: [[4,1,2],[0,5,3]]
// 移动 2 次: [[0,1,2],[4,5,3]]
// 移动 3 次: [[1,0,2],[4,5,3]]
// 移动 4 次: [[1,2,0],[4,5,3]]
// 移动 5 次: [[1,2,3],[4,5,0]]
//
//
//
// 输入：board = [[3,2,4],[1,5,0]]
// 输出：14
//
//
// 提示：
//
//
// board 是一个如上所述的 2 x 3 的数组.
// board[i][j] 是一个 [0, 1, 2, 3, 4, 5] 的排列.
//
// Related Topics 广度优先搜索 数组 矩阵
// 👍 167 👎 0

typedef struct {
    int pos;
    int step;
    int data[6];
    UT_hash_handle hh;
} node_t, *hash_t;
bool node_next(node_t now, int forward, node_t *next) {
    static int offset[] = { -3, 3, -1, 1 };

    next->pos = now.pos + offset[forward];
    if (next->pos < 0 || next->pos > 5) return false;
    if (forward > 1 && now.pos / 3 != next->pos / 3) return false;

    next->step = now.step + 1;
    memcpy(next->data, now.data, sizeof(now.data));
    for (int tmp               = next->data[next->pos]; tmp != next->data[now.pos];
         next->data[next->pos] = next->data[now.pos], next->data[now.pos] = tmp) {}
    return true;
}
int slidingPuzzle(int **board, int size, int *colSize) {
    hash_t cur, hash = NULL;
    node_t queue[361] = { 0 };
    int ans[6]        = { board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2] };

    queue[0] = (node_t) { .data = { 1, 2, 3, 4, 5, 0 }, .pos = 5 };
    HASH_ADD(hh, hash, data, sizeof(ans), &queue[0]);
    for (int l = 0, r = 1; l < r; ++l) {
        node_t now = queue[l];
        for (int i = 0; i < 4; ++i) {
            if (node_next(now, i, &queue[r])) {
                HASH_FIND(hh, hash, queue[r].data, sizeof(ans), cur);
                if (cur) continue;
                HASH_ADD(hh, hash, data, sizeof(ans), &queue[r]);
                r++;
            }
        }
    }
    HASH_FIND(hh, hash, ans, sizeof(ans), cur);
    HASH_CLEAR(hh, hash);

    return cur ? cur->step : -1;
}
