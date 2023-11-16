/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/11/16 14:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2760.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 2, 5, 4 }, threshold = 5;
    int target = 3, ans = longestAlternatingSubarray(nums, LEN(nums), threshold);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2 }, threshold = 2;
    int target = 1, ans = longestAlternatingSubarray(nums, LEN(nums), threshold);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 2, 3, 4, 5 }, threshold = 4;
    int target = 3, ans = longestAlternatingSubarray(nums, LEN(nums), threshold);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 4, 10, 3 }, threshold = 10;
    int target = 2, ans = longestAlternatingSubarray(nums, LEN(nums), threshold);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}