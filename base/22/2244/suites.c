/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/14 19:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2244.c"

START_TEST(test_official_1) {
    int tasks[] = { 2, 2, 3, 3, 2, 4, 4, 4, 4, 4 };
    int target = 4, ans = minimumRounds(tasks, LEN(tasks));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int tasks[] = { 2, 3, 3 };
    int target = -1, ans = minimumRounds(tasks, LEN(tasks));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}