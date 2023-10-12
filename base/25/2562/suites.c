/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/12 12:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2562.c"

START_TEST(test_official_1) {
    int nums[]       = { 7, 52, 2, 4 };
    long long target = 596, ans = findTheArrayConcVal(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[]       = { 5, 14, 13, 8, 12 };
    long long target = 673, ans = findTheArrayConcVal(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}