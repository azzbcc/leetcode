/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/15 14:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1177.c"

START_TEST(test_official) {
    char *s = "abcda";
    int len, *query[] = { (int[]) { 3, 3, 0 }, (int[]) { 1, 2, 0 }, (int[]) { 0, 3, 1 }, (int[]) { 0, 3, 2 },
                          (int[]) { 0, 4, 1 } };
    bool target[] = { true, false, false, true, true }, *ans = canMakePaliQueries(s, query, LEN(query), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}