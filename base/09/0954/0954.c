// 给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，
// 都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。
//
//
//
// 示例 1：
//
//
// 输入：arr = [3,1,3,6]
// 输出：false
//
//
// 示例 2：
//
//
// 输入：arr = [2,1,2,6]
// 输出：false
//
//
// 示例 3：
//
//
// 输入：arr = [4,-2,2,-4]
// 输出：true
// 解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
//
//
//
//
// 提示：
//
//
// 0 <= arr.length <= 3 * 10⁴
// arr.length 是偶数
// -10⁵ <= arr[i] <= 10⁵
//
// Related Topics 贪心 数组 哈希表 排序 👍 109 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t, node_t;
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
int cmp(hash_t a, hash_t b) {
    return abs(a->key) - abs(b->key);
}
bool canReorderDoubled(int *arr, int size) {
    bool ans = true;
    node_t nodes[size];
    hash_t hash = NULL, cur, next, find;

    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { arr[i] };
        hash_record(&hash, &nodes[i]);
    }
    HASH_SORT(hash, cmp);
    HASH_ITER(hh, hash, cur, next) {
        if (!cur->count) continue;
        find = hash_find(hash, cur->key * 2);
        if (!find || cur->count > find->count) {
            ans = false;
            break;
        }
        find->count -= cur->count;
    }
    HASH_CLEAR(hh, hash);

    return ans;
}
