/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午3:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "0401.c"

int comp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}

START_TEST(test_official) {
    int len, input = 1;
    char *target[] = { "1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32" };
    char **ans     = readBinaryWatch(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len, input = 2;
    char *target[] = { "0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33",
                       "0:34", "0:36", "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01",
                       "2:02", "2:04", "2:08", "2:16", "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16",
                       "4:32", "5:00", "6:00", "8:01", "8:02", "8:04", "8:08", "8:16", "8:32", "9:00", "10:00" };
    char **ans     = readBinaryWatch(input, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}