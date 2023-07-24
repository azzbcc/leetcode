/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/24 14:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0771.c"

START_TEST(test_official_1) {
    char *jewels = "aA", *stones = "aAAbbbb";
    int target = 3, ans = numJewelsInStones(jewels, stones);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *jewels = "z", *stones = "ZZ";
    int target = 0, ans = numJewelsInStones(jewels, stones);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}