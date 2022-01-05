/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/5 上午11:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1576.c"

static void str_check(char *source, char *ans) {
    ck_assert_int_eq(strlen(source), strlen(ans));
    for (int i = 0; ans[i]; ++i) {
        if (source[i] == '?') {
            ck_assert(islower(ans[i]));
            ck_assert(ans[i] != ans[i + 1] && (!i || ans[i] != ans[i - 1]));
        } else {
            ck_assert(source[i] == ans[i]);
        }
    }
}

START_TEST(test_official_1) {
    char s[]  = "?zs";
    char *ans = modifyString(s);
    str_check(s, ans);
}

START_TEST(test_official_2) {
    char s[]  = "ubv?w";
    char *ans = modifyString(s);
    str_check(s, ans);
}

START_TEST(test_official_3) {
    char s[]  = "j?qg??b";
    char *ans = modifyString(s);
    str_check(s, ans);
}

START_TEST(test_official_4) {
    char s[]  = "??yw?ipkj?";
    char *ans = modifyString(s);
    str_check(s, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}