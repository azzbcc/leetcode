/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/17 下午4:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1726.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 3, 4, 6 };
    int target = 8, ans = tupleSameProduct(nums, LEN(nums));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 4, 5, 10 };
    int target = 16, ans = tupleSameProduct(nums, LEN(nums));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 2, 3, 4, 6, 8, 12 };
    int target = 40, ans = tupleSameProduct(nums, LEN(nums));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int nums[] = { 2, 3, 5, 7 };
    int target = 0, ans = tupleSameProduct(nums, LEN(nums));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 10, 5, 15, 8, 6, 12, 20, 4 };
    int target = 72, ans = tupleSameProduct(nums, LEN(nums));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}