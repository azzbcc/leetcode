/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/19 上午11:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1971.c"

START_TEST(test_official_1) {
    int n = 3, source = 0, destination = 2;
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 2, 0 } };
    ck_assert_int_eq(true, validPath(n, edges, LEN(edges), NULL, source, destination));
}

START_TEST(test_official_2) {
    int n = 6, source = 0, destination = 5;
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 3, 5 }, (int[]) { 5, 4 }, (int[]) { 4, 3 } };
    ck_assert_int_eq(false, validPath(n, edges, LEN(edges), NULL, source, destination));
}

START_TEST(test_out_of_bounds) {
    int n = 1, source = 0, destination = 0;
    int *edges[] = {};
    ck_assert_int_eq(true, validPath(n, edges, LEN(edges), NULL, source, destination));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_out_of_bounds);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}