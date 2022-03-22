/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/22 下午1:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2038.c"

START_TEST(test_official_1) {
    char *colors = "AAABABB";
    bool target = true, ans = winnerOfGame(colors);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *colors = "AA";
    bool target = false, ans = winnerOfGame(colors);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *colors = "ABBBBBBBAAA";
    bool target = false, ans = winnerOfGame(colors);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}