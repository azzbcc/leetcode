/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/29 13:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0924.c"

START_TEST(test_official_1) {
    int *graph[] = { (int[]) { 1, 1, 0 }, (int[]) { 1, 1, 0 }, (int[]) { 0, 0, 1 } }, initial[] = { 0, 1 };
    int target = 0, ans = minMalwareSpread(graph, LEN(graph), NULL, initial, LEN(initial));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *graph[] = { (int[]) { 1, 0, 0 }, (int[]) { 0, 1, 0 }, (int[]) { 0, 0, 1 } }, initial[] = { 0, 2 };
    int target = 0, ans = minMalwareSpread(graph, LEN(graph), NULL, initial, LEN(initial));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *graph[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 1 } }, initial[] = { 1, 2 };
    int target = 1, ans = minMalwareSpread(graph, LEN(graph), NULL, initial, LEN(initial));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *graph[] = { (int[]) { 1, 1, 0 }, (int[]) { 1, 1, 0 }, (int[]) { 0, 0, 1 } }, initial[] = { 0, 1, 2 };
    int target = 2, ans = minMalwareSpread(graph, LEN(graph), NULL, initial, LEN(initial));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}