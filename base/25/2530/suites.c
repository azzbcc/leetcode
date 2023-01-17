/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/17 下午8:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2530.c"

START_TEST(test_official_1) {
    int nums[] = { 10, 10, 10, 10, 10 }, k = 5;
    long long target = 50, ans = maxKelements(nums, LEN(nums), k);
    ck_assert_uint_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 10, 3, 3, 3 }, k = 3;
    long long target = 17, ans = maxKelements(nums, LEN(nums), k);
    ck_assert_uint_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}