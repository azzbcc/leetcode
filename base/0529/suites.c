/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>

#include "0529.c"

START_TEST(test_official_1) {
    int ans_len, column_len = 5;
    int click[] = { 3, 0 }, *returnColumnSizes = NULL;
    char *arr[]    = { "EEEEE", "EEMEE", "EEEEE", "EEEEE" };
    char *target[] = { "B1E1B", "B1M1B", "B111B", "BBBBB" };

    char **ans = updateBoard(arr, sizeof(arr) / sizeof(arr[0]), &column_len, click, sizeof(click) / sizeof(click[0]),
                             &ans_len, &returnColumnSizes);

    ck_assert_int_eq(ans_len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < ans_len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(char) * returnColumnSizes[i]);
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int ans_len, column_len = 5;
    int click[] = { 1, 2 }, *returnColumnSizes = NULL;
    char *arr[]    = { "B1E1B", "B1M1B", "B111B", "BBBBB" };
    char *target[] = { "B1E1B", "B1X1B", "B111B", "BBBBB" };

    char **ans = updateBoard(arr, sizeof(arr) / sizeof(arr[0]), &column_len, click, sizeof(click) / sizeof(click[0]),
                             &ans_len, &returnColumnSizes);

    ck_assert_int_eq(ans_len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < ans_len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(char) * returnColumnSizes[i]);
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int ans_len, column_len = 8;
    int click[] = { 0, 0 }, *returnColumnSizes = NULL;
    char *arr[]    = { "EEEEEEEE", "EEEEEEEM", "EEMEEEEE", "MEEEEEEE", "EEEEEEEE", "EEEEEEEE", "EEEEEEEE", "EEMMEEEE" };
    char *target[] = { "BBBBBB1E", "B111BB1M", "12M1BB11", "M211BBBB", "11BBBBBB", "BBBBBBBB", "B1221BBB", "B1MM1BBB" };

    char **ans = updateBoard(arr, sizeof(arr) / sizeof(arr[0]), &column_len, click, sizeof(click) / sizeof(click[0]),
                             &ans_len, &returnColumnSizes);

    ck_assert_int_eq(ans_len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < ans_len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        ck_assert_mem_eq(ans[i], target[i], sizeof(char) * returnColumnSizes[i]);
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}