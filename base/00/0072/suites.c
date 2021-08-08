/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/7 下午1:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0072.c"

START_TEST(test_official_1) {
    char *word1 = "horse", *word2 = "ros";
    int target = 3, ans = minDistance(word1, word2);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *word1 = "intention", *word2 = "execution";
    int target = 5, ans = minDistance(word1, word2);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}