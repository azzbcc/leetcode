/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/2 下午9:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0743.c"

START_TEST(test_official_1) {
    int n = 4, k = 2;
    int *grid[] = { (int[]) { 2, 1, 1 }, (int[]) { 2, 3, 1 }, (int[]) { 3, 4, 1 } };
    int target = 2, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 2, k = 1;
    int *grid[] = { (int[]) { 1, 2, 1 } };
    int target = 1, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 2, k = 2;
    int *grid[] = { (int[]) { 1, 2, 1 } };
    int target = -1, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int n = 3, k = 1;
    int *grid[] = { (int[]) { 1, 2, 1 }, (int[]) { 2, 3, 2 }, (int[]) { 1, 3, 4 } };
    int target = 3, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int n = 3, k = 1;
    int *grid[] = { (int[]) { 1, 2, 1 }, (int[]) { 2, 3, 7 }, (int[]) { 1, 3, 4 }, (int[]) { 2, 1, 2 } };
    int target = 4, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int n = 5, k = 5;
    int *grid[] = { (int[]) { 3, 5, 78 }, (int[]) { 2, 1, 1 },  (int[]) { 1, 3, 0 },  (int[]) { 4, 3, 59 },
                    (int[]) { 5, 3, 85 }, (int[]) { 5, 2, 22 }, (int[]) { 2, 4, 23 }, (int[]) { 1, 4, 43 },
                    (int[]) { 4, 5, 75 }, (int[]) { 5, 1, 15 }, (int[]) { 1, 5, 91 }, (int[]) { 4, 1, 16 },
                    (int[]) { 3, 2, 98 }, (int[]) { 3, 4, 22 }, (int[]) { 5, 4, 31 }, (int[]) { 1, 2, 0 },
                    (int[]) { 2, 5, 4 },  (int[]) { 4, 2, 51 }, (int[]) { 3, 1, 36 }, (int[]) { 2, 3, 59 } };
    int target = 31, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_4) {
    int n = 5, k = 1;
    int *grid[] = { (int[]) { 2, 4, 10 }, (int[]) { 5, 2, 38 }, (int[]) { 3, 4, 33 }, (int[]) { 4, 2, 76 },
                    (int[]) { 3, 2, 64 }, (int[]) { 1, 5, 54 }, (int[]) { 1, 4, 98 }, (int[]) { 2, 3, 61 },
                    (int[]) { 2, 1, 0 },  (int[]) { 3, 5, 77 }, (int[]) { 5, 1, 34 }, (int[]) { 3, 1, 79 },
                    (int[]) { 5, 3, 2 },  (int[]) { 1, 2, 59 }, (int[]) { 4, 3, 46 }, (int[]) { 5, 4, 44 },
                    (int[]) { 2, 5, 89 }, (int[]) { 4, 5, 21 }, (int[]) { 1, 3, 86 }, (int[]) { 4, 1, 95 } };
    int target = 69, ans = networkDelayTime(grid, LEN(grid), NULL, n, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}