/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/17 下午6:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1764.c"

START_TEST(test_official_1) {
    int col[]     = { 3, 3 };
    int *groups[] = { (int[]) { 1, -1, -1 }, (int[]) { 3, -2, 0 } };
    int nums[]    = { 1, -1, 0, 1, -1, -1, 3, -2, 0 };
    ck_assert_int_eq(true, canChoose(groups, LEN(groups), col, nums, LEN(nums)));
}

START_TEST(test_official_2) {
    int col[]     = { 2, 4 };
    int *groups[] = { (int[]) { 10, -2 }, (int[]) { 1, 2, 3, 4 } };
    int nums[]    = { 1, 2, 3, 4, 10, -2 };
    ck_assert_int_eq(false, canChoose(groups, LEN(groups), col, nums, LEN(nums)));
}

START_TEST(test_official_3) {
    int col[]     = { 3, 2 };
    int *groups[] = { (int[]) { 1, 2, 3 }, (int[]) { 3, 4 } };
    int nums[]    = { 7, 7, 1, 2, 3, 4, 7, 7 };
    ck_assert_int_eq(false, canChoose(groups, LEN(groups), col, nums, LEN(nums)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}