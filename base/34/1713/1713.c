// 给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。
//
// 每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到
// [1,4,3,1,2] 。 你可以在数组最开始或最后面添加整数。
//
// 请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
//
// 一个数组的 子序列指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。
// 比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。
//
//
//
// 示例 1：
//
// 输入：target = [5,1,3], arr = [9,4,2,3,4]
// 输出：2
// 解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
//
//
// 示例 2：
//
// 输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
// 输出：3
//
//
//
//
// 提示：
//
//
// 1 <= target.length, arr.length <= 105
// 1 <= target[i], arr[i] <= 109
// target 不包含任何重复元素。
//
// Related Topics 贪心 数组 哈希表 二分查找
// 👍 76 👎 0

typedef struct {
    int key, val;
    UT_hash_handle hh;
} * hash_t;
int minOperations(int *target, int targetSize, int *arr, int size) {
    int dp[size], ans = 0;
    hash_t hash = NULL, cur, next;
    for (int i = 0; i < targetSize; ++i) {
        cur = malloc(sizeof(*cur)), cur->key = target[i], cur->val = i;
        HASH_ADD_INT(hash, key, cur);
    }
    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(hash, &arr[i], cur);
        if (!cur) continue;
        if (!ans || dp[ans - 1] < cur->val) {
            dp[ans++] = cur->val;
        } else {
            int l = 0, r = ans - 1, mid;
            while (l <= r) {
                mid = (l + r) / 2;
                if (dp[mid] >= cur->val) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            dp[l] = cur->val;
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return targetSize - ans;
}
