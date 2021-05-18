/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/18 上午10:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1442.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 3, 1, 6, 7 };
    int target = 4, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 1, 1, 1, 1 };
    int target = 10, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 2, 3 };
    int target = 0, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 1, 3, 5, 7, 9 };
    int target = 3, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]  = { 7, 11, 12, 9, 5, 2, 7, 17, 22 };
    int target = 8, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 508, 803, 735, 442, 869, 567, 338, 863, 525, 37,  552, 984, 496, 862, 686, 591, 225, 985,
                  824, 642, 442, 700, 774, 708, 450, 100, 422, 82,  500, 920, 620, 260, 872, 254, 918, 34,
                  948, 895, 203, 55,  252, 518, 762, 96,  666, 711, 93,  903, 986, 777, 211, 306, 481, 551,
                  966, 674, 356, 729, 957, 355, 734, 546, 252, 466, 302, 497, 223, 166, 121, 323, 314, 66,
                  376, 576, 824, 978, 234, 563, 729, 651, 82,  761, 683, 724, 127, 483, 412 };
    int target = 178, ans = countTriplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}