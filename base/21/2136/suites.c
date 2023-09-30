/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/30 07:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2136.c"

START_TEST(test_official_1) {
    int plantTime[] = { 1, 4, 3 }, growTime[] = { 2, 3, 1 };
    int target = 9, ans = earliestFullBloom(plantTime, LEN(plantTime), growTime, LEN(growTime));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int plantTime[] = { 1, 2, 3, 2 }, growTime[] = { 2, 1, 2, 1 };
    int target = 9, ans = earliestFullBloom(plantTime, LEN(plantTime), growTime, LEN(growTime));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int plantTime[] = { 1 }, growTime[] = { 1 };
    int target = 2, ans = earliestFullBloom(plantTime, LEN(plantTime), growTime, LEN(growTime));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}