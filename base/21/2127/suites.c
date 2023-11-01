/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/11/1 15:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2127.c"

START_TEST(test_official_1) {
    int favorite[] = { 2, 2, 1, 2 };
    int target = 3, ans = maximumInvitations(favorite, LEN(favorite));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int favorite[] = { 1, 2, 0 };
    int target = 3, ans = maximumInvitations(favorite, LEN(favorite));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int favorite[] = { 3, 0, 1, 4, 1 };
    int target = 4, ans = maximumInvitations(favorite, LEN(favorite));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_1) {
    int favorite[] = { 3, 0, 1, 2, 3, 4 };
    int target = 4, ans = maximumInvitations(favorite, LEN(favorite));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_2) {
    int favorite[] = { 3, 0, 1, 2, 3, 4, 5, 6, 7 };
    int target = 4, ans = maximumInvitations(favorite, LEN(favorite));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}