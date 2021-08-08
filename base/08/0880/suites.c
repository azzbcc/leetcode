/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/1 下午5:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0880.c"

START_TEST(test_official_1) {
    int K        = 10;
    char *S      = "leet2code3";
    char *target = "o", *ans = decodeAtIndex(S, K);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int K        = 5;
    char *S      = "ha22";
    char *target = "h", *ans = decodeAtIndex(S, K);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int K        = 1;
    char *S      = "a2345678999999999999999";
    char *target = "a", *ans = decodeAtIndex(S, K);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    int K        = 9;
    char *S      = "a2b3c4d5e6f7g8h9";
    char *target = "b", *ans = decodeAtIndex(S, K);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}