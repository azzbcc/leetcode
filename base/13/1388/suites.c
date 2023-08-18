/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/18 14:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1388.c"

START_TEST(test_official_1) {
    int slices[] = { 1, 2, 3, 4, 5, 6 };
    int target = 10, ans = maxSizeSlices(slices, LEN(slices));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int slices[] = { 8, 9, 8, 6, 1, 1 };
    int target = 16, ans = maxSizeSlices(slices, LEN(slices));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}