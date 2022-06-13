/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/13 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1051.c"

START_TEST(test_official_1) {
    int heights[] = { 1, 1, 4, 2, 1, 3 };
    int target = 3, ans = heightChecker(heights, LEN(heights));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int heights[] = { 5, 1, 2, 3, 4 };
    int target = 5, ans = heightChecker(heights, LEN(heights));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int heights[] = { 1, 2, 3, 4, 5 };
    int target = 0, ans = heightChecker(heights, LEN(heights));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}