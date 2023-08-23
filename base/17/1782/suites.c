/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/23 19:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1782.c"

START_TEST(test_official_1) {
    int n = 4, queries[] = { 2, 3 };
    int *edges[] = { (int[]) { 1, 2 }, (int[]) { 2, 4 }, (int[]) { 1, 3 }, (int[]) { 2, 3 }, (int[]) { 2, 1 } };
    int target[] = { 6, 5 }, len, *ans = countPairs(n, edges, LEN(edges), NULL, queries, LEN(queries), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 5, queries[] = { 1, 2, 3, 4, 5 };
    int *edges[] = { (int[]) { 1, 5 }, (int[]) { 1, 5 }, (int[]) { 3, 4 }, (int[]) { 2, 5 },
                     (int[]) { 1, 3 }, (int[]) { 5, 1 }, (int[]) { 2, 3 }, (int[]) { 2, 5 } };
    int target[] = { 10, 10, 9, 8, 6 }, len, *ans = countPairs(n, edges, LEN(edges), NULL, queries, LEN(queries), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}