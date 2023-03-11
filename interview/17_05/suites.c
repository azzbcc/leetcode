/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/11 下午1:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "17_05.c"

START_TEST(test_official_1) {
    int len;
    char *array[] = {
        "A", "1", "B", "C", "D", "2", "3", "4", "E", "5", "F", "G", "6", "7", "H", "I", "J", "K", "L", "M"
    };
    char *target[] = { "A", "1", "B", "C", "D", "2", "3", "4", "E", "5", "F", "G", "6", "7" };
    char **ans     = findLongestSubarray(array, LEN(array), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *array[]  = { "A", "A" };
    char *target[] = {};
    char **ans     = findLongestSubarray(array, LEN(array), &len);
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