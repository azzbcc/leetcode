/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/1 12:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2462.c"

START_TEST(test_official_1) {
    int costs[] = { 17, 12, 10, 2, 7, 2, 11, 20, 8 }, k = 3, candidates = 4;
    long long target = 11, ans = totalCost(costs, LEN(costs), k, candidates);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int costs[] = { 1, 2, 4, 1 }, k = 3, candidates = 3;
    long long target = 4, ans = totalCost(costs, LEN(costs), k, candidates);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}