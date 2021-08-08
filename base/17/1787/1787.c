// 给你一个整数数组 nums 和一个整数 k 。区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括
// left 和 right ）之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。
//
// 返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,2,0,3,0], k = 1
// 输出：3
// 解释：将数组 [1,2,0,3,0] 修改为 [0,0,0,0,0]
//
//
// 示例 2：
//
//
// 输入：nums = [3,4,5,2,1,7,3,4,7], k = 3
// 输出：3
// 解释：将数组 [3,4,5,2,1,7,3,4,7] 修改为 [3,4,7,3,4,7,3,4,7]
//
//
// 示例 3：
//
//
// 输入：nums = [1,2,4,1,2,5,1,2,6], k = 3
// 输出：3
// 解释：将数组[1,2,4,1,2,5,1,2,6] 修改为 [1,2,3,1,2,3,1,2,3]
//
//
//
// 提示：
//
//
// 1 <= k <= nums.length <= 2000
// 0 <= nums[i] < 210
//
// Related Topics 动态规划
// 👍 93 👎 0

#define MAXN 0x400
typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int key) {
    hash_t cur = NULL;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count++;
}
int hash_count(hash_t t, int key) {
    hash_t cur = NULL;
    HASH_FIND_INT(t, &key, cur);
    return cur ? cur->count : 0;
}
int minChanges(int *nums, int size, int k) {
    int dp[k][MAXN], g[k];

    memset(g, 0x3f, sizeof(g));
    memset(dp, 0x3f, sizeof(dp));

    for (int i = 0; i < k; ++i) {
        int cnt = 0;
        hash_t hash = NULL, cur, next;
        for (int j = i; j < size; j += k, cnt++) {
            hash_record(&hash, nums[j]);
        }
        for (int xor = 0; xor < MAXN; ++xor) {
            if (!i) {
                dp[i][xor] = fmin(dp[i][xor], cnt - hash_count(hash, xor));
            } else {
                dp[i][xor] = g[i - 1] + cnt;
                HASH_ITER(hh, hash, cur, next) {
                    dp[i][xor] = fmin(dp[i][xor], dp[i - 1][xor ^ cur->key] + cnt - cur->count);
                }
            }
            g[i] = fmin(g[i], dp[i][xor]);
        }
        HASH_ITER(hh, hash, cur, next) {
            HASH_DEL(hash, cur);
            free(cur);
        }
    }
    return dp[k - 1][0];
}