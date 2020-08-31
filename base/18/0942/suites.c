/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 下午12:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0942.c"

START_TEST(test_official_1) {
    char *input  = "IDID";
    int target[] = { 0, 4, 1, 3, 2 };
    int len, *ans = diStringMatch(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    char *input  = "III";
    int target[] = { 0, 1, 2, 3 };
    int len, *ans = diStringMatch(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    char *input  = "DDI";
    int target[] = { 3, 2, 0, 1 };
    int len, *ans = diStringMatch(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}