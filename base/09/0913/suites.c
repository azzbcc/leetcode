/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/4 下午2:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0913.c"

START_TEST(test_official_1) {
    int col[]    = { 2, 1, 3, 3, 2, 3 };
    int *graph[] = { (int[]) { 2, 5 },    (int[]) { 3 },    (int[]) { 0, 4, 5 },
                     (int[]) { 1, 4, 5 }, (int[]) { 2, 3 }, (int[]) { 0, 2, 3 } };
    int target = 0, ans = catMouseGame(graph, LEN(graph), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col[]    = { 2, 1, 1, 2 };
    int *graph[] = { (int[]) { 1, 3 }, (int[]) { 0 }, (int[]) { 3 }, (int[]) { 0, 2 } };
    int target = 1, ans = catMouseGame(graph, LEN(graph), col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}