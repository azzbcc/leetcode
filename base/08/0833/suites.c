/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/16 13:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0833.c"

START_TEST(test_official_1) {
    int indices[] = { 0, 2 };
    char *s = "abcd", *sources[] = { "a", "cd" }, *targets[] = { "eee", "ffff" };
    char *target = "eeebffff";
    char *ans    = findReplaceString(s, indices, LEN(indices), sources, LEN(sources), targets, LEN(targets));

    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    int indices[] = { 0, 2 };
    char *s = "abcd", *sources[] = { "ab", "ec" }, *targets[] = { "eee", "ffff" };
    char *target = "eeecd";
    char *ans    = findReplaceString(s, indices, LEN(indices), sources, LEN(sources), targets, LEN(targets));

    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}