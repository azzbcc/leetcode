/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/3 下午7:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0067.c"

START_TEST(test_official_1) {
    char *a = "11", *b = "1";

    char *target = "100", *ans = addBinary(a, b);
    ck_assert_str_eq(target, ans);

    free(ans);
}

START_TEST(test_official_2) {
    char *a = "1010", *b = "1011";

    char *target = "10101", *ans = addBinary(a, b);
    ck_assert_str_eq(target, ans);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}