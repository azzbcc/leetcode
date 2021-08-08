/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/26 上午10:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1365.c"

START_TEST(test_official_1) {
    int arr[]    = { 8, 1, 2, 2, 3 };
    int target[] = { 4, 0, 1, 1, 3 };

    int len, *ans = smallerNumbersThanCurrent(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 6, 5, 4, 8 };
    int target[] = { 2, 1, 0, 3 };

    int len, *ans = smallerNumbersThanCurrent(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 7, 7, 7, 7 };
    int target[] = { 0, 0, 0, 0 };

    int len, *ans = smallerNumbersThanCurrent(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}