/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/27 下午6:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0881.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2 }, limit = 3;
    int target = 1, ans = numRescueBoats(arr, sizeof(arr) / sizeof(arr[0]), limit);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    int arr[] = { 3, 2, 2, 1 }, limit = 3;
    int target = 3, ans = numRescueBoats(arr, sizeof(arr) / sizeof(arr[0]), limit);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_3) {
    int arr[] = { 3, 5, 3, 4 }, limit = 5;
    int target = 4, ans = numRescueBoats(arr, sizeof(arr) / sizeof(arr[0]), limit);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}