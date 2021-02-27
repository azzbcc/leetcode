/**
 * 0058.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/27 下午6:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0058.c"

START_TEST(test_official_1) {
    char *s    = "Hello World";
    int target = 5, ans = lengthOfLastWord(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = " ";
    int target = 0, ans = lengthOfLastWord(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *s    = "a";
    int target = 1, ans = lengthOfLastWord(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}