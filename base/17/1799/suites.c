/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/22 下午5:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1799.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2 };
    int target = 1, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 3, 4, 6, 8 };
    int target = 11, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 2, 3, 4, 5, 6 };
    int target = 14, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int nums[] = { 171651, 546244, 880754, 412358 };
    int target = 60, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int nums[] = { 984916, 312350, 779975, 165893, 436389, 592384, 264617, 136726, 8893, 587955, 921403, 891842 };
    int target = 257, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int nums[] = { 109497, 983516, 698308, 409009, 310455, 528595, 524079,
                   18036,  341150, 641864, 913962, 421869, 943382, 295019 };
    int target = 527, ans = maxScore(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}