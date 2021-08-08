/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午3:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1536.c"

START_TEST(test_official_1) {
    int arr[][3] = { { 0, 0, 1 }, { 1, 1, 0 }, { 1, 0, 0 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };

    int target = 3, ans = minSwaps(grid, LEN(grid), NULL);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[][4] = { { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };

    int target = -1, ans = minSwaps(grid, LEN(grid), NULL);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[][3] = { { 1, 0, 0 }, { 1, 1, 0 }, { 1, 1, 1 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };

    int target = 0, ans = minSwaps(grid, LEN(grid), NULL);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
