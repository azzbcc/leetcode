/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/28 下午2:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "16_06.c"

START_TEST(test_official) {
    int num1[] = { 1, 3, 15, 11, 2 }, num2[] = { 23, 127, 235, 19, 8 };
    int target = 3, ans = smallestDifference(num1, LEN(num1), num2, LEN(num2));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int num1[] = { -2147483648, 1 }, num2[] = { 2147483647, 0 };
    int target = 1, ans = smallestDifference(num1, LEN(num1), num2, LEN(num2));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official);
}