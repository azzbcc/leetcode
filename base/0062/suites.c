/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/24 下午4:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0062.c"

START_TEST(test_official_1) {
    int target = 3, ans = uniquePaths(3, 2);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 28, ans = uniquePaths(7, 3);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_limit) {
    int target = 1916797311, ans = uniquePaths(51, 9);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}