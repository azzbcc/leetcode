/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/7 15:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2575.c"

START_TEST(test_official_1) {
    char *word = "998244353";
    int len, m = 3;
    int target[] = { 1, 1, 0, 0, 0, 1, 1, 0, 0 }, *ans = divisibilityArray(word, m, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    char *word = "1010";
    int len, m = 10;
    int target[] = { 0, 1, 0, 1 }, *ans = divisibilityArray(word, m, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_limit) {
    char *word = "999999999999";
    int len, m = 1000000000;
    int target[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, *ans = divisibilityArray(word, m, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}