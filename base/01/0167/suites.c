/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/31 15:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0167.c"

START_TEST(test_official_1) {
    int numbers[] = { 2, 7, 11, 15 }, k = 9;
    int target[] = { 1, 2 };
    int len, *ans = twoSum(numbers, LEN(numbers), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int numbers[] = { 2, 3, 4 }, k = 6;
    int target[] = { 1, 3 };
    int len, *ans = twoSum(numbers, LEN(numbers), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int numbers[] = { -1, 0 }, k = -1;
    int target[] = { 1, 2 };
    int len, *ans = twoSum(numbers, LEN(numbers), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}