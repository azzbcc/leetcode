/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/25 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1370.c"

START_TEST(test_official_1) {
    char s[] = "aaaabbbbcccc", *target = "abccbaabccba";

    char *ans = sortString(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char s[] = "rat", *target = "art";

    char *ans = sortString(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char s[] = "leetcode", *target = "cdelotee";

    char *ans = sortString(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char s[] = "ggggggg", *target = "ggggggg";

    char *ans = sortString(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_5) {
    char s[] = "spo", *target = "ops";

    char *ans = sortString(s);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}