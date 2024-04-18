// 一个整数数组 original 可以转变成一个 双倍 数组 changed ，
// 转变方式为将 original 中每个元素 值乘以 2 加入数组中，然后将所有元素 随机打乱。
//
// 给你一个数组 changed ，如果 change 是 双倍 数组，那么请你返回 original数组，否则请返回空数组。
// original 的元素可以以任意 顺序返回。
//
//
//
// 示例 1：
//
// 输入：changed = [1,3,4,2,6,8]
// 输出：[1,3,4]
// 解释：一个可能的 original 数组为 [1,3,4] :
// - 将 1 乘以 2 ，得到 1 * 2 = 2。
// - 将 3 乘以 2 ，得到 3 * 2 = 6。
// - 将 4 乘以 2 ，得到 4 * 2 = 8。
// 其他可能的原数组方案为 [4,3,1] 或者 [3,1,4]。
//
//
// 示例 2：
//
// 输入：changed = [6,3,0,1]
// 输出：[]
// 解释：changed 不是一个双倍数组。
//
//
// 示例 3：
//
// 输入：changed = [1]
// 输出：[]
// 解释：changed 不是一个双倍数组。
//
//
//
//
// 提示：
//
//
// 1 <= changed.length <= 10⁵
// 0 <= changed[i] <= 10⁵
//
//
// Related Topics 贪心 数组 哈希表 排序 👍 54 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} hash_t;
hash_t *hash_find(hash_t *t, int key) {
    hash_t *cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t **t, hash_t *node) {
    hash_t *find = hash_find(*t, node->key);
    if (!find) {
        find = node, find->count = 0;
        HASH_ADD_INT(*t, key, find);
    }
    find->count += 1;
}
int cmp(hash_t *a, hash_t *b) {
    return a->key - b->key;
}
int *findOriginalArray(int *changed, int size, int *returnSize) {
    int len, help[size], c0 = 0;
    hash_t *cur, *next, *find, nodes[size], *hash = NULL;

    for (int i = 0; i < size; ++i) {
        if (!changed[i]) {
            c0++;
        } else {
            nodes[i] = (hash_t) { changed[i] };
            hash_record(&hash, &nodes[i]);
        }
    }
    if (c0 % 2 || (size - c0) % 2) {
        HASH_CLEAR(hh, hash);
        return malloc(*returnSize = 0);
    }
    memset(help, 0, (len = c0 / 2) * sizeof(int));
    HASH_SORT(hash, cmp);
    HASH_ITER(hh, hash, cur, next) {
        if (!cur->count) continue;
        find = hash_find(hash, cur->key * 2);
        if (!find || cur->count > find->count) {
            len = 0;
            break;
        }
        for (int i = 0; i < cur->count; help[len++] = cur->key, ++i) {}
        find->count -= cur->count;
    }

    int *ans = malloc((*returnSize = len) * sizeof(int));
    memcpy(ans, help, len * sizeof(int));
    HASH_CLEAR(hh, hash);
    return ans;
}
