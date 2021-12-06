/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/6 下午5:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "2096.c"

START_TEST(test_official_1) {
    int arr[] = { 5, 1, 2, 3, null, 6, 4 }, startValue = 3, destValue = 6;
    tree_t t = tree_create(arr);

    char *target = "UURL", *ans = getDirections(t, startValue, destValue);
    ck_assert_str_eq(ans, target);

    free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 1 }, startValue = 2, destValue = 1;
    tree_t t = tree_create(arr);

    char *target = "L", *ans = getDirections(t, startValue, destValue);
    ck_assert_str_eq(ans, target);

    free(ans);
    tree_free(t);
}

START_TEST(test_tle) {
#include "tle.c"
    int startValue = 29716, destValue = 54117;
    tree_t t = tree_create(arr);

    char *ans    = getDirections(t, startValue, destValue);
    ck_assert(0 == strcmp(ans, target));

    free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}