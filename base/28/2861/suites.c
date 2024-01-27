/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/27 17:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2861.c"

START_TEST(test_official_1) {
    int target = 2;
    int n = 3, k = 2, budget = 15;
    int *composition[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 10 } };
    int stock[] = { 0, 0, 0 }, cost[] = { 1, 2, 3 };
    int ans = maxNumberOfAlloys(n, k, budget, composition, LEN(composition), NULL, stock, LEN(stock), cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 5;
    int n = 3, k = 2, budget = 15;
    int *composition[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 10 } };
    int stock[] = { 0, 0, 100 }, cost[] = { 1, 2, 3 };
    int ans = maxNumberOfAlloys(n, k, budget, composition, LEN(composition), NULL, stock, LEN(stock), cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int target = 2;
    int n = 2, k = 3, budget = 10;
    int *composition[] = { (int[]) { 2, 1 }, (int[]) { 1, 2 }, (int[]) { 1, 1 } };
    int stock[] = { 1, 1 }, cost[] = { 5, 5 };
    int ans = maxNumberOfAlloys(n, k, budget, composition, LEN(composition), NULL, stock, LEN(stock), cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int target = 200000000;
    int n = 1, k = 1, budget = 100000000;
    int *composition[] = { (int[]) { 1 } };
    int stock[] = { 100000000 }, cost[] = { 1 };
    int ans = maxNumberOfAlloys(n, k, budget, composition, LEN(composition), NULL, stock, LEN(stock), cost, LEN(cost));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}