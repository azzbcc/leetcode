/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/29 12:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2581.c"

START_TEST(test_official_1) {
    int k = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 4, 2 } };
    int *guesses[] = { (int[]) { 1, 3 }, (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 2, 4 } };
    int target = 3, ans = rootCount(edges, LEN(edges), NULL, guesses, LEN(guesses), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int k = 3, *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 } };
    int *guesses[] = { (int[]) { 1, 0 }, (int[]) { 3, 4 }, (int[]) { 2, 1 }, (int[]) { 3, 2 } };
    int target = 3, ans = rootCount(edges, LEN(edges), NULL, guesses, LEN(guesses), NULL, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}