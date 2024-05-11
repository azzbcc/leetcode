/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/11 12:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2391.c"

START_TEST(test_official_1) {
    int travel[]    = { 2, 4, 3 };
    char *garbage[] = { "G", "P", "GP", "GG" };
    int target = 21, ans = garbageCollection(garbage, LEN(garbage), travel, LEN(travel));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int travel[]    = { 3, 10 };
    char *garbage[] = { "MMM", "PGM", "GP" };
    int target = 37, ans = garbageCollection(garbage, LEN(garbage), travel, LEN(travel));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}