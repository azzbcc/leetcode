/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/27 下午7:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0944.c"

START_TEST(test_official_1) {
    char *arr[] = { "cba", "daf", "ghi" };
    int target = 1, ans = minDeletionSize(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    char *arr[] = { "a", "b" };
    int target = 0, ans = minDeletionSize(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_3) {
    char *arr[] = { "zyx", "wvu", "tsr" };
    int target = 3, ans = minDeletionSize(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_failed) {
    char *arr[] = { "cba", "daf", "ghi" };
    int target = 1, ans = minDeletionSize(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}