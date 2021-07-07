// 大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。
//
// 你可以搭配 任意 两道餐品做一顿大餐。
//
// 给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i 道餐品的美味程度，返回你可以用数组中的餐品做出的不同
// 大餐 的数量。结果需要对 109 + 7 取余。
//
// 注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。
//
//
//
// 示例 1：
//
//
// 输入：deliciousness = [1,3,5,7,9]
// 输出：4
// 解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2
// 的幂。
//
//
// 示例 2：
//
//
// 输入：deliciousness = [1,1,1,3,3,3,7]
// 输出：15
// 解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
//
//
//
// 提示：
//
//
// 1 <= deliciousness.length <= 105
// 0 <= deliciousness[i] <= 220
//
// Related Topics 数组 哈希表
// 👍 70 👎 0

#define MOD 1000000007
typedef struct {
    int num;
    int count;
    UT_hash_handle hh;
} * hash_t;
int hash_count(hash_t t, int num) {
    hash_t cur;
    HASH_FIND_INT(t, &num, cur);
    return cur ? cur->count : 0;
}
int countPairs(int *deliciousness, int size) {
    long ans    = 0;
    hash_t hash = NULL, cur, next;
    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(hash, &deliciousness[i], cur);
        if (!cur) {
            cur = malloc(sizeof(*cur)), cur->num = deliciousness[i], cur->count = 0;
            HASH_ADD_INT(hash, num, cur);
        }
        cur->count += 1;
    }

    HASH_ITER(hh, hash, cur, next) {
        for (int sum = 0x200000; sum >= cur->num && sum; sum >>= 1) {
            int other = sum - cur->num, count = hash_count(hash, other);
            if (!count) continue;
            if (other == cur->num) {
                ans = (ans + 1L * count * (count - 1) / 2) % MOD;
            } else {
                ans = (ans + 1L * count * cur->count) % MOD;
            }
        }
        HASH_DEL(hash, cur);
        free(cur);
    }

    return ans;
}