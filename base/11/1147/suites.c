/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午7:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1147.c"

START_TEST(test_official_1) {
    char *text = "ghiabcdefhelloadamhelloabcdefghi";

    int target = 7, ans = longestDecomposition(text);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *text = "merchant";

    int target = 1, ans = longestDecomposition(text);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *text = "antaprezatepzapreanta";

    int target = 11, ans = longestDecomposition(text);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    char *text = "aaa";

    int target = 3, ans = longestDecomposition(text);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    char *text = "elvtoelvto";

    int target = 2, ans = longestDecomposition(text);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}