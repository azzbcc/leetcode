/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/27 上午11:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "01_02.c"

START_TEST(test_official_1) {
    char *s1 = "abc", *s2 = "bca";
    bool target = true, ans = CheckPermutation(s1, s2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s1 = "abc", *s2 = "bad";
    bool target = false, ans = CheckPermutation(s1, s2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}