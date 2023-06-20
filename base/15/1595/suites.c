/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/20 16:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1595.c"

START_TEST(test_official_1) {
    int col = 2, *cost[] = { (int[]) { 15, 96 }, (int[]) { 36, 2 } };
    int target = 17, ans = connectTwoGroups(cost, LEN(cost), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 3, *cost[] = { (int[]) { 1, 3, 5 }, (int[]) { 4, 1, 1 }, (int[]) { 1, 5, 3 } };
    int target = 4, ans = connectTwoGroups(cost, LEN(cost), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col = 3, *cost[] = { (int[]) { 2, 5, 1 }, (int[]) { 3, 4, 7 }, (int[]) { 8, 1, 2 }, (int[]) { 6, 2, 4 },
                             (int[]) { 3, 8, 8 } };
    int target = 10, ans = connectTwoGroups(cost, LEN(cost), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}