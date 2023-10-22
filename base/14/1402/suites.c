/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/22 11:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1402.c"

START_TEST(test_official_1) {
    int satisfaction[] = { -1, -8, 0, 5, -9 };
    int target = 14, ans = maxSatisfaction(satisfaction, LEN(satisfaction));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int satisfaction[] = { 4, 3, 2 };
    int target = 20, ans = maxSatisfaction(satisfaction, LEN(satisfaction));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int satisfaction[] = { -1, -4, -5 };
    int target = 0, ans = maxSatisfaction(satisfaction, LEN(satisfaction));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}