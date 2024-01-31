/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/31 15:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcr_115.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 3 }, col[] = { 2, 2 };
    int *sequences[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 } };
    bool target = false, ans = sequenceReconstruction(nums, LEN(nums), sequences, LEN(sequences), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3 }, col[] = { 2 };
    int *sequences[] = { (int[]) { 1, 2 } };
    bool target = false, ans = sequenceReconstruction(nums, LEN(nums), sequences, LEN(sequences), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 2, 3 }, col[] = { 2, 2, 2 };
    int *sequences[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 3 } };
    bool target = true, ans = sequenceReconstruction(nums, LEN(nums), sequences, LEN(sequences), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 1, 2, 3 }, col[] = { 2, 2, 2 };
    int *sequences[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 2 } };
    bool target = false, ans = sequenceReconstruction(nums, LEN(nums), sequences, LEN(sequences), col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}