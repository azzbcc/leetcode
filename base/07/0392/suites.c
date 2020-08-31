/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/27 下午4:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0392.c"

START_TEST(test_official_1) {
    char *s = "abc", *t = "ahbgdc";
    bool target = true, ans = isSubsequence(s, t);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray('%s', '%s').", target, ans, s, t);
}

START_TEST(test_official_2) {
    char *s = "axc", *t = "ahbgdc";
    bool target = false, ans = isSubsequence(s, t);

    ck_assert_msg(ans == target, "error, except %d but got %d on splitArray('%s', '%s').", target, ans, s, t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}