/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/20 下午12:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1760.c"

START_TEST(test_official_1) {
    int nums[] = { 9 }, maxOperations = 2;
    int target = 3, ans = minimumSize(nums, LEN(nums), maxOperations);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 2, 4, 8, 2 }, maxOperations = 4;
    int target = 2, ans = minimumSize(nums, LEN(nums), maxOperations);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 7, 17 }, maxOperations = 2;
    int target = 7, ans = minimumSize(nums, LEN(nums), maxOperations);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}