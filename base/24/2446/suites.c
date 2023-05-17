/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/17 14:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2446.c"

START_TEST(test_official_1) {
    char *event1[] = { "01:15", "02:00" }, *event2[] = { "02:00", "03:00" };
    ck_assert_int_eq(true, haveConflict(event1, LEN(event1), event2, LEN(event2)));
}

START_TEST(test_official_2) {
    char *event1[] = { "01:00", "02:00" }, *event2[] = { "01:20", "03:00" };
    ck_assert_int_eq(true, haveConflict(event1, LEN(event1), event2, LEN(event2)));
}

START_TEST(test_official_3) {
    char *event1[] = { "10:00", "11:00" }, *event2[] = { "14:00", "15:00" };
    ck_assert_int_eq(false, haveConflict(event1, LEN(event1), event2, LEN(event2)));
}

START_TEST(test_own) {
    char *event1[] = { "14:00", "15:00" }, *event2[] = { "10:00", "11:00" };
    ck_assert_int_eq(false, haveConflict(event1, LEN(event1), event2, LEN(event2)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}