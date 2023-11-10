/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/11/10 14:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2300.c"

START_TEST(test_official_1) {
    int len;
    int spells[] = { 5, 1, 3 }, potions[] = { 1, 2, 3, 4, 5 }, success = 7;
    int target[] = { 4, 0, 3 }, *ans = successfulPairs(spells, LEN(spells), potions, LEN(potions), success, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    int spells[] = { 3, 1, 2 }, potions[] = { 8, 5, 8 }, success = 16;
    int target[] = { 2, 0, 2 }, *ans = successfulPairs(spells, LEN(spells), potions, LEN(potions), success, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}