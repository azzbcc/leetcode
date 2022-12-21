/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/21 上午10:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1753.c"

START_TEST(test_official_1) {
    int a = 2, b = 4, c = 6;
    int target = 6, ans = maximumScore(a, b, c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int a = 4, b = 4, c = 6;
    int target = 7, ans = maximumScore(a, b, c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int a = 1, b = 8, c = 8;
    int target = 8, ans = maximumScore(a, b, c);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}