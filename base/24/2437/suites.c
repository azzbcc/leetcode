/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/13 上午12:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2437.c"

START_TEST(test_official_1) {
    char *time = "?5:00";
    int target = 2, ans = countTime(time);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *time = "0?:0?";
    int target = 100, ans = countTime(time);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *time = "??:??";
    int target = 1440, ans = countTime(time);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}