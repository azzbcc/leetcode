// 给定两个数组，编写一个函数来计算它们的交集。
//
//
//
// 示例 1：
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2]
//
//
// 示例 2：
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[9,4]
//
//
//
// 说明：
//
//
// 输出结果中的每个元素一定是唯一的。
// 我们可以不考虑输出结果的顺序。
//
// Related Topics 排序 哈希表 双指针 二分查找
// 👍 261 👎 0

typedef struct {
    int num;
    UT_hash_handle hh;
} hash_t;
hash_t *hash_init(int nums[], int size) {
    hash_t *t = NULL, *cur = NULL;
    for (int i = 0; i < size; ++i) {
        HASH_FIND_INT(t, &nums[i], cur);
        if (cur) continue;
        cur      = malloc(sizeof(hash_t));
        cur->num = nums[i];
        HASH_ADD_INT(t, num, cur);
    }
    return t;
}
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    hash_t *cur, *next, *tmp;
    hash_t *t1 = hash_init(nums1, nums1Size), *t2 = hash_init(nums2, nums2Size);
    int len = 0, *ans = NULL;

    if (HASH_COUNT(t1) > HASH_COUNT(t2)) tmp = t1, t1 = t2, t2 = tmp;

    ans = malloc(HASH_COUNT(t2) * sizeof(int));
    HASH_ITER(hh, t1, cur, next) {
        HASH_FIND_INT(t2, &cur->num, tmp);
        if (tmp) ans[len++] = cur->num;
        HASH_DEL(t1, cur);
        free(cur);
    }
    HASH_ITER(hh, t2, cur, next) {
        HASH_DEL(t2, cur);
        free(cur);
    }

    *returnSize = len;
    return ans;
}
