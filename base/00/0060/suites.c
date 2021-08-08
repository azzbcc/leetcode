/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/5 下午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0060.c"

START_TEST(test_official_1) {
    char *target = "213", *ans = getPermutation(3, 3);

    ck_assert_str_eq(target, ans);
}
START_TEST(test_official_2) {
    char *target = "2314", *ans = getPermutation(4, 9);

    ck_assert_str_eq(target, ans);
}
void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}