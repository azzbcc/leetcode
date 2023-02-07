/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/7 下午4:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1604.c"

START_TEST(test_official_1) {
    int len;
    char *keyName[] = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
    char *keyTime[] = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };
    char *target[] = { "daniel" }, **ans = alertNames(keyName, LEN(keyName), keyTime, LEN(keyTime), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *keyName[] = { "alice", "alice", "alice", "bob", "bob", "bob", "bob" };
    char *keyTime[] = { "12:01", "12:00", "18:00", "21:00", "21:20", "21:30", "23:00" };
    char *target[] = { "bob" }, **ans = alertNames(keyName, LEN(keyName), keyTime, LEN(keyTime), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *keyName[] = { "john", "john", "john" };
    char *keyTime[] = { "23:58", "23:59", "00:01" };
    char *target[] = {}, **ans = alertNames(keyName, LEN(keyName), keyTime, LEN(keyTime), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_4) {
    int len;
    char *keyName[] = { "leslie", "leslie", "leslie", "clare", "clare", "clare", "clare" };
    char *keyTime[] = { "13:00", "13:20", "14:00", "18:00", "18:51", "19:30", "19:49" };
    char *target[] = { "clare", "leslie" }, **ans = alertNames(keyName, LEN(keyName), keyTime, LEN(keyTime), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}