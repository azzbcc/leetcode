/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/1 下午1:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2351.c"

START_TEST(test_official_1) {
    char *s     = "abccbaacz";
    char target = 'c', ans = repeatedCharacter(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s     = "abcdd";
    char target = 'd', ans = repeatedCharacter(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}