/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/8 下午1:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0189.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }, k = 3;
    int target[] = { 5, 6, 7, 1, 2, 3, 4 };

    rotate(arr, LEN(arr), k);

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_official_2) {
    int arr[] = { -1, -100, 3, 99 }, k = 2;
    int target[] = { 3, 99, -1, -100 };

    rotate(arr, LEN(arr), k);

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_own_1) {
    int arr[]              = { 1, 2, 3, 4, 5, 6, 7 };
    int target[][LEN(arr)] = { { 1, 2, 3, 4, 5, 6, 7 }, { 7, 1, 2, 3, 4, 5, 6 }, { 6, 7, 1, 2, 3, 4, 5 },
                               { 5, 6, 7, 1, 2, 3, 4 }, { 4, 5, 6, 7, 1, 2, 3 }, { 3, 4, 5, 6, 7, 1, 2 },
                               { 2, 3, 4, 5, 6, 7, 1 }, { 1, 2, 3, 4, 5, 6, 7 } };

    for (int i = 0, tmp[LEN(arr)]; i < LEN(target); ++i) {
        memcpy(tmp, arr, sizeof(arr));
        rotate(tmp, LEN(tmp), i);
        ck_assert_mem_eq(tmp, target[i], sizeof(target[i]));
    }
}

START_TEST(test_own_2) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 }, k = 3;
    int target[] = { 6, 7, 8, 1, 2, 3, 4, 5 };

    rotate(arr, LEN(arr), k);
    ck_assert_mem_eq(arr, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}