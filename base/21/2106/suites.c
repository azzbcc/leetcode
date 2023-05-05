/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/4 15:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2106.c"

START_TEST(test_official_1) {
    int startPos = 5, k = 4;
    int *fruits[] = { (int[]) { 2, 8 }, (int[]) { 6, 3 }, (int[]) { 8, 6 } };
    int target = 9, ans = maxTotalFruits(fruits, LEN(fruits), NULL, startPos, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int startPos = 5, k = 4;
    int *fruits[] = { (int[]) { 0, 9 }, (int[]) { 4, 1 }, (int[]) { 5, 7 },
                      (int[]) { 6, 2 }, (int[]) { 7, 4 }, (int[]) { 10, 9 } };
    int target = 14, ans = maxTotalFruits(fruits, LEN(fruits), NULL, startPos, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int startPos = 3, k = 2;
    int *fruits[] = { (int[]) { 0, 3 }, (int[]) { 6, 4 }, (int[]) { 8, 5 } };
    int target = 0, ans = maxTotalFruits(fruits, LEN(fruits), NULL, startPos, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}