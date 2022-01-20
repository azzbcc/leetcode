/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/20 下午4:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2029.c"

START_TEST(test_official_1) {
    int stones[] = { 2, 1 };
    bool target = true, ans = stoneGameIX(stones, LEN(stones));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int stones[] = { 2 };
    bool target = false, ans = stoneGameIX(stones, LEN(stones));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int stones[] = { 5, 1, 2, 4, 3 };
    bool target = false, ans = stoneGameIX(stones, LEN(stones));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}