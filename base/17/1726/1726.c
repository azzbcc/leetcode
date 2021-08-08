// 给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d
// 都是 nums 中的元素，且 a != b != c != d 。
//
//
//
// 示例 1：
//
// 输入：nums = [2,3,4,6]
// 输出：8
// 解释：存在 8 个满足题意的元组：
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (3,4,2,6) , (3,4,6,2) , (4,3,6,2)
//
//
// 示例 2：
//
// 输入：nums = [1,2,4,5,10]
// 输出：16
// 解释：存在 16 个满足题意的元组：
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
//
//
// 示例 3：
//
// 输入：nums = [2,3,4,6,8,12]
// 输出：40
//
//
// 示例 4：
//
// 输入：nums = [2,3,5,7]
// 输出：0
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// nums 中的所有元素 互不相同
//
// Related Topics 数组
// 👍 1 👎 0

typedef struct {
    int mul, count;
    UT_hash_handle hh;
} * hash_t;
int hash_record(hash_t *hash, int mul) {
    hash_t cur = NULL;
    HASH_FIND_INT(*hash, &mul, cur);
    if (!cur) {
        cur      = malloc(sizeof(*cur));
        cur->mul = mul, cur->count = 0;
        HASH_ADD_INT(*hash, mul, cur);
    }
    return cur->count++;
}
void hash_destroy(hash_t hash) {
    hash_t cur = NULL, next = NULL;
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
}
int tupleSameProduct(int *nums, int size) {
    int ans     = 0;
    hash_t hash = NULL;

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            ans += hash_record(&hash, nums[i] * nums[j]);
        }
    }
    hash_destroy(hash);

    return ans * 8;
}
