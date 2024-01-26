/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/26 14:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2846.c"

START_TEST(test_official_1) {
    int len, n = 7;
    int *edges[]   = { (int[]) { 0, 1, 1 }, (int[]) { 1, 2, 1 }, (int[]) { 2, 3, 1 },
                       (int[]) { 3, 4, 2 }, (int[]) { 4, 5, 2 }, (int[]) { 5, 6, 2 } };
    int *queries[] = { (int[]) { 0, 3 }, (int[]) { 3, 6 }, (int[]) { 2, 6 }, (int[]) { 0, 6 } };
    int target[]   = { 0, 0, 1, 3 };

    int *ans = minOperationsQueries(n, edges, LEN(edges), NULL, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 8;
    int *edges[]   = { (int[]) { 1, 2, 6 }, (int[]) { 1, 3, 4 }, (int[]) { 2, 4, 6 }, (int[]) { 2, 5, 3 },
                       (int[]) { 3, 6, 6 }, (int[]) { 3, 0, 8 }, (int[]) { 7, 0, 2 } };
    int *queries[] = { (int[]) { 4, 6 }, (int[]) { 0, 4 }, (int[]) { 6, 5 }, (int[]) { 7, 4 } };
    int target[]   = { 1, 2, 2, 3 };

    int *ans = minOperationsQueries(n, edges, LEN(edges), NULL, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}