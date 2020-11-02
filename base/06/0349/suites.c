/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/2 上午11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0349.c"

START_TEST(test_official_1) {
    int nums1[] = { 1, 2, 2, 1 }, nums2[] = { 2, 2 }, target[] = { 2 };
    int len, *ans = intersection(nums1, LEN(nums1), nums2, LEN(nums2), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int nums1[] = { 4, 9, 5 }, nums2[] = { 9, 4, 9, 8, 4 }, target[] = { 4, 9 };
    int len, *ans = intersection(nums1, LEN(nums1), nums2, LEN(nums2), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}