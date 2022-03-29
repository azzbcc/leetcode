/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/29 下午7:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2024.c"

START_TEST(test_official_1) {
    int k           = 2;
    char *answerKey = "TTFF";
    int target = 4, ans = maxConsecutiveAnswers(answerKey, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int k           = 1;
    char *answerKey = "TFFT";
    int target = 3, ans = maxConsecutiveAnswers(answerKey, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int k           = 1;
    char *answerKey = "TTFTTFTT";
    int target = 5, ans = maxConsecutiveAnswers(answerKey, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}