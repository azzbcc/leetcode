/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/26 下午12:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0773.c"

START_TEST(test_official_1) {
    int *board[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 0, 5 } };
    int target = 1, ans = slidingPuzzle(board, LEN(board), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *board[] = { (int[]) { 1, 2, 3 }, (int[]) { 5, 4, 0 } };
    int target = -1, ans = slidingPuzzle(board, LEN(board), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *board[] = { (int[]) { 4, 1, 2 }, (int[]) { 5, 0, 3 } };
    int target = 5, ans = slidingPuzzle(board, LEN(board), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int *board[] = { (int[]) { 3, 2, 4 }, (int[]) { 1, 5, 0 } };
    int target = 14, ans = slidingPuzzle(board, LEN(board), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}