/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/1 下午9:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0473.c"

START_TEST(test_official_1) {
    int matchsticks[] = { 1, 1, 2, 2, 2 };
    bool target = true, ans = makesquare(matchsticks, LEN(matchsticks));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int matchsticks[] = { 3, 3, 3, 3, 4 };
    bool target = false, ans = makesquare(matchsticks, LEN(matchsticks));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int matchsticks[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
    bool target = true, ans = makesquare(matchsticks, LEN(matchsticks));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}