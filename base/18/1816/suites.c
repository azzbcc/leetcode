/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/6 上午10:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1816.c"

START_TEST(test_official_1) {
    int k        = 4;
    char s[]     = "Hello how are you Contestant";
    char *target = "Hello how are you", *ans = truncateSentence(s, k);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int k        = 4;
    char s[]     = "What is the solution to this problem";
    char *target = "What is the solution", *ans = truncateSentence(s, k);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int k        = 5;
    char s[]     = "chopper is not a tanuki";
    char *target = "chopper is not a tanuki", *ans = truncateSentence(s, k);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}