/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/10 上午10:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0748.c"

START_TEST(test_official_1) {
    char *licensePlate = "1s3 PSt", *words[] = { "step", "steps", "stripe", "stepple" };
    char *target = "steps", *ans = shortestCompletingWord(licensePlate, words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *licensePlate = "1s3 PSt", *words[] = { "step", "steps", "stripe", "stepple" };
    char *target = "steps", *ans = shortestCompletingWord(licensePlate, words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *licensePlate = "1s3 PSt", *words[] = { "step", "steps", "stripe", "stepple" };
    char *target = "steps", *ans = shortestCompletingWord(licensePlate, words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char *licensePlate = "1s3 PSt", *words[] = { "step", "steps", "stripe", "stepple" };
    char *target = "steps", *ans = shortestCompletingWord(licensePlate, words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_5) {
    char *licensePlate = "1s3 PSt", *words[] = { "step", "steps", "stripe", "stepple" };
    char *target = "steps", *ans = shortestCompletingWord(licensePlate, words, LEN(words));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}