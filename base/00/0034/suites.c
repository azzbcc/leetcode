/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/14 下午2:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0034.c"

START_TEST(test_official_1) {
    int nums[] = { 5, 7, 7, 8, 8, 10 }, key = 8;

    int len, target[] = { 3, 4 }, *ans = searchRange(nums, LEN(nums), key, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 5, 7, 7, 8, 8, 10 }, key = 6;

    int len, target[] = { -1, -1 }, *ans = searchRange(nums, LEN(nums), key, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    int nums[] = {2, 2}, key = 2;

    int len, target[] = { 0, 1 }, *ans = searchRange(nums, LEN(nums), key, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}