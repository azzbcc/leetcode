/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/25 09:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2698.c"

START_TEST(test_official_1) {
    int n      = 10;
    int target = 182, ans = punishmentNumber(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 37;
    int target = 1478, ans = punishmentNumber(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}