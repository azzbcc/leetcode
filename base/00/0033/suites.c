/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/14 下午1:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0033.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 5, 6, 7, 0, 1, 2 }, key = 0;

    int target = 4, ans = search(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int nums[] = { 4, 5, 6, 7, 0, 1, 2 }, key = 3;

    int target = -1, ans = search(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int nums[] = { 4,5,6,7,8,1,2,3 }, key = 8;

    int target = 4, ans = search(nums, LEN(nums), key);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}