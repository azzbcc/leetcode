/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/17 下午9:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1725.c"

START_TEST(test_official_1) {
    int *arr[] = { (int[]) { 5, 8 }, (int[]) { 3, 9 }, (int[]) { 5, 12 }, (int[]) { 16, 5 } };
    int target = 3, ans = countGoodRectangles(arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *arr[] = { (int[]) { 2, 3 }, (int[]) { 3, 7 }, (int[]) { 4, 3 }, (int[]) { 3, 7 } };
    int target = 3, ans = countGoodRectangles(arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}