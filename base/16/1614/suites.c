/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/7 上午10:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1614.c"

START_TEST(test_official_1) {
    char *s    = "(1+(2*3)+((8)/4))+1";
    int target = 3, ans = maxDepth(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "(1)+((2))+(((3)))";
    int target = 3, ans = maxDepth(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "1+(2*3)/(2-1)";
    int target = 1, ans = maxDepth(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "1";
    int target = 0, ans = maxDepth(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}