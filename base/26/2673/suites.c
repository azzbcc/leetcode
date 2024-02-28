/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/28 09:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2673.c"

START_TEST(test_official_1) {
    int n = 7, cost[] = { 1, 5, 2, 2, 3, 3, 1 };
    int target = 6, ans = minIncrements(n, cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, cost[] = { 5, 3, 3 };
    int target = 0, ans = minIncrements(n, cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n = 15, cost[] = { 764, 1460, 2664, 764, 2725, 4556, 5305, 8829, 5064, 5929, 7660, 6321, 4830, 7055, 3761 };
    int target = 15735, ans = minIncrements(n, cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}