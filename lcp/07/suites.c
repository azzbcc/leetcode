/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/1 上午11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_07.c"

START_TEST(test_official_1) {
    int n = 5, k = 3;
    int *relation[] = { (int[]) { 0, 2 }, (int[]) { 2, 1 }, (int[]) { 3, 4 }, (int[]) { 2, 3 },
                        (int[]) { 1, 4 }, (int[]) { 2, 0 }, (int[]) { 0, 4 } };
    int target = 3, ans = numWays(n, relation, LEN(relation), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, k = 2;
    int *relation[] = { (int[]) { 0, 2 }, (int[]) { 2, 1 } };
    int target = 0, ans = numWays(n, relation, LEN(relation), NULL, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}