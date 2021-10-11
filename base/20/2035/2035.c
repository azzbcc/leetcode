// 给你一个长度为 2 * n 的整数数组。你需要将 nums 分成 两个 长度为 n 的数组，
// 分别求出两个数组的和，并 最小化 两个数组和之 差的绝对值 。nums 中每个元素都需要放入两个数组之一。
//
// 请你返回 最小 的数组和之差。
//
//
//
// 示例 1：
//
//
//
// 输入：nums = [3,9,7,3]
// 输出：2
// 解释：最优分组方案是分成 [3,9] 和 [7,3] 。
// 数组和之差的绝对值为 abs((3 + 9) - (7 + 3)) = 2 。
//
//
// 示例 2：
//
// 输入：nums = [-36,36]
// 输出：72
// 解释：最优分组方案是分成 [-36] 和 [36] 。
// 数组和之差的绝对值为 abs((-36) - (36)) = 72 。
//
//
// 示例 3：
//
//
//
// 输入：nums = [2,-1,0,4,-2,-9]
// 输出：0
// 解释：最优分组方案是分成 [2,4,-9] 和 [-1,0,-2] 。
// 数组和之差的绝对值为 abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0 。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 15
// nums.length == 2 * n
// -10⁷ <= nums[i] <= 10⁷
//
// 👍 12 👎 0

typedef struct {
    int val;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int val) {
    hash_t cur;
    HASH_FIND_INT(*t, &val, cur);
    if (cur) return;
    cur = malloc(sizeof(*cur)), cur->val = val;
    HASH_ADD_INT(*t, val, cur);
}
int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int minimumDifference(int *nums, int size) {
    int n = size / 2, sl = 0, sr = 0, ans = INT32_MAX;
    hash_t hl[n + 1], hr[n + 1], cur, next;

    memset(hl, 0, sizeof(hl)), memset(hr, 0, sizeof(hr));
    for (int i = 0; i < n; ++i) {
        sl += nums[i], sr -= nums[n + i];
    }
    hash_record(&hl[0], sl), hash_record(&hr[0], sr);
    for (int i = 1, gray = 0; i < 1 << n; ++i) {
        int pos = i & 1 ? 0 : __builtin_ffs(gray);
        if (gray ^= 1 << pos, 1 << pos & gray) {
            sl -= 2 * nums[pos], sr += 2 * nums[pos + n];
        } else {
            sl += 2 * nums[pos], sr -= 2 * nums[pos + n];
        }
        hash_record(&hl[__builtin_popcount(gray)], sl);
        hash_record(&hr[__builtin_popcount(gray)], sr);
    }
    for (int i = 0; i <= n; ++i) {
        int lc = 0, rc = 0;
        int ll[HASH_COUNT(hl[i])], rr[HASH_COUNT(hr[i])];
        HASH_ITER(hh, hl[i], cur, next) {
            HASH_DEL(hl[i], cur);
            ll[lc++] = cur->val;
            free(cur);
        }
        HASH_ITER(hh, hr[i], cur, next) {
            HASH_DEL(hr[i], cur);
            rr[rc++] = cur->val;
            free(cur);
        }
        qsort(ll, lc, sizeof(int), cmp);
        qsort(rr, rc, sizeof(int), cmp);
        for (int j = 0, k = rc - 1; j < lc; ++j) {
            for (; k >= 0 && ll[j] + rr[k] > 0; --k) {}
            if (k < 0) break;
            ans = fmin(ans, 0 - ll[j] - rr[k]);
        }
    }

    return ans;
}
