/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/29 下午1:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0403.c"

START_TEST(test_official_1) {
    int arr[]   = { 0, 1, 3, 5, 6, 8, 12, 17 };
    bool target = true, ans = canCross(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 0, 1, 2, 3, 4, 8, 9, 11 };
    bool target = false, ans = canCross(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}