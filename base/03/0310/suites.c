/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/6 下午12:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0310.c"

START_TEST(test_official_1) {
    int n = 4, *edges[] = { (int[]) { 1, 0 }, (int[]) { 1, 2 }, (int[]) { 1, 3 } };
    int target[] = { 1 };
    int len, *ans = findMinHeightTrees(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 6, *edges[] = { (int[]) { 3, 0 }, (int[]) { 3, 1 }, (int[]) { 3, 2 }, (int[]) { 3, 4 }, (int[]) { 5, 4 } };
    int target[] = { 3, 4 };
    int len, *ans = findMinHeightTrees(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_tle) {
    int n = 1, *edges[] = {};
    int target[] = { 0 };
    int len, *ans = findMinHeightTrees(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}