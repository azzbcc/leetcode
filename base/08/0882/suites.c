/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/26 下午4:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0882.c"

START_TEST(test_official_1) {
    int *edges[] = { (int[]) { 0, 1, 10 }, (int[]) { 0, 2, 1 }, (int[]) { 1, 2, 2 } };
    int maxMoves = 6, n = 3;
    int target = 13, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *edges[] = { (int[]) { 0, 1, 4 }, (int[]) { 1, 2, 6 }, (int[]) { 0, 2, 8 }, (int[]) { 1, 3, 1 } };
    int maxMoves = 10, n = 4;
    int target = 23, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *edges[] = { (int[]) { 1, 2, 4 }, (int[]) { 1, 4, 5 }, (int[]) { 1, 3, 1 }, (int[]) { 2, 3, 4 },
                     (int[]) { 3, 4, 5 } };
    int maxMoves = 17, n = 5;
    int target = 1, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int *edges[] = { (int[]) { 0, 1, 4 }, (int[]) { 1, 2, 6 }, (int[]) { 0, 2, 8 }, (int[]) { 1, 3, 1 } };
    int maxMoves = 8, n = 4;
    int target = 19, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int *edges[] = { (int[]) { 3, 4, 8 }, (int[]) { 0, 1, 3 },  (int[]) { 1, 4, 0 }, (int[]) { 1, 2, 3 },
                     (int[]) { 0, 3, 2 }, (int[]) { 0, 4, 10 }, (int[]) { 1, 3, 3 }, (int[]) { 2, 4, 3 },
                     (int[]) { 2, 3, 3 }, (int[]) { 0, 2, 10 } };
    int maxMoves = 7, n = 5;
    int target = 43, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
#include "failed_2.c"
    int maxMoves = 25091255, n = 3000;
    int target = 50176030, ans = reachableNodes(edges, LEN(edges), NULL, maxMoves, n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}