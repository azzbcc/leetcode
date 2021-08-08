/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/25 下午8:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1787.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 0, 3, 0 }, k = 1;
    int target = 3, ans = minChanges(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 3, 4, 5, 2, 1, 7, 3, 4, 7 }, k = 3;
    int target = 3, ans = minChanges(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 2, 4, 1, 2, 5, 1, 2, 6 }, k = 3;
    int target = 3, ans = minChanges(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}