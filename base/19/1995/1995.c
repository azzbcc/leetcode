// 给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：
//
//
// nums[a] + nums[b] + nums[c] == nums[d] ，且
// a < b < c < d
//
//
//
//
// 示例 1：
//
// 输入：nums = [1,2,3,6]
// 输出：1
// 解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
//
//
// 示例 2：
//
// 输入：nums = [3,3,6,4,5]
// 输出：0
// 解释：[3,3,6,4,5] 中不存在满足要求的四元组。
//
//
// 示例 3：
//
// 输入：nums = [1,1,1,3,5]
// 输出：4
// 解释：满足要求的 4 个四元组如下：
// - (0, 1, 2, 3): 1 + 1 + 1 == 3
// - (0, 1, 3, 4): 1 + 1 + 3 == 5
// - (0, 2, 3, 4): 1 + 1 + 3 == 5
// - (1, 2, 3, 4): 1 + 1 + 3 == 5
//
//
//
//
// 提示：
//
//
// 4 <= nums.length <= 50
// 1 <= nums[i] <= 100
//
// Related Topics 数组 枚举 👍 2 👎 0

#if 0
int countQuadruplets(int *nums, int size) {
    int count = 0;
    for (int a = 0; a < size; ++a) {
        for (int b = a + 1; b < size; ++b) {
            int ab = nums[a] + nums[b];
            for (int c = b + 1; c < size; ++c) {
                int abc = ab + nums[c];
                for (int d = c + 1; d < size; ++d) {
                    count += abc == nums[d];
                }
            }
        }
    }
    return count;
}
#else
typedef struct {
    int val, count;
    UT_hash_handle hh;
} * hash_t;
void hash_record(hash_t *t, int val) {
    hash_t cur;
    HASH_FIND_INT(*t, &val, cur);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->val = val, cur->count = 0;
        HASH_ADD_INT(*t, val, cur);
    }
    cur->count += 1;
}
int hash_count(hash_t t, int val) {
    hash_t cur;
    HASH_FIND_INT(t, &val, cur);
    return cur ? cur->count : 0;
}
int countQuadruplets(int *nums, int size) {
    int count   = 0;
    hash_t hash = NULL, cur, next;
    hash_record(&hash, nums[0] + nums[1]);
    for (int c = 2; c < size; ++c) {
        for (int d = c + 1; d < size; ++d) {
            count += hash_count(hash, nums[d] - nums[c]);
        }
        for (int j = 0; j < c; ++j) {
            hash_record(&hash, nums[c] + nums[j]);
        }
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return count;
}
#endif