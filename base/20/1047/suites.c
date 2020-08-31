/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/19 下午7:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>

#include "1047.c"

START_TEST(test_official) {
    char *target = "ca", *ans = removeDuplicates("abbaca");

    ck_assert(!strcmp(target, ans));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}