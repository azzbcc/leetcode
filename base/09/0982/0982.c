// 给你一个整数数组 nums ，返回其中 按位与三元组 的数目。
//
// 按位与三元组 是由下标 (i, j, k) 组成的三元组，并满足下述全部条件：
//
//
// 0 <= i < nums.length
// 0 <= j < nums.length
// 0 <= k < nums.length
// nums[i] & nums[j] & nums[k] == 0 ，其中 & 表示按位与运算符。
//
//
// 示例 1：
//
//
// 输入：nums = [2,1,3]
// 输出：12
// 解释：可以选出如下 i, j, k 三元组：
// (i=0, j=0, k=1) : 2 & 2 & 1
// (i=0, j=1, k=0) : 2 & 1 & 2
// (i=0, j=1, k=1) : 2 & 1 & 1
// (i=0, j=1, k=2) : 2 & 1 & 3
// (i=0, j=2, k=1) : 2 & 3 & 1
// (i=1, j=0, k=0) : 1 & 2 & 2
// (i=1, j=0, k=1) : 1 & 2 & 1
// (i=1, j=0, k=2) : 1 & 2 & 3
// (i=1, j=1, k=0) : 1 & 1 & 2
// (i=1, j=2, k=0) : 1 & 3 & 2
// (i=2, j=0, k=1) : 3 & 2 & 1
// (i=2, j=1, k=0) : 3 & 1 & 2
//
//
// 示例 2：
//
//
// 输入：nums = [0,0,0]
// 输出：27
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 1000
// 0 <= nums[i] < 2¹⁶
//
//
// Related Topics 位运算 数组 哈希表 👍 135 👎 0

typedef struct {
    int key, count;
    UT_hash_handle hh;
} *hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t find;
    HASH_FIND_INT(t, &key, find);
    return find;
}
void hash_record(hash_t *t, int key) {
    hash_t find = hash_find(*t, key);
    if (!find) {
        find = malloc(sizeof(*find)), find->key = key, find->count = 0;
        HASH_ADD_INT(*t, key, find);
    }
    find->count += 1;
}
int countTriplets(int *nums, int size) {
    int ans = 0;
    hash_t cur, next, hash = NULL;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            hash_record(&hash, nums[i] & nums[j]);
        }
    }
    for (int i = 0, tmp; i < size; ++i) {
        tmp = nums[i] ^ 0xffff;
        for (int now = tmp; now; now = tmp & (now - 1)) {
            if ((cur = hash_find(hash, now))) ans += cur->count;
        }
        if ((cur = hash_find(hash, 0))) ans += cur->count;
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
