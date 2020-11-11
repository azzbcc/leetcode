/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/11 下午3:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0514.c"

START_TEST(test_official) {
    char *ring = "godding", *key = "gd";

    int target = 4, ans = findRotateSteps(ring, key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    char *ring = "badabcddddddd", *key = "abc";

    int target = 8, ans = findRotateSteps(ring, key);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    char *ring = "edcba", *key = "abcde";

    int target = 10, ans = findRotateSteps(ring, key);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}