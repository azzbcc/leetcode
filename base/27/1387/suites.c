/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/26 下午2:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1387.c"

START_TEST(test_official_1) {
    int target = 13, ans = getKth(12, 15, 2);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 1, ans = getKth(1, 1, 1);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int target = 7, ans = getKth(7, 11, 4);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    int target = 13, ans = getKth(10, 20, 5);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_5) {
    int target = 570, ans = getKth(1, 1000, 777);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int target = 646, ans = getKth(55, 922, 646);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}