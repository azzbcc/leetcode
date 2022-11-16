/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/16 下午1:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0775.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 0, 2 };
    ck_assert_int_eq(true, isIdealPermutation(nums, LEN(nums)));
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 0 };
    ck_assert_int_eq(false, isIdealPermutation(nums, LEN(nums)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}