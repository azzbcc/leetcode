// 给你一个整数数组 nums ，返回 nums 中所有 等差子序列 的数目。
//
// 如果一个序列中 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该序列为等差序列。
//
//
// 例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和 [3, -1, -5, -9] 都是等差序列。
// 再例如，[1, 1, 2, 5, 7] 不是等差序列。
//
//
// 数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列。
//
//
// 例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
//
//
// 题目数据保证答案是一个 32-bit 整数。
//
//
//
// 示例 1：
//
//
// 输入：nums = [2,4,6,8,10]
// 输出：7
// 解释：所有的等差子序列为：
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]
//
//
// 示例 2：
//
//
// 输入：nums = [7,7,7,7,7]
// 输出：16
// 解释：数组中的任意子序列都是等差子序列。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
//
// Related Topics 数组 动态规划
// 👍 155 👎 0

typedef struct {
    long dist;
    int count;
    UT_hash_handle hh;
} * hash_t;
int hash_count(hash_t t, long dist) {
    hash_t cur;
    HASH_FIND(hh, t, &dist, sizeof(long), cur);
    return cur ? cur->count : 0;
}
void hash_record(hash_t* t, long dist, int count) {
    hash_t cur;
    HASH_FIND(hh, *t, &dist, sizeof(long), cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->dist = dist, cur->count = 0;
        HASH_ADD(hh, *t, dist, sizeof(long), cur);
    }
    cur->count += count;
}
int numberOfArithmeticSlices(int* nums, int size) {
    int ans = 0;
    hash_t hash[size], cur, next;
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < size; ++i) {
        for (int j = 0, count; j < i; ++j, ans += count) {
            long dist = 0L + nums[i] - nums[j];
            count     = hash_count(hash[j], dist);
            hash_record(&hash[i], dist, count + 1);
        }
    }
    for (int i = 0; i < size; ++i) {
        HASH_ITER(hh, hash[i], cur, next) {
            HASH_DEL(hash[i], cur);
            free(cur);
        }
    }
    return ans;
}
