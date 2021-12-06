/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/6 下午4:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2094.c"

START_TEST(test_official_1) {
    int digits[] = { 2, 1, 3, 0 };
    int target[] = { 102, 120, 130, 132, 210, 230, 302, 310, 312, 320 };
    int len, *ans = findEvenNumbers(digits, LEN(digits), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int digits[] = { 2, 2, 8, 8, 2 };
    int target[] = { 222, 228, 282, 288, 822, 828, 882 };
    int len, *ans = findEvenNumbers(digits, LEN(digits), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int digits[] = { 3, 7, 5 };
    int target[] = {};
    int len, *ans = findEvenNumbers(digits, LEN(digits), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int digits[] = { 0, 2, 0, 0 };
    int target[] = { 200 };
    int len, *ans = findEvenNumbers(digits, LEN(digits), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_5) {
    int digits[] = { 0, 0, 0 };
    int target[] = {};
    int len, *ans = findEvenNumbers(digits, LEN(digits), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}