/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/2 19:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2511.c"

START_TEST(test_official_1) {
    int forts[] = { 1, 0, 0, -1, 0, 0, 0, 0, 1 };
    int target = 4, ans = captureForts(forts, LEN(forts));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int forts[] = { 0, 0, 1, -1 };
    int target = 0, ans = captureForts(forts, LEN(forts));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}