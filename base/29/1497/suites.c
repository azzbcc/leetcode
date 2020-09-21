/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 下午8:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1497.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5, 10, 6, 7, 8, 9 }, k = 5;
    bool target = true, ans = canArrange(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, 4, 5, 6 }, k = 7;
    bool target = true, ans = canArrange(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_3) {
    int arr[] = { 1, 2, 3, 4, 5, 6 }, k = 10;
    bool target = false, ans = canArrange(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_4) {
    int arr[] = { -10, 10 }, k = 2;
    bool target = true, ans = canArrange(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_5) {
    int arr[] = { -1, 1, -2, 2, -3, 3, -4, 4 }, k = 3;
    bool target = true, ans = canArrange(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}