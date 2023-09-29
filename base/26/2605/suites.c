/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/29 14:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2605.c"

START_TEST(test_official_1) {
    int nums1[] = { 4, 1, 3 }, nums2[] = { 5, 7 };
    int target = 15, ans = minNumber(nums1, LEN(nums1), nums2, LEN(nums2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums1[] = { 3, 5, 2, 6 }, nums2[] = { 3, 1, 7 };
    int target = 3, ans = minNumber(nums1, LEN(nums1), nums2, LEN(nums2));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}