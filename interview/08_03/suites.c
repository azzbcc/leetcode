/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/31 下午12:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "08_03.c"

START_TEST(test_official_1) {
    int nums[] = { 0, 2, 3, 4, 5 };
    int target = 0, ans = findMagicIndex(nums, sizeof(nums) / sizeof(nums[0]));
    ck_assert_msg(ans == target, "error, except %d but got %d on findMagicIndex().", target, ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 1, 1 };
    int target = 1, ans = findMagicIndex(nums, sizeof(nums) / sizeof(nums[0]));
    ck_assert_msg(ans == target, "error, except %d but got %d on findMagicIndex().", target, ans);
}

START_TEST(test_failed) {
    int nums[] = { 0, 0, 2 };
    int target = 0, ans = findMagicIndex(nums, sizeof(nums) / sizeof(nums[0]));
    ck_assert_msg(ans == target, "error, except %d but got %d on findMagicIndex().", target, ans);
}


void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}