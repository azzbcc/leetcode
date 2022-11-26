/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/27 上午12:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1752.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 4, 5, 1, 2 };
    ck_assert_int_eq(true, check(nums, LEN(nums)));
}

START_TEST(test_official_2) {
    int nums[] = { 2, 1, 3, 4 };
    ck_assert_int_eq(false, check(nums, LEN(nums)));
}

START_TEST(test_official_3) {
    int nums[] = { 1, 2, 3 };
    ck_assert_int_eq(true, check(nums, LEN(nums)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}