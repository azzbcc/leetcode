/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/16 下午2:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1813.c"

START_TEST(test_official_1) {
    char *sentence1 = "My name is Haley", *sentence2 = "My Haley";
    ck_assert_int_eq(true, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_official_2) {
    char *sentence1 = "of", *sentence2 = "A lot of words";
    ck_assert_int_eq(false, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_official_3) {
    char *sentence1 = "Eating right now", *sentence2 = "Eating";
    ck_assert_int_eq(true, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_official_4) {
    char *sentence1 = "Luky", *sentence2 = "Lucccky";
    ck_assert_int_eq(false, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_failed_1) {
    char *sentence1 = "qbaVXO Msgr aEWD v ekcb", *sentence2 = "Msgr aEWD ekcb";
    ck_assert_int_eq(false, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_failed_2) {
    char *sentence1 = "B",
         *sentence2 = "ByI BMyQIqce b bARkkMaABi vlR RLHhqjNzCN oXvyK zRXR q ff B yHS OD KkvJA P JdWksnH";
    ck_assert_int_eq(false, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_failed_3) {
    char *sentence1 = "A A AAa", *sentence2 = "A AAa";
    ck_assert_int_eq(true, areSentencesSimilar(sentence1, sentence2));
}

START_TEST(test_failed_4) {
    char *sentence1 = "xD iP tqchblXgqvNVdi", *sentence2 = "FmtdCzv Gp YZf UYJ xD iP tqchblXgqvNVdi";
    ck_assert_int_eq(true, areSentencesSimilar(sentence1, sentence2));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}