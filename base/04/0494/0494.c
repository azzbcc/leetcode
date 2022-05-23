// 给你一个整数数组 nums 和一个整数 target 。
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,1,1,1,1], target = 3
// 输出：5
// 解释：一共有 5 种方法让最终目标和为 3 。
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
//
//
// 示例 2：
//
//
// 输入：nums = [1], target = 1
// 输出：1
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 100
//
// Related Topics 深度优先搜索 动态规划
// 👍 727 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int key, int count) {
    hash_t cur;
    HASH_FIND_INT(*t, &key, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += count;
}
int findTargetSumWays(int *nums, int size, int target) {
    int ans = 0, suffix[size];
    hash_t h_old, h_new = NULL, cur, next;

    hash_record(&h_new, 0, 1);
    for (int i = size - 1, sum = 0; i >= 0; --i) {
        suffix[i] = sum += abs(nums[i]);
    }
    for (int i = 0; i < size; ++i) {
        h_old = h_new, h_new = NULL;
        HASH_ITER(hh, h_old, cur, next) {
            HASH_DEL(h_old, cur);
            if (cur->key >= target - suffix[i] && cur->key <= target + suffix[i]) {
                hash_record(&h_new, cur->key + nums[i], cur->count);
                hash_record(&h_new, cur->key - nums[i], cur->count);
            }
            free(cur);
        }
    }
    HASH_ITER(hh, h_new, cur, next) {
        HASH_DEL(h_new, cur);
        if (cur->key == target) ans = cur->count;
        free(cur);
    }

    return ans;
}