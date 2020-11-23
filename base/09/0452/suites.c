/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/23 上午11:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0452.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };

    int target = 2, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };

    int target = 4, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };

    int target = 2, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[][2] = { { 1, 2 } };
    int *grid[]  = { arr[0] };

    int target = 1, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[][2] = { { 2, 3 }, { 2, 3 } };
    int *grid[]  = { arr[0], arr[1] };

    int target = 1, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[][2] = { { 1, 2 }, { 4, 5 }, { 1, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };

    int target = 2, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[][2] = { { 9, 12 }, { 1, 10 }, { 4, 11 }, { 8, 12 }, { 3, 9 }, { 6, 9 }, { 6, 7 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6] };

    int target = 2, ans = findMinArrowShots(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}