/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/29 上午10:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0335.c"

START_TEST(test_official_1) {
    int distance[] = { 2, 1, 1, 2 };
    bool target = true, ans = isSelfCrossing(distance, LEN(distance));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int distance[] = { 1, 2, 3, 4 };
    bool target = false, ans = isSelfCrossing(distance, LEN(distance));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int distance[] = { 1, 1, 1, 1 };
    bool target = true, ans = isSelfCrossing(distance, LEN(distance));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int distance[] = { 3, 3, 3, 2, 1, 1 };
    bool target = false, ans = isSelfCrossing(distance, LEN(distance));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}