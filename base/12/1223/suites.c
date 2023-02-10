/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/10 下午2:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1223.c"

START_TEST(test_official_1) {
    int n = 2, rollMax[] = { 1, 1, 2, 2, 2, 3 };
    int target = 34, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 2, rollMax[] = { 1, 1, 1, 1, 1, 1 };
    int target = 30, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 3, rollMax[] = { 1, 1, 1, 2, 2, 3 };
    int target = 181, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n = 4, rollMax[] = { 2, 1, 1, 3, 3, 2 };
    int target = 1082, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow_1) {
    int n = 30, rollMax[] = { 2, 3, 1, 2, 1, 2 };
    int target = 753152086, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow_2) {
    int n = 100, rollMax[] = { 7, 5, 15, 5, 1, 7 };
    int target = 797209093, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow_3) {
    int n = 100, rollMax[] = { 8, 11, 13, 9, 10, 7 };
    int target = 778061023, ans = dieSimulator(n, rollMax, LEN(rollMax));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow_3);
    tcase_add_test(t, test_overflow_2);
    tcase_add_test(t, test_overflow_1);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}