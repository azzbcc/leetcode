/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/29 下午8:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1652.c"

START_TEST(test_official_1) {
    int code[] = { 5, 7, 1, 4 }, k = 3;
    int target[] = { 12, 10, 16, 13 };
    int len, *ans = decrypt(code, LEN(code), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int code[] = { 1, 2, 3, 4 }, k = 0;
    int target[] = { 0, 0, 0, 0 };
    int len, *ans = decrypt(code, LEN(code), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int code[] = { 2, 4, 9, 3 }, k = -2;
    int target[] = { 12, 5, 6, 13 };
    int len, *ans = decrypt(code, LEN(code), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int code[] = { 10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6 }, k = -4;
    int target[] = { 22, 26, 22, 28, 29, 22, 19, 22, 18, 21, 28, 19 };
    int len, *ans = decrypt(code, LEN(code), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}