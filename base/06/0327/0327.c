// 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
//
// 说明:
// 最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。
//
// 示例:
//
// 输入: nums = [-2,5,-1], lower = -2, upper = 2,
// 输出: 3
// 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
//
// Related Topics 排序 树状数组 线段树 二分查找 分治算法
// 👍 184 👎 0

int cmp(const void *a, const void *b) {
    long *pa = a, *pb = b;
    if (*pa == *pb) {
        return 0;
    } else if (*pa > *pb) {
        return 1;
    } else {
        return -1;
    }
}
int count_all_values(long arr[], int size) {
    int c = 1;
    qsort(arr, size, sizeof(long), cmp);
    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) continue;
        arr[c++] = arr[i];
    }
    return c;
}
int index_of(const long array[], int size, long key) {
    long *found = bsearch(&key, array, size, sizeof(long), cmp);
    return found - array;
}
int prefix_sum(const int bit_array[], int pos) {
    int sum = 0;
    for (pos += 1; pos; pos -= pos & (-pos)) {
        sum += bit_array[pos];
    }
    return sum;
}
void update(int bit_array[], int size, int pos) {
    for (pos += 1; pos <= size; pos += pos & (-pos)) {
        bit_array[pos] += 1;
    }
}
int countRangeSum(int *nums, int numsSize, int lower, int upper) {
    if (!numsSize) return 0;

    int value_count = 0, ans = 0;
    long sums[numsSize + 1], all_values[numsSize * 3 + 3];

    sums[0] = all_values[0] = 0, all_values[1] = -lower, all_values[2] = -upper;
    for (int i = 0; i < numsSize; ++i) {
        sums[i + 1]           = sums[i] + nums[i];
        all_values[3 * i + 3] = sums[i + 1];
        all_values[3 * i + 4] = sums[i + 1] - lower;
        all_values[3 * i + 5] = sums[i + 1] - upper;
    }
    value_count = count_all_values(all_values, numsSize * 3 + 3);

    int bit_array[value_count + 1];
    memset(bit_array, 0, sizeof(bit_array));
    for (int i = 0, cur, left, right; i < numsSize + 1; ++i) {
        cur   = index_of(all_values, value_count, sums[i]);
        left  = index_of(all_values, value_count, sums[i] - upper);
        right = index_of(all_values, value_count, sums[i] - lower);

        ans += prefix_sum(bit_array, right) - prefix_sum(bit_array, left - 1);
        update(bit_array, value_count, cur);
    }

    return ans;
}
