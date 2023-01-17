// 给你一个数组 nums ，数组中只包含非负整数。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321
// ，rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：
//
//
// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//
//
// 请你返回好下标对的数目。由于结果可能会很大，请将结果对 10⁹ + 7 取余 后返回。
//
//
//
// 示例 1：
//
// 输入：nums = [42,11,1,97]
// 输出：2
// 解释：两个坐标对为：
// - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
// - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
//
//
// 示例 2：
//
// 输入：nums = [13,10,35,24,76]
// 输出：4
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁵
// 0 <= nums[i] <= 10⁹
//
//
// Related Topics 数组 哈希表 数学 计数 👍 72 👎 0

#define MOD 1000000007
typedef struct {
    int val, count;
    UT_hash_handle hh;
} *hash_t;
int weight(int n) {
    int ans = 0;
    for (int t = n; t; t /= 10) {
        ans *= 10, ans += t % 10;
    }
    return n - ans;
}
int hash_record(hash_t *t, int val) {
    hash_t cur;
    HASH_FIND_INT(*t, &val, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->val = val, cur->count = 0;
        HASH_ADD_INT(*t, val, cur);
    }
    return cur->count++;
}
int countNicePairs(int *nums, int size) {
    int ans = 0;
    hash_t cur, next, hash = NULL;
    for (int i = 0; i < size; ++i) {
        ans = (ans + hash_record(&hash, weight(nums[i]))) % MOD;
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}