// Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize
// 张连续的牌组成。
//
// 给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true
// ；否则，返回 false 。
//
//
//
//
//
//
// 示例 1：
//
//
// 输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// 输出：true
// 解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
//
// 示例 2：
//
//
// 输入：hand = [1,2,3,4,5], groupSize = 4
// 输出：false
// 解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
//
//
//
// 提示：
//
//
// 1 <= hand.length <= 10⁴
// 0 <= hand[i] <= 10⁹
// 1 <= groupSize <= hand.length
//
//
//
//
// 注意：此题目与 1296 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Related Topics 贪心 数组 哈希表 排序 👍 154 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} node_t, *hash_t;
int cmp(hash_t a, hash_t b) {
    return a->key - b->key;
}
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, node_t *node) {
    hash_t cur = hash_find(*t, node->key);
    if (!cur) {
        cur = node;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
bool isNStraightHand(int *hand, int size, int groupSize) {
    if (size % groupSize) return false;

    node_t nodes[size];
    hash_t hash = NULL, cur;
    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { hand[i] };
        hash_record(&hash, &nodes[i]);
    }
    HASH_SORT(hash, cmp);
    for (int first; hash;) {
        first = hash->key;
        for (int i = 0; i < groupSize; ++i) {
            cur = hash_find(hash, first + i);
            if (!cur) {
                HASH_CLEAR(hh, hash);
                return false;
            }
            if (!--cur->count) HASH_DEL(hash, cur);
        }
    }

    HASH_CLEAR(hh, hash);
    return true;
}