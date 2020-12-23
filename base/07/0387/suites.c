/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/23 上午11:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0387.c"

START_TEST(test_official_1) {
    char *s = "leetcode";
    int target = 0, ans = firstUniqChar(s);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "loveleetcode";
    int target = 2, ans = firstUniqChar(s);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s = "aa";
    int target = -1, ans = firstUniqChar(s);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}