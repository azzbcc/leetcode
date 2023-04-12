/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/13 上午12:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2404.c"

START_TEST(test_official_1) {
    int nums[] = { 0, 1, 2, 2, 4, 4, 1 };
    int target = 2, ans = mostFrequentEven(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 4, 4, 4, 9, 2, 4 };
    int target = 4, ans = mostFrequentEven(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 29, 47, 21, 41, 13, 37, 25, 7 };
    int target = -1, ans = mostFrequentEven(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int nums[] = { 8154, 9139, 8194, 3346, 5450, 9190, 133, 8239, 4606, 8671, 8412, 6290 };
    int target = 3346, ans = mostFrequentEven(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int nums[] = { 78110, 12914, 29949, 29375, 77720, 36307 };
    int target = 12914, ans = mostFrequentEven(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}