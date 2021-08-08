/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/10 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0567.c"

START_TEST(test_official_1) {
    char *s1 = "ab", *s2 = "eidbaooo";
    bool target = true, ans = checkInclusion(s1, s2);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s1 = "ab", *s2 = "eidboaoo";
    bool target = false, ans = checkInclusion(s1, s2);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *s1 = "adc", *s2 = "dcda";
    bool target = true, ans = checkInclusion(s1, s2);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *s1 = "hello", *s2 = "ooolleoooleh";
    bool target = false, ans = checkInclusion(s1, s2);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}