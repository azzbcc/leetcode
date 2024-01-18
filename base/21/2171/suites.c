/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/18 08:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2171.c"

START_TEST(test_official_1) {
    int beans[]      = { 4, 1, 6, 5 };
    long long target = 4, ans = minimumRemoval(beans, LEN(beans));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int beans[]      = { 2, 10, 3, 2 };
    long long target = 7, ans = minimumRemoval(beans, LEN(beans));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}