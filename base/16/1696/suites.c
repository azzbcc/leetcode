/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/5 15:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1696.c"

START_TEST(test_official_1) {
    int nums[] = { 1, -1, -2, 4, -7, 3 }, k = 2;
    int target = 7, ans = maxResult(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 10, -5, -2, 4, 0, 3 }, k = 3;
    int target = 17, ans = maxResult(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, -5, -20, 4, -1, 3, -6, -3 }, k = 2;
    int target = 0, ans = maxResult(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}