/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/21 下午11:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1035.c"

START_TEST(test_official_1) {
    int nums1[] = { 1, 4, 2 }, nums2[] = { 1, 2, 4 };
    int target = 2, ans = maxUncrossedLines(nums1, LEN(nums1), nums2, LEN(nums2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums1[] = { 2, 5, 1, 2, 5 }, nums2[] = { 10, 5, 2, 1, 5, 2 };
    int target = 3, ans = maxUncrossedLines(nums1, LEN(nums1), nums2, LEN(nums2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums1[] = { 1, 3, 7, 1, 7, 5 }, nums2[] = { 1, 9, 2, 5, 1 };
    int target = 2, ans = maxUncrossedLines(nums1, LEN(nums1), nums2, LEN(nums2));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}