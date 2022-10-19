/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/19 上午11:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1700.c"

START_TEST(test_official_1) {
    int students[] = { 1, 1, 0, 0 }, sandwiches[] = { 0, 1, 0, 1 };
    int target = 0, ans = countStudents(students, LEN(students), sandwiches, LEN(sandwiches));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int students[] = { 1, 1, 1, 0, 0, 1 }, sandwiches[] = { 1, 0, 0, 0, 1, 1 };
    int target = 3, ans = countStudents(students, LEN(students), sandwiches, LEN(sandwiches));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}