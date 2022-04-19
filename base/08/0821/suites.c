/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/19 上午11:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0821.c"

START_TEST(test_official_1) {
    char *s = "loveleetcode", c = 'e';
    int target[] = { 3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0 };
    int len, *ans = shortestToChar(s, c, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    char *s = "aaab", c = 'b';
    int target[] = { 3, 2, 1, 0 };
    int len, *ans = shortestToChar(s, c, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_own) {
    char *s = "abcde", c = 'c';
    int target[] = { 2, 1, 0, 1, 2 };
    int len, *ans = shortestToChar(s, c, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}