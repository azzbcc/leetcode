/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/2 11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2368.c"

START_TEST(test_official_1) {
    int n = 7, restricted[] = { 4, 5 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 3, 1 },
                     (int[]) { 4, 0 }, (int[]) { 0, 5 }, (int[]) { 5, 6 } };
    int target = 4, ans = reachableNodes(n, edges, LEN(edges), NULL, restricted, LEN(restricted));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 7, restricted[] = { 4, 2, 1 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 0, 5 },
                     (int[]) { 0, 4 }, (int[]) { 3, 2 }, (int[]) { 6, 5 } };
    int target = 3, ans = reachableNodes(n, edges, LEN(edges), NULL, restricted, LEN(restricted));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}