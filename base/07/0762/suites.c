/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/5 上午7:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0762.c"

START_TEST(test_official_1) {
    int left = 6, right = 10;
    int target = 4, ans = countPrimeSetBits(left, right);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int left = 10, right = 15;
    int target = 5, ans = countPrimeSetBits(left, right);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}