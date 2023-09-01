/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/1 09:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2240.c"

START_TEST(test_official_1) {
    int total = 20, cost1 = 10, cost2 = 5;
    long long target = 9, ans = waysToBuyPensPencils(total, cost1, cost2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int total = 5, cost1 = 10, cost2 = 10;
    long long target = 1, ans = waysToBuyPensPencils(total, cost1, cost2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}