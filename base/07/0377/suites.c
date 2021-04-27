/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/24 下午8:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0377.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3 }, key = 4;
    int target = 7, ans = combinationSum4(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 9 }, key = 3;
    int target = 0, ans = combinationSum4(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200,
                  210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400,
                  410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
                  610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800,
                  810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111 };
    int key    = 999;
    int target = 1, ans = combinationSum4(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}