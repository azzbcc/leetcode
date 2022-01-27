/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/27 下午2:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2047.c"

START_TEST(test_official_1) {
    char *sentence = "cat and  dog";
    int target = 3, ans = countValidWords(sentence);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *sentence = "!this  1-s b8d!";
    int target = 0, ans = countValidWords(sentence);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *sentence = "alice and  bob are playing stone-gamxe10";
    int target = 5, ans = countValidWords(sentence);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.";
    int target = 6, ans = countValidWords(sentence);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *sentence = "a a-b a-b-c -a a- -";
    int target = 2, ans = countValidWords(sentence);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}