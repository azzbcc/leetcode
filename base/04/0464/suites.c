/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/22 下午8:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0464.c"

START_TEST(test_official_1) {
    int maxChoosableInteger = 10, desiredTotal = 11;
    bool target = false, ans = canIWin(maxChoosableInteger, desiredTotal);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int maxChoosableInteger = 10, desiredTotal = 0;
    bool target = true, ans = canIWin(maxChoosableInteger, desiredTotal);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int maxChoosableInteger = 10, desiredTotal = 1;
    bool target = true, ans = canIWin(maxChoosableInteger, desiredTotal);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int maxChoosableInteger = 10, desiredTotal = 40;
    bool target = false, ans = canIWin(maxChoosableInteger, desiredTotal);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int maxChoosableInteger = 6, desiredTotal = 16;
    bool target = true, ans = canIWin(maxChoosableInteger, desiredTotal);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}