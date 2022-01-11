// 在一个 10⁶ x 10⁶ 的网格中，每个网格上方格的坐标为 (x, y) 。
//
// 现在从源方格 source = [sx, sy] 开始出发，意图赶往目标方格 target = [tx, ty] 。数组 blocked 是封锁的方格列表，其中每个
// blocked[i] = [xi, yi] 表示坐标为 (xi, yi) 的方格是禁止通行的。
//
// 每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 不 在给出的封锁列表 blocked 上。同时，不允许走出网格。
//
// 只有在可以通过一系列的移动从源方格 source 到达目标方格 target 时才返回 true。否则，返回 false。
//
//
//
// 示例 1：
//
//
// 输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
// 输出：false
// 解释：
// 从源方格无法到达目标方格，因为我们无法在网格中移动。
// 无法向北或者向东移动是因为方格禁止通行。
// 无法向南或者向西移动是因为不能走出网格。
//
// 示例 2：
//
//
// 输入：blocked = [], source = [0,0], target = [999999,999999]
// 输出：true
// 解释：
// 因为没有方格被封锁，所以一定可以到达目标方格。
//
//
//
//
// 提示：
//
//
// 0 <= blocked.length <= 200
// blocked[i].length == 2
// 0 <= xi, yi < 10⁶
// source.length == target.length == 2
// 0 <= sx, sy, tx, ty < 10⁶
// source != target
// 题目数据保证 source 和 target 不在封锁列表内
//
// Related Topics 深度优先搜索 广度优先搜索 数组 哈希表 👍 109 👎 0

#define MAXM 1000000
typedef struct {
    int x, y;
} point_t;
typedef struct {
    point_t key;
    UT_hash_handle hh;
} * hash_t;
const point_t wards[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
bool bfs(int **blocked, int size, point_t source, point_t target) {
    int maxn    = size * (size - 1) / 2 + 1;
    hash_t hash = NULL, cur, next;
    point_t queue[maxn], now;
    int front = 0, rear = 0;
    bool ans = false;

    cur = malloc(sizeof(*cur)), cur->key = source;
    HASH_ADD(hh, hash, key, sizeof(point_t), cur);
    for (int i = 0; i < size; ++i) {
        cur = malloc(sizeof(*cur)), cur->key = (point_t) { blocked[i][0], blocked[i][1] };
        HASH_ADD(hh, hash, key, sizeof(point_t), cur);
    }
    for (queue[rear++] = source; front < rear;) {
#define ans_goto(expr)                                                                                                 \
    if (expr) {                                                                                                        \
        ans = true;                                                                                                    \
        goto done;                                                                                                     \
    }
        now = queue[front++];
        ans_goto(now.x == target.x && now.y == target.y);
        for (int i = 0; i < sizeof(wards) / sizeof(wards[0]); ++i) {
            point_t ne = (point_t) { now.x + wards[i].x, now.y + wards[i].y };
            if (ne.x < 0 || ne.x >= MAXM || ne.y < 0 || ne.y >= MAXM) continue;
            HASH_FIND(hh, hash, &ne, sizeof(point_t), cur);
            if (cur) continue;
            ans_goto(rear + 1 >= maxn);
            queue[rear] = ne, rear = (rear + 1) % maxn;
            cur = malloc(sizeof(*cur)), cur->key = ne;
            HASH_ADD(hh, hash, key, sizeof(point_t), cur);
        }
    }
done:
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
bool isEscapePossible(int **blocked, int size, int *colSize, int *source, int sourceSize, int *target, int targetSize) {
    return bfs(blocked, size, (point_t) { source[0], source[1] }, (point_t) { target[0], target[1] })
           && bfs(blocked, size, (point_t) { target[0], target[1] }, (point_t) { source[0], source[1] });
}
