/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/8 下午12:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0870.c"

START_TEST(test_official_1) {
    int nums1[] = { 2, 7, 11, 15 }, nums2[] = { 1, 10, 4, 11 };
    int target[] = { 2, 11, 7, 15 };
    int len, *ans = advantageCount(nums1, LEN(nums1), nums2, LEN(nums2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums1[] = { 12, 24, 8, 32 }, nums2[] = { 13, 25, 32, 11 };
    int target[] = { 24, 32, 8, 12 };
    int len, *ans = advantageCount(nums1, LEN(nums1), nums2, LEN(nums2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}