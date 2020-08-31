/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/28 下午12:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0657.c"

START_TEST(test_official_1) {
    char *input = "UD";
    bool target = true, ans = judgeCircle(input);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input = "LL";
    bool target = false, ans = judgeCircle(input);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}