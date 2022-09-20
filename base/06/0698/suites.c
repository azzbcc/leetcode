/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/20 下午2:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0698.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 3, 2, 3, 5, 2, 1 }, k = 4;
    bool target = true, ans = canPartitionKSubsets(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3, 4 }, k = 3;
    bool target = false, ans = canPartitionKSubsets(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}