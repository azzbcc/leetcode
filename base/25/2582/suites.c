/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/26 14:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2582.c"

START_TEST(test_official_1) {
    int n = 4, time = 5;
    int target = 2, ans = passThePillow(n, time);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, time = 2;
    int target = 3, ans = passThePillow(n, time);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}