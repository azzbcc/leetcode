/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/19 下午8:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1636.c"

START_TEST(test_official_1) {
    int nums[]   = { 1, 1, 2, 2, 2, 3 };
    int target[] = { 3, 1, 1, 2, 2, 2 };
    int len, *ans = frequencySort(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[]   = { 2, 3, 1, 3, 2 };
    int target[] = { 1, 3, 3, 2, 2 };
    int len, *ans = frequencySort(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int nums[]   = { -1, 1, -6, 4, 5, -6, 1, 4, 1 };
    int target[] = { 5, -1, 4, 4, -6, -6, 1, 1, 1 };
    int len, *ans = frequencySort(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}