/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/8 14:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2079.c"

START_TEST(test_official_1) {
    int plants[] = { 2, 2, 3, 3 }, capacity = 5;
    int target = 14, ans = wateringPlants(plants, LEN(plants), capacity);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int plants[] = { 1, 1, 1, 4, 2, 3 }, capacity = 4;
    int target = 30, ans = wateringPlants(plants, LEN(plants), capacity);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int plants[] = { 7, 7, 7, 7, 7, 7, 7 }, capacity = 8;
    int target = 49, ans = wateringPlants(plants, LEN(plants), capacity);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}