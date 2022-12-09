/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/9 上午9:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1780.c"

START_TEST(test_official_1) {
    int n = 12;
    ck_assert_int_eq(true, checkPowersOfThree(n));
}

START_TEST(test_official_2) {
    int n = 91;
    ck_assert_int_eq(true, checkPowersOfThree(n));
}

START_TEST(test_official_3) {
    int n = 21;
    ck_assert_int_eq(false, checkPowersOfThree(n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}