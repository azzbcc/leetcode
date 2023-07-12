/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/12 20:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2544.c"

START_TEST(test_official_1) {
    int n      = 521;
    int target = 4, ans = alternateDigitSum(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 111;
    int target = 1, ans = alternateDigitSum(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 886996;
    int target = 0, ans = alternateDigitSum(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}