/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/25 15:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "3016.c"

START_TEST(test_official_1) {
    char *word = "abcde";
    int target = 5, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *word = "xyzxyzxyzxyz";
    int target = 12, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *word = "aabbccddeeffgghhiiiiii";
    int target = 24, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}