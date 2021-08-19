/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/18 下午10:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0552.c"

START_TEST(test_official_1) {
    int n      = 2;
    int target = 8, ans = checkRecord(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 1;
    int target = 3, ans = checkRecord(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 10101;
    int target = 183236316, ans = checkRecord(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}