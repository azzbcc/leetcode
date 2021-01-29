/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/29 上午11:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1631.c"

START_TEST(test_official_1) {
    int len = 3, *grid[] = { (int[]) { 1, 2, 2 }, (int[]) { 3, 8, 2 }, (int[]) { 5, 3, 5 } };
    int target = 2, ans = minimumEffortPath(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int len = 3, *grid[] = { (int[]) { 1, 2, 3 }, (int[]) { 3, 8, 4 }, (int[]) { 5, 3, 5 } };
    int target = 1, ans = minimumEffortPath(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int len = 5, *grid[] = { (int[]) { 1, 2, 1, 1, 1 }, (int[]) { 1, 2, 1, 2, 1 }, (int[]) { 1, 2, 1, 2, 1 },
                             (int[]) { 1, 2, 1, 2, 1 }, (int[]) { 1, 1, 1, 2, 1 } };
    int target = 0, ans = minimumEffortPath(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int len = 1, *grid[] = { (int[]) { 3 } };
    int target = 0, ans = minimumEffortPath(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int len = 8, *grid[] = { (int[]) { 4, 3, 4, 10, 5, 5, 9, 2 }, (int[]) { 10, 8, 2, 10, 9, 7, 5, 6 },
                             (int[]) { 5, 8, 10, 10, 10, 7, 4, 2 }, (int[]) { 5, 1, 3, 1, 1, 3, 1, 9 },
                             (int[]) { 6, 4, 10, 6, 10, 9, 4, 6 } };
    int target = 5, ans = minimumEffortPath(grid, LEN(grid), &len);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}