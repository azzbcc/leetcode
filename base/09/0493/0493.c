// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
//
// 你需要返回给定数组中的重要翻转对的数量。
//
// 示例 1:
//
//
// 输入: [1,3,2,3,1]
// 输出: 2
//
//
// 示例 2:
//
//
// 输入: [2,4,3,5,1]
// 输出: 3
//
//
// 注意:
//
//
// 给定数组的长度不会超过50000。
// 输入数组中的所有数字都在32位整数的表示范围内。
//
// Related Topics 排序 树状数组 线段树 二分查找 分治算法
// 👍 182 👎 0

#if 0
static int cmp(const void *a, const void *b) {
    long la = *( long * )a, lb = *( long * )b;
    if (la == lb) return 0;
    return la > lb ? 1 : -1;
}
int index_of(const long array[], int size, long key) {
    long *found = bsearch(&key, array, size, sizeof(long), cmp);
    return found - array;
}
int prefix(const int bit_array[], int pos) {
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
int reversePairs(int *nums, int numsSize) {
    if (!numsSize) return 0;

    int count = 1, ans = 0;
    long data[numsSize * 2];

    for (int i = 0; i < numsSize; ++i) {
        data[2 * i] = nums[i], data[2 * i + 1] = 2L * nums[i];
    }
    qsort(data, numsSize * 2, sizeof(long), cmp);
    for (int i = count; i < numsSize * 2; ++i) {
        if (data[i] != data[count - 1]) data[count++] = data[i];
    }

    int bit_array[count + 1];
    memset(bit_array, 0, sizeof(bit_array));
    for (int i = numsSize - 1, i1, i2; i >= 0; --i) {
        i1 = index_of(data, count, nums[i]);
        i2 = index_of(data, count, 2L * nums[i]);

        ans += prefix(bit_array, i1);
        update(bit_array, count, i2 + 1);
    }

    return ans;
}
#elif 0
int merge_sort(int *nums, int beg, int end) {
    if (beg >= end) return 0;
    int mid = (beg + end) / 2, lc = mid - beg + 1, rc = end - mid;
    int ans = merge_sort(nums, beg, mid) + merge_sort(nums, mid + 1, end);

    int left[lc], right[rc];
    memcpy(left, nums + beg, lc * sizeof(int));
    memcpy(right, nums + mid + 1, rc * sizeof(int));
    for (int l = 0, r = 0; r < rc; ++r) {
        for (long tmp = 2L * right[r]; l < lc && left[l] <= tmp; l++) {}
        if (l >= lc) break;
        ans += lc - l;
    }

    for (int l = 0, r = 0, k = beg; k <= end; ++k) {
        if (l >= lc) {
            nums[k] = right[r++];
        } else if (r >= rc || left[l] <= right[r]) {
            nums[k] = left[l++];
        } else {
            nums[k] = right[r++];
        }
    }

    return ans;
}
int reversePairs(int *nums, int numsSize) {
    return merge_sort(nums, 0, numsSize - 1);
}
#else
int reversePairs(int *nums, int numsSize) {
    if (!numsSize) return 0;

    int help[numsSize], ans = 0;
    for (int cur = 1, next = 2; cur < numsSize; cur = next, next *= 2) {
        memcpy(help, nums, sizeof(help));
        for (int i = 0; i < numsSize; i += next) {
            int lc = cur, rc = cur;
            if (i + cur >= numsSize) break;
            if (i + next >= numsSize) rc = numsSize - i - cur;
            for (int l = 0, r = 0; r < rc; ++r) {
                for (long tmp = 2L * help[i + cur + r]; l < lc && help[i + l] <= tmp; l++) {}
                if (l >= lc) break;
                ans += lc - l;
            }
            if (next >= numsSize) break;
            for (int l = 0, r = 0, k = i; l < lc || r < rc; ++k) {
                if (l >= lc) {
                    nums[k] = help[i + cur + r++];
                } else if (r >= rc || help[i + l] <= help[i + cur + r]) {
                    nums[k] = help[i + l++];
                } else {
                    nums[k] = help[i + cur + r++];
                }
            }
        }
    }
    return ans;
}
#endif