// 给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
//
// 机器人从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。
//
// 如果路径在任何位置上出现相交的情况，也就是走到之前已经走过的位置，请返回 True ；否则，返回 False 。
//
//
//
// 示例 1：
//
//
//
// 输入：path = "NES"
// 输出：false
// 解释：该路径没有在任何位置相交。
//
// 示例 2：
//
//
//
// 输入：path = "NESWW"
// 输出：true
// 解释：该路径经过原点两次。
//
//
//
// 提示：
//
//
// 1 <= path.length <= 10^4
// path 仅由 {'N', 'S', 'E', 'W} 中的字符组成
//
// Related Topics 字符串
// 👍 21 👎 0

typedef struct {
    int val;
    UT_hash_handle hh;
} * hash_t;
bool hash_record(hash_t *t, int val) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &val, cur);
    if (cur) return false;
    cur = malloc(sizeof(*cur)), cur->val = val;
    HASH_ADD_INT(*t, val, cur);
    return true;
}
bool isPathCrossing(char *path) {
    bool exist  = false;
    int base    = 0;
    hash_t hash = NULL, cur, next;
    hash_record(&hash, base);
    for (int i = 0; !exist && path[i]; ++i) {
        if (path[i] == 'N') {
            base += 10000;
        } else if (path[i] == 'S') {
            base -= 10000;
        } else if (path[i] == 'W') {
            base += 1;
        } else if (path[i] == 'E') {
            base -= 1;
        }
        exist = !hash_record(&hash, base);
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return exist;
}