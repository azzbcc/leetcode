/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/26 下午2:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0496.c"

START_TEST(test_official_1) {
    int nums1[] = { 4, 1, 2 }, nums2[] = { 1, 3, 4, 2 };
    int target[] = { -1, 3, -1 };
    int len, *ans = nextGreaterElement(nums1, LEN(nums1), nums2, LEN(nums2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums1[] = { 2, 4 }, nums2[] = { 1, 2, 3, 4 };
    int target[] = { 3, -1 };
    int len, *ans = nextGreaterElement(nums1, LEN(nums1), nums2, LEN(nums2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}