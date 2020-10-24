/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/24 下午10:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1024.c"

START_TEST(test_official_1) {
    int T        = 10;
    int arr[][2] = { { 0, 2 }, { 4, 6 }, { 8, 10 }, { 1, 9 }, { 1, 5 }, { 5, 9 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5] };

    int target = 3, ans = videoStitching(grid, LEN(grid), NULL, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int T        = 5;
    int arr[][2] = { { 0, 1 }, { 1, 2 } };
    int *grid[]  = { arr[0], arr[1] };

    int target = -1, ans = videoStitching(grid, LEN(grid), NULL, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int T        = 9;
    int arr[][2] = { { 0, 1 }, { 6, 8 }, { 0, 2 }, { 5, 6 }, { 0, 4 }, { 0, 3 }, { 6, 7 }, { 1, 3 },
                     { 4, 7 }, { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 4 }, { 4, 5 }, { 5, 7 }, { 6, 9 } };
    int *grid[]  = { arr[0], arr[1], arr[2],  arr[3],  arr[4],  arr[5],  arr[6],  arr[7],
                    arr[8], arr[9], arr[10], arr[11], arr[12], arr[13], arr[14], arr[15] };

    int target = 3, ans = videoStitching(grid, LEN(grid), NULL, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    int T        = 5;
    int arr[][2] = { { 0, 4 }, { 2, 8 } };
    int *grid[]  = { arr[0], arr[1] };

    int target = 2, ans = videoStitching(grid, LEN(grid), NULL, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int T        = 5;
    int arr[][2] = { { 5, 7 }, { 1, 8 }, { 0, 0 }, { 2, 3 }, { 4, 5 }, { 0, 6 }, { 5, 10 }, { 7, 10 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7] };

    int target = 1, ans = videoStitching(grid, LEN(grid), NULL, T);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}