/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/6 20:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1419.c"

START_TEST(test_official_1) {
    char *croakOfFrogs = "croakcroak";
    int target = 1, ans = minNumberOfFrogs(croakOfFrogs);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *croakOfFrogs = "crcoakroak";
    int target = 2, ans = minNumberOfFrogs(croakOfFrogs);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *croakOfFrogs = "croakcrook";
    int target = -1, ans = minNumberOfFrogs(croakOfFrogs);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
