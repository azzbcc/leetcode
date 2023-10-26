/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/26 17:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2520.c"

START_TEST(test_official_1) {
    int num    = 7;
    int target = 1, ans = countDigits(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num    = 121;
    int target = 2, ans = countDigits(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int num    = 1248;
    int target = 4, ans = countDigits(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}