/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/28 下午1:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

#include "0004.c"

START_TEST(test_own) {
    int nums1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, nums2[] = { 2, 3, 5, 6, 9 };
    double target = 5, ans = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2,
                                                    sizeof(nums2) / sizeof(nums2[0]));

    ck_assert_msg(fabs(ans - target) < 1e-6,
                  "error, except %.1lf but got %.1lf on lengthOfLongestSubstring([1, 2], [3, 4]).", target, ans);
}

START_TEST(test_official_1) {
    int nums1[] = { 1, 3 }, nums2[] = { 2 };
    double target = 2.0, ans = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2,
                                                      sizeof(nums2) / sizeof(nums2[0]));

    ck_assert_msg(fabs(ans - target) < 1e-6,
                  "error, except %.1lf but got %.1lf on lengthOfLongestSubstring([1, 3], [2]).", target, ans);
}

START_TEST(test_official_2) {
    int nums1[] = { 1, 2 }, nums2[] = { 3, 4 };
    double target = 2.5, ans = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2,
                                                      sizeof(nums2) / sizeof(nums2[0]));

    ck_assert_msg(fabs(ans - target) < 1e-6,
                  "error, except %.1lf but got %.1lf on lengthOfLongestSubstring([1, 2], [3, 4]).", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}