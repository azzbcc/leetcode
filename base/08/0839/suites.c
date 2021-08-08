/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/31 下午2:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0839.c"

START_TEST(test_official_1) {
    char *strs[] = { "tars", "rats", "arts", "star" };
    int target = 2, ans = numSimilarGroups(strs, LEN(strs));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *strs[] = { "omv", "ovm" };
    int target = 1, ans = numSimilarGroups(strs, LEN(strs));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}