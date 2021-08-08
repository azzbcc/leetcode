/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/16 上午11:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0290.c"

START_TEST(test_official_1) {
    char *pattern = "abba", str[] = "dog cat cat dog";

    bool target = true, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *pattern = "abba", str[] = "dog cat cat fish";

    bool target = false, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *pattern = "aaaa", str[] = "dog cat cat dog";

    bool target = false, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *pattern = "abba", str[] = "dog dog dog dog";

    bool target = false, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *pattern = "abba", str[] = "dog cat cat dog dog";

    bool target = false, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *pattern = "deadbeef", str[] = "d e a d b e e f";

    bool target = true, ans = wordPattern(pattern, str);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}