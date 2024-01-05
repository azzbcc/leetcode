/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/5 15:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1944.c"

START_TEST(test_official_1) {
    int len, heights[] = { 10, 6, 8, 5, 11, 9 };
    int target[] = { 3, 1, 2, 1, 1, 0 }, *ans = canSeePersonsCount(heights, LEN(heights), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int len, heights[] = { 5, 1, 2, 3, 10 };
    int target[] = { 4, 1, 1, 1, 0 }, *ans = canSeePersonsCount(heights, LEN(heights), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}