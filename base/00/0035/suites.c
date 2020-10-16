/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/16 下午1:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0035.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 3, 5, 6 }, key = 5;

    int target = 2, ans = searchInsert(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 3, 5, 6 }, key = 2;

    int target = 1, ans = searchInsert(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 3, 5, 6 }, key = 7;

    int target = 4, ans = searchInsert(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    int nums[] = { 1, 3, 5, 6 }, key = 0;

    int target = 0, ans = searchInsert(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
//    tcase_add_test(t, test_official_1);
//    tcase_add_test(t, test_official_2);
//    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}