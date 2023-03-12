/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/12 下午5:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1617.c"

START_TEST(test_official_1) {
    int n = 4, *edges[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 2, 4 } };
    int target[] = { 3, 4, 0 };
    int len, *ans = countSubgraphsForEachDiameter(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 2, *edges[] = { (int[]) { 1, 2 } };
    int target[] = { 1 };
    int len, *ans = countSubgraphsForEachDiameter(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int n = 3, *edges[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 } };
    int target[] = { 2, 1 };
    int len, *ans = countSubgraphsForEachDiameter(n, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}