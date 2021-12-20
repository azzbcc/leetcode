/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/20 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0475.c"

START_TEST(test_official_1) {
    int houses[] = { 1, 2, 3 }, heaters[] = { 2 };
    int target = 1, ans = findRadius(houses, LEN(houses), heaters, LEN(heaters));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int houses[] = { 1, 2, 3, 4 }, heaters[] = { 1, 4 };
    int target = 1, ans = findRadius(houses, LEN(houses), heaters, LEN(heaters));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int houses[] = { 1, 5 }, heaters[] = { 2 };
    int target = 3, ans = findRadius(houses, LEN(houses), heaters, LEN(heaters));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}