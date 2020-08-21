/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 下午1:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0842.c"

START_TEST(test_official_1) {
    char *input  = "123456579";
    int target[] = { 123, 456, 579 };
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    char *input  = "11235813";
    int target[] = { 1, 1, 2, 3, 5, 8, 13 };
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    char *input  = "112358130";
    int target[] = {};
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_4) {
    char *input  = "0123";
    int target[] = {};
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_5) {
    char *input  = "1101111";
    int target[] = { 11, 0, 11, 11 };
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    char *input  = "214748364921474836492";
    int target[] = {};
    int len, *ans = splitIntoFibonacci(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}