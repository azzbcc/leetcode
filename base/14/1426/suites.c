/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/1 上午8:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1426.c"

START_TEST(test_official_1) {
    char **paths[] = { (char *[]) { "London", "New York" }, (char *[]) { "New York", "Lima" },
                       (char *[]) { "Lima", "Sao Paulo" } };
    char *target = "Sao Paulo", *ans = destCity(paths, LEN(paths), NULL);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char **paths[] = { (char *[]) { "B", "C" }, (char *[]) { "D", "B" }, (char *[]) { "C", "A" } };
    char *target = "A", *ans = destCity(paths, LEN(paths), NULL);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char **paths[] = { (char *[]) { "A", "Z" } };
    char *target = "Z", *ans = destCity(paths, LEN(paths), NULL);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}