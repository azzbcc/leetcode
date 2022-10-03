// 给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：
//
//
// 从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
//
//
// 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。
//
//
//
// 示例 1：
//
//
// 输入：nums = [2,2,1,1,5,3,3,5]
// 输出：7
// 解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数
// 字都出现了两次。
//
//
// 示例 2：
//
//
// 输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
// 输出：13
//
//
//
//
// 提示：
//
//
// 2 <= nums.length <= 10⁵
// 1 <= nums[i] <= 10⁵
//
//
// Related Topics 数组 哈希表 👍 112 👎 0

#if 0
typedef struct {
    int key, count;
    UT_hash_handle hh;
} * hash_t;
hash_t hash_find(hash_t t, int key) {
    hash_t find = NULL;
    HASH_FIND_INT(t, &key, find);
    return find;
}
int hash_count(hash_t t, int key) {
    hash_t find = hash_find(t, key);
    return find ? find->count : 0;
}
int hash_record(hash_t *t, int key, int plus) {
    hash_t find = hash_find(*t, key);
    if (!find) {
        find = malloc(sizeof(*find)), find->key = key, find->count = 0;
        HASH_ADD_INT(*t, key, find);
    }
    return find->count += plus;
}
void hash_destroy(hash_t *t) {
    hash_t cur, next;
    HASH_ITER(hh, *t, cur, next) {
        HASH_DEL(*t, cur);
        free(cur);
    }
}
int maxEqualFreq(int *nums, int size) {
    int max = 0, ans = 0;
    hash_t count = NULL, freq = NULL;
    for (int i = 0, tmp; i < size; ++i) {
        hash_record(&freq, hash_count(count, nums[i]), -1);
        hash_record(&freq, tmp = hash_record(&count, nums[i], 1), 1);
        if (max = fmax(max, tmp),
            max == 1 || hash_count(freq, max) == 1 && max + hash_count(freq, max - 1) * (max - 1) == i + 1
                || hash_count(freq, 1) == 1 && max * hash_count(freq, max) == i) {
            ans = fmax(ans, i + 1);
        }
    }
    hash_destroy(&freq);
    hash_destroy(&count);
    return ans;
}
#else
#define MAXN 100000
int maxEqualFreq(int *nums, int size) {
    int max = 0, ans = 0, count[MAXN + 1] = { 0 }, freq[MAXN + 1] = { 0 };
    for (int i = 0; i < size; ++i) {
        freq[count[nums[i]]]--, count[nums[i]]++, freq[count[nums[i]]]++, max = fmax(max, count[nums[i]]);
        if (max == 1 || freq[max] == 1 && max + freq[max - 1] * (max - 1) == i + 1
            || freq[1] == 1 && max * freq[max] == i) {
            ans = i + 1;
        }
    }
    return ans;
}
#endif