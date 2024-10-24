/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/10/24 19:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "3175.c"

START_TEST(test_official_1) {
    int skills[] = { 4, 2, 6, 3, 9 }, k = 2;
    int target = 2, ans = findWinningPlayer(skills, LEN(skills), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int skills[] = { 2, 5, 4 }, k = 3;
    int target = 1, ans = findWinningPlayer(skills, LEN(skills), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
