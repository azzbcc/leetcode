/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/28 下午2:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2016.c"

START_TEST(test_official_1) {
    int nums[] = { 7, 1, 5, 4 };
    int target = 4, ans = maximumDifference(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 9, 4, 3, 2 };
    int target = -1, ans = maximumDifference(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 5, 2, 10 };
    int target = 9, ans = maximumDifference(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 999, 997, 980, 976, 948, 940, 938, 928, 924, 917, 907, 907, 881, 878, 864, 862, 859, 857, 848, 840,
                   824, 824, 824, 805, 802, 798, 788, 777, 775, 766, 755, 748, 735, 732, 727, 705, 700, 697, 693, 679,
                   676, 644, 634, 624, 599, 596, 588, 583, 562, 558, 553, 539, 537, 536, 509, 491, 485, 483, 454, 449,
                   438, 425, 403, 368, 345, 327, 287, 285, 270, 263, 255, 248, 235, 234, 224, 221, 201, 189, 187, 183,
                   179, 168, 155, 153, 150, 144, 107, 102, 102, 87,  80,  57,  55,  49,  48,  45,  26,  26,  23,  15 };
    int target = -1, ans = maximumDifference(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}