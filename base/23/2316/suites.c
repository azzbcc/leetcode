/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/21 14:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2316.c"

START_TEST(test_official_1) {
    int n = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 2 } };
    long long target = 0, ans = countPairs(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 7, *edges[] = { (int[]) { 0, 2 }, (int[]) { 0, 5 }, (int[]) { 2, 4 }, (int[]) { 1, 6 }, (int[]) { 5, 4 } };
    long long target = 14, ans = countPairs(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}