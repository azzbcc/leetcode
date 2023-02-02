/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/2 下午2:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1129.c"

START_TEST(test_official_1) {
    int n = 3, *red_edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 } }, *blue_edges[] = {};
    int len, target[] = { 0, 1, -1 };
    int *ans = shortestAlternatingPaths(n, red_edges, LEN(red_edges), NULL, blue_edges, LEN(blue_edges), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 3, *red_edges[] = { (int[]) { 0, 1 } }, *blue_edges[] = { (int[]) { 2, 1 } };
    int len, target[] = { 0, 1, -1 };
    int *ans = shortestAlternatingPaths(n, red_edges, LEN(red_edges), NULL, blue_edges, LEN(blue_edges), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int n = 3, *red_edges[] = { (int[]) { 1, 0 } }, *blue_edges[] = { (int[]) { 2, 1 } };
    int len, target[] = { 0, -1, -1 };
    int *ans = shortestAlternatingPaths(n, red_edges, LEN(red_edges), NULL, blue_edges, LEN(blue_edges), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int n = 3, *red_edges[] = { (int[]) { 0, 1 } }, *blue_edges[] = { (int[]) { 1, 2 } };
    int len, target[] = { 0, 1, 2 };
    int *ans = shortestAlternatingPaths(n, red_edges, LEN(red_edges), NULL, blue_edges, LEN(blue_edges), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_5) {
    int n = 3, *red_edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 } }, *blue_edges[] = { (int[]) { 1, 0 } };
    int len, target[] = { 0, 1, 1 };
    int *ans = shortestAlternatingPaths(n, red_edges, LEN(red_edges), NULL, blue_edges, LEN(blue_edges), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    //    tcase_add_test(t, test_official_1);
    //    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}