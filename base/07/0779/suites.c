/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/20 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0779.c"

START_TEST(test_official_1) {
    int n = 1, k = 1;
    ck_assert_int_eq(0, kthGrammar(n, k));
}

START_TEST(test_official_2) {
    int n = 2, k = 1;
    ck_assert_int_eq(0, kthGrammar(n, k));
}

START_TEST(test_official_3) {
    int n = 2, k = 2;
    ck_assert_int_eq(1, kthGrammar(n, k));
}

START_TEST(test_failed) {
    int n = 4, k = 5;
    ck_assert_int_eq(1, kthGrammar(n, k));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}