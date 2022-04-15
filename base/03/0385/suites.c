/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/15 上午8:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include "nested_integer.h"

#include "0385.c"
#include "nested_integer.c"

START_TEST(test_official_1) {
    char *s           = "324";
    nested_int_t *ans = deserialize(s);
    char *target      = nested_dump(ans);

    ck_assert_str_eq(s, target);
    nested_free(ans);
}

START_TEST(test_official_2) {
    char *s           = "[123,[456,[789]]]";
    nested_int_t *ans = deserialize(s);
    char *target      = nested_dump(ans);

    ck_assert_str_eq(s, target);
    nested_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}