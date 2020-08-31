/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/22 下午4:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0679.c"

START_TEST(test_official_1) {
    int arr[]   = { 4, 1, 8, 7 };
    bool target = true, ans = judgePoint24(arr, sizeof(arr) / sizeof(arr[0]));

    fail_if(target != ans);
}

START_TEST(test_official_2) {
    int arr[]   = { 1, 2, 1, 2 };
    bool target = false, ans = judgePoint24(arr, sizeof(arr) / sizeof(arr[0]));

    fail_if(target != ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}