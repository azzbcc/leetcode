// 和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//
// 现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
//
// 数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
//
//
//
// 示例 1：
//
//
// 输入：nums = [1,3,2,2,5,2,3,7]
// 输出：5
// 解释：最长的和谐子序列是 [3,2,2,2,3]
//
//
// 示例 2：
//
//
// 输入：nums = [1,2,3,4]
// 输出：2
//
//
// 示例 3：
//
//
// 输入：nums = [1,1,1,1]
// 输出：0
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 10⁴
// -10⁹ <= nums[i] <= 10⁹
//
// Related Topics 数组 哈希表 排序 👍 227 👎 0

#if 0
int cmp(const void *a, const void *b) {
    int pa = *( int * )a, pb = *( int * )b;
    return pa >= pb ? pa != pb : -1;
}
int findLHS(int *nums, int size) {
    int ans = 0, a = 0, b = -1;

    qsort(nums, size, sizeof(int), cmp);
    for (int i = 0; i < size; ++i) {
        if (nums[i] == nums[a]) {
        } else if (b < a) {
            b = i;
        } else if (nums[i] == nums[b]) {
        } else {
            if (nums[a] + 1 == nums[b]) ans = fmax(ans, i - a);
            a = b, b = i;
        }
    }
    if (nums[a] + 1 == nums[size - 1]) ans = fmax(ans, size - a);

    return ans;
}
#else
typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t cur;
    HASH_FIND_INT(t, &key, cur);
    return cur;
}
void hash_record(hash_t *t, int key) {
    hash_t cur = hash_find(*t, key);
    if (!cur) {
        cur = malloc(sizeof(*cur)), cur->key = key, cur->count = 0;
        HASH_ADD_INT(*t, key, cur);
    }
    cur->count += 1;
}
int findLHS(int *nums, int size) {
    int ans     = 0;
    hash_t hash = NULL, cur, next;

    for (int i = 0; i < size; ++i) {
        hash_record(&hash, nums[i]);
    }
    HASH_ITER(hh, hash, cur, next) {
        hash_t tmp = hash_find(hash, cur->key + 1);
        if (!tmp) continue;
        ans = fmax(ans, cur->count + tmp->count);
    }
    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
#endif