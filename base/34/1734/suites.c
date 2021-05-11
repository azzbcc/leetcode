/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/11 上午10:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1734.c"

START_TEST(test_official_1) {
    int encoded[] = { 3, 1 };
    int target[]  = { 1, 2, 3 };
    int len, *ans = decode(encoded, LEN(encoded), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int encoded[] = { 6, 5, 4, 6 };
    int target[]  = { 2, 4, 1, 5, 3 };
    int len, *ans = decode(encoded, LEN(encoded), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}