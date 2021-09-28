/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/28 下午3:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1996.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 5, 5 }, (int[]) { 6, 3 }, (int[]) { 3, 6 } };
    int target = 0, ans = numberOfWeakCharacters(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 2, 2 }, (int[]) { 3, 3 } };
    int target = 1, ans = numberOfWeakCharacters(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *grid[] = { (int[]) { 1, 5 }, (int[]) { 10, 4 }, (int[]) { 4, 3 } };
    int target = 1, ans = numberOfWeakCharacters(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}