//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
// 你可以假设 nums1 和 nums2 不会同时为空。
//
//
//
// 示例 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
//则中位数是 2.0
//
//
// 示例 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
//
// Related Topics 数组 二分查找 分治算法
// 👍 2972 👎 0

#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)

double findMedianSortedArrays(int *pm, int m, int *pn, int n) {
    if (m > n) return findMedianSortedArrays(pn, n, pm, m);

    int beg = 0, end = m;
    while (beg <= end) {
        int mi = (beg + end) / 2;
        int ni = (m + n + 1) / 2 - mi;

        if (mi < m && ni > 0 && pm[mi] < pn[ni - 1]) {
            beg = mi + 1;
            continue;
        }
        if (mi > 0 && ni < n && pm[mi - 1] > pn[ni]) {
            end = mi - 1;
            continue;
        }

        int left = 0;
        if (!mi) {
            left = pn[ni - 1];
        } else if (!ni) {
            left = pm[mi - 1];
        } else {
            left = MAX(pm[mi - 1], pn[ni - 1]);
        }
        if ((m + n) % 2) return left;

        int right = 0;
        if (mi >= m) {
            right = pn[ni];
        } else if (ni >= n) {
            right = pm[mi];
        } else {
            right = MIN(pm[mi], pn[ni]);
        }
        return (left + right) / 2.0;
    }
    return 0;
}
