/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/21 下午12:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0925.c"

START_TEST(test_official_1) {
    char *name = "alex", *typed = "aaleexxx";

    bool target = true, ans = isLongPressedName(name, typed);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *name = "saeed", *typed = "ssaaedd";

    bool target = false, ans = isLongPressedName(name, typed);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *name = "leelee", *typed = "lleeelee";

    bool target = true, ans = isLongPressedName(name, typed);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    char *name = "laiden", *typed = "laiden";

    bool target = true, ans = isLongPressedName(name, typed);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}