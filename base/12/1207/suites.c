/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/28 上午11:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1207.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 2, 1, 1, 3 };

    bool target = true, ans = uniqueOccurrences(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2 };

    bool target = false, ans = uniqueOccurrences(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[] = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };

    bool target = true, ans = uniqueOccurrences(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}