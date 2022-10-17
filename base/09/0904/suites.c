/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/17 上午11:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0904.c"

START_TEST(test_official_1) {
    int fruits[] = { 1, 2, 1 };
    int target = 3, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int fruits[] = { 0, 1, 2, 2 };
    int target = 3, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int fruits[] = { 1, 2, 3, 2, 2 };
    int target = 4, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int fruits[] = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    int target = 5, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int fruits[] = { 1, 0, 1, 4, 1, 4, 1, 2, 3 };
    int target = 5, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int fruits[] = { 0 };
    int target = 1, ans = totalFruit(fruits, LEN(fruits));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}