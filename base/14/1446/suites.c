/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/1 上午10:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1446.c"

START_TEST(test_official_1) {
    char *s    = "leetcode";
    int target = 2, ans = maxPower(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "abbcccddddeeeeedcba";
    int target = 5, ans = maxPower(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "triplepillooooow";
    int target = 5, ans = maxPower(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "hooraaaaaaaaaaay";
    int target = 11, ans = maxPower(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *s    = "tourist";
    int target = 1, ans = maxPower(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}
