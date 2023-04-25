/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/25 上午8:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2418.c"

START_TEST(test_official_1) {
    char *names[] = { "Mary", "John", "Emma" };
    int len, heights[] = { 180, 165, 170 };
    char *target[] = { "Mary", "Emma", "John" };
    char **ans     = sortPeople(names, LEN(names), heights, LEN(heights), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    char *names[] = { "Alice", "Bob", "Bob" };
    int len, heights[] = { 155, 185, 150 };
    char *target[] = { "Bob", "Alice", "Bob" };
    char **ans     = sortPeople(names, LEN(names), heights, LEN(heights), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}