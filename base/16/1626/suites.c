/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/22 下午12:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1626.c"

START_TEST(test_official_1) {
    int scores[] = { 1, 3, 5, 10, 15 }, ages[] = { 1, 2, 3, 4, 5 };
    int target = 34, ans = bestTeamScore(scores, LEN(scores), ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int scores[] = { 4, 5, 6, 5 }, ages[] = { 2, 1, 2, 1 };
    int target = 16, ans = bestTeamScore(scores, LEN(scores), ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int scores[] = { 1, 2, 3, 5 }, ages[] = { 8, 9, 10, 1 };
    int target = 6, ans = bestTeamScore(scores, LEN(scores), ages, LEN(ages));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}