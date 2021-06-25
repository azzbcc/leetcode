// 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8',
// '9'。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//
// 字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
//
//
//
// 示例 1:
//
//
// 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// 输出：6
// 解释：
// 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
// 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
// 因为当拨动到 "0102" 时这个锁就会被锁定。
//
//
// 示例 2:
//
//
// 输入: deadends = ["8888"], target = "0009"
// 输出：1
// 解释：
// 把最后一位反向旋转一次即可 "0000" -> "0009"。
//
//
// 示例 3:
//
//
// 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// 输出：-1
// 解释：
// 无法旋转到目标数字且不被锁定。
//
//
// 示例 4:
//
//
// 输入: deadends = ["0000"], target = "8888"
// 输出：-1
//
//
//
//
// 提示：
//
//
// 1 <= deadends.length <= 500
// deadends[i].length == 4
// target.length == 4
// target 不在 deadends 之中
// target 和 deadends[i] 仅由若干位数字组成
//
// Related Topics 广度优先搜索 数组 哈希表 字符串
// 👍 311 👎 0

#define MAXN 10000
typedef struct {
    int val, step;
    UT_hash_handle hh;
} * node_t, *hash_t;
node_t hash_find(hash_t t, int val) {
    hash_t cur;
    HASH_FIND_INT(t, &val, cur);
    return cur;
}
hash_t hash_record(hash_t *t, int val, int step) {
    hash_t cur = hash_find(*t, val);
    if (cur) return NULL;
    cur = malloc(sizeof(*cur)), cur->val = val, cur->step = step;
    HASH_ADD_INT(*t, val, cur);
    return cur;
}
int next_val(int now, int base, bool positive) {
    int digit = now / base % 10, other = now - digit * base;
    if (positive) {
        digit = (digit + 1) % 10;
    } else {
        digit = (digit + 9) % 10;
    }
    return other + digit * base;
}
int openLock(char **deadends, int size, char *target) {
    node_t queue[MAXN] = { NULL };
    int ans = -1, end = atoi(target);
    hash_t hash = NULL, dead = NULL, cur, next;
    for (int i = 0; i < size; ++i) {
        hash_record(&dead, atoi(deadends[i]), 0);
    }
    queue[0] = hash_record(&hash, 0, 0);
    for (int l = 0, r = 1; l < r; ++l) {
        node_t now = queue[l];
        if (hash_find(dead, now->val)) continue;
        if (now->val == end) {
            ans = now->step;
            break;
        }
        for (int base = 1; base < MAXN; base *= 10) {
            queue[r] = hash_record(&hash, next_val(now->val, base, true), now->step + 1);
            if (queue[r]) r++;
            queue[r] = hash_record(&hash, next_val(now->val, base, false), now->step + 1);
            if (queue[r]) r++;
        }
    }
    HASH_ITER(hh, dead, cur, next) {
        HASH_DEL(dead, cur);
        free(cur);
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }

    return ans;
}
