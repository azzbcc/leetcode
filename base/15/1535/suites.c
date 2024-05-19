/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/19 10:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1535.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 1, 3, 5, 4, 6, 7 }, k = 2;
    int target = 5, ans = getWinner(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 2, 1 }, k = 10;
    int target = 3, ans = getWinner(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 9, 8, 2, 3, 7, 6, 4, 5 }, k = 7;
    int target = 9, ans = getWinner(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[] = { 1, 11, 22, 33, 44, 55, 66, 77, 88, 99 }, k = 1000000000;
    int target = 99, ans = getWinner(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 857, 215, 866, 707, 227, 206, 372, 817, 844, 363, 591, 487, 727, 912, 879, 365, 657,
                   143, 264, 459, 429, 212, 551, 610, 312, 514, 533, 123, 250, 863, 305, 543, 359, 625,
                   291, 490, 908, 309, 18,  183, 690, 197, 859, 462, 260, 922, 175, 435, 850, 684, 653,
                   527, 76,  855, 765, 997, 199, 898, 65,  371, 223, 999, 771, 154, 451, 258 },
        k      = 473;
    int target = 999, ans = getWinner(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}