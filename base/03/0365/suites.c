/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/28 13:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0365.c"

START_TEST(test_official_1) {
    int jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4;
    bool target = true, ans = canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5;
    bool target = false, ans = canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3;
    bool target = true, ans = canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}