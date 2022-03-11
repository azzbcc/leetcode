/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/11 下午5:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2049.c"

START_TEST(test_official_1) {
    int parents[] = { -1, 2, 0, 2, 0 };
    int target = 3, ans = countHighestScoreNodes(parents, LEN(parents));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int parents[] = { -1, 2, 0 };
    int target = 2, ans = countHighestScoreNodes(parents, LEN(parents));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int parents[] = { -1, 0 };
    int target = 2, ans = countHighestScoreNodes(parents, LEN(parents));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
#include "failed.c"
    int target = 2, ans = countHighestScoreNodes(parents, LEN(parents));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}