/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/26 下午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1713.c"

START_TEST(test_official_1) {
    int keys[] = { 5, 1, 3 }, arr[] = { 9, 4, 2, 3, 4 };
    int target = 2, ans = minOperations(keys, LEN(keys), arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int keys[] = { 6, 4, 8, 1, 3, 2 }, arr[] = { 4, 7, 6, 2, 3, 8, 6, 1 };
    int target = 3, ans = minOperations(keys, LEN(keys), arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}