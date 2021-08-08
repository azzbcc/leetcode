/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/6 下午2:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0503.c"

START_TEST(test_official) {
    int arr[]    = { 1, 2, 1 };
    int target[] = { 2, -1, 2 };
    int len, *ans = nextGreaterElements(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_own) {
    int arr[]    = { -2, -2, -2 };
    int target[] = { -1, -1, -1 };
    int len, *ans = nextGreaterElements(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int arr[]    = { 1, 2, 3, 4, 5, 6, 5, 4, 5, 1, 2, 3 };
    int target[] = { 2, 3, 4, 5, 6, -1, 6, 5, 6, 2, 3, 4 };
    int len, *ans = nextGreaterElements(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}