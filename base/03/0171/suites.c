/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/30 下午1:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0171.c"

START_TEST(test_official_1) {
    char *title = "A";
    int target = 1, ans = titleToNumber(title);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *title = "AB";
    int target = 28, ans = titleToNumber(title);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *title = "ZY";
    int target = 701, ans = titleToNumber(title);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *title = "FXSHRXW";
    int target = 2147483647, ans = titleToNumber(title);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}