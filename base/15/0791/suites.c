/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/23 下午5:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0791.c"

START_TEST(test_official) {
    char S[] = "cba", T[] = "abcd";
    char *target = "dcba", *ans = customSortString(S, T);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}