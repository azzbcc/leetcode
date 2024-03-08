/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/8 14:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2834.c"

START_TEST(test_official_1) {
    int n = 2, t = 3;
    int target = 4, ans = minimumPossibleSum(n, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, t = 3;
    int target = 8, ans = minimumPossibleSum(n, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 1, t = 1;
    int target = 1, ans = minimumPossibleSum(n, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int n = 1000000000, t = 1000000000;
    int target = 750000042, ans = minimumPossibleSum(n, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}