/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/11 下午12:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0227.c"

START_TEST(test_official_1) {
    char *s    = "3+2*2";
    int target = 7, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = " 3/2 ";
    int target = 1, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = " 3+5 / 2 ";
    int target = 5, ans = calculate(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}