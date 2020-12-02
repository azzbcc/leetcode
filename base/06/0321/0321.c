// 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m +
// n) 个数字拼接 成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
//
// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
//
// 说明: 请尽可能地优化你算法的时间和空间复杂度。
//
// 示例 1:
//
// 输入:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// 输出:
// [9, 8, 6, 5, 3]
//
// 示例 2:
//
// 输入:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// 输出:
// [6, 7, 6, 0, 4]
//
// 示例 3:
//
// 输入:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// 输出:
// [9, 8, 9]
// Related Topics 贪心算法 动态规划
// 👍 269 👎 0

int min(int a, int b) {
    return a < b ? a : b;
}
int compare(int marr[], int m, int narr[], int n) {
    if (m < n) return -1;
    if (m > n) return 1;
    return memcmp(marr, narr, m * sizeof(int));
}
void merge(int nums[], int split, int size) {
    if (split <= 0 || split >= size) return;

    int tmp[size];
    for (int i = 0, j = split, k = 0, len = 1; k < size;) {
        int cmp = compare(nums + i, min(len, split - i), nums + j, min(len, size - j));
        if (cmp < 0) {
            tmp[k++] = nums[j++], len = 1;
        } else if (cmp > 0) {
            tmp[k++] = nums[i++], len = 1;
        } else if (size - k == 2 * len) {
            memcpy(&tmp[k], nums + i, len * sizeof(int));
            memcpy(&tmp[k + len], nums + i, len * sizeof(int));
            break;
        } else {
            len++;
        }
    }
    memcpy(nums, tmp, sizeof(tmp));
}
void init(int nums[], int m, int stack[], int n) {
    for (int i = 0, top = 0, skip = 0; i < m; i++) {
        while (top > 0 && stack[top - 1] < nums[i] && skip < m - n) {
            top--, skip++;
        }
        if (top < n) {
            stack[top++] = nums[i];
        } else {
            skip++;
        }
    }
}
int *maxNumber(int *nums1, int m, int *nums2, int n, int k, int *returnSize) {
    int *ans = calloc(*returnSize = k, sizeof(int));
    for (int i = 0, tmp[k]; i <= k && i <= m; ++i) {
        if (k - i > n) continue;
        init(nums1, m, &tmp[0], i);
        init(nums2, n, &tmp[i], k - i);
        merge(tmp, i, k);
        if (compare(ans, k, tmp, k) < 0) memcpy(ans, tmp, sizeof(tmp));
    }

    return ans;
}