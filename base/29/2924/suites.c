/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/13 17:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2924.c"

START_TEST(test_official_1) {
    int n = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 } };
    int target = 0, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 4, *edges[] = { (int[]) { 0, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 2 } };
    int target = -1, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int n = 4, *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 0 } };
    int target = -1, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
    int n = 2, *edges[] = {};
    int target = -1, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_02) {
    int n = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 0, 2 } };
    int target = 0, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_03) {
    int n = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 2, 1 }, (int[]) { 0, 2 } };
    int target = 0, ans = findChampion(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_03);
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}