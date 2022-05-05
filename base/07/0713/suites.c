/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/5 上午11:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0713.c"

START_TEST(test_official_1) {
    int nums[] = { 10, 5, 2, 6 }, k = 100;
    int target = 8, ans = numSubarrayProductLessThanK(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3 }, k = 0;
    int target = 0, ans = numSubarrayProductLessThanK(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 1, 2, 3, 11, 1, 2, 3, 11, 1, 2, 3 }, k = 10;
    int target = 18, ans = numSubarrayProductLessThanK(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
