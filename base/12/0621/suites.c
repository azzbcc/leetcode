/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/5 下午1:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0621.c"

START_TEST(test_official_1) {
    char task[] = { 'A', 'A', 'A', 'B', 'B', 'B' }, n = 2;
    int target = 8, ans = leastInterval(task, LEN(task), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char task[] = { 'A', 'A', 'A', 'B', 'B', 'B' }, n = 0;
    int target = 6, ans = leastInterval(task, LEN(task), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char task[] = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' }, n = 2;
    int target = 16, ans = leastInterval(task, LEN(task), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char task[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'V' }, n = 3;
    int target = 7, ans = leastInterval(task, LEN(task), n);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}