// 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
//
// 如果数组元素个数小于 2，则返回 0。
//
// 示例 1:
//
// 输入: [3,6,9,1]
// 输出: 3
// 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
//
// 示例 2:
//
// 输入: [10]
// 输出: 0
// 解释: 数组元素个数小于 2，因此返回 0。
//
// 说明:
//
//
// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
//
// Related Topics 排序
// 👍 264 👎 0

#if 0
static int cmp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
int maximumGap(int *nums, int numsSize) {
    if (numsSize < 2) return 0;

    int ans = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; ++i) {
        if (ans < nums[i] - nums[i - 1]) ans = nums[i] - nums[i - 1];
    }
    return ans;
}
#else
typedef struct {
    bool exists;
    int min, max;
} bucket_t;

int maximumGap(int *nums, int numsSize) {
    if (numsSize < 2) return 0;

    bucket_t buckets[numsSize + 1];
    int min = nums[0], max = nums[0], len, ans = 0;

    for (int i = 1; i < numsSize; ++i) {
        if (min > nums[i]) min = nums[i];
        if (max < nums[i]) max = nums[i];
    }
    if (min == max) return 0;

    len = (max - min) / (numsSize + 1) + 1;
    memset(buckets, 0, sizeof(buckets));
    for (int i = 0; i < numsSize; ++i) {
        int index = (nums[i] - min) / len;
        if (buckets[index].exists) {
            if (buckets[index].max < nums[i]) buckets[index].max = nums[i];
            if (buckets[index].min > nums[i]) buckets[index].min = nums[i];
        } else {
            buckets[index] = (bucket_t) { true, nums[i], nums[i] };
        }
    }

    numsSize = (max - min) / len;
    for (int cur = 0, next; cur < numsSize; cur = next) {
        for (next = cur; !buckets[++next].exists;) {}
        if (ans < buckets[next].min - buckets[cur].max) ans = buckets[next].min - buckets[cur].max;
    }

    return ans;
}
#endif