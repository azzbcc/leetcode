/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/27 16:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2867.c"

START_TEST(test_official_1) {
    int n = 5, *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 4 }, (int[]) { 2, 5 } };
    long long target = 4, ans = countPaths(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 6, *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 4 }, (int[]) { 3, 5 }, (int[]) { 3, 6 } };
    long long target = 6, ans = countPaths(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n = 37659;
#include "failed.c"
    long long target = 8979643, ans = countPaths(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}