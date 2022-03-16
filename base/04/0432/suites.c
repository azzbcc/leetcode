/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/16 上午11:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0432.c"

static void all_one_check(char *commands[], char *args[], size_t size) {
    AllOne *allOne = allOneCreate();
    ck_assert_ptr_nonnull(allOne);

    for (int i = 0; i < size; ++i) {
        if (!strcmp(commands[i], "inc")) {
            allOneInc(allOne, args[i]);
        } else if (!strcmp(commands[i], "dec")) {
            allOneDec(allOne, args[i]);
        } else if (!strcmp(commands[i], "getMaxKey")) {
            char *ans = allOneGetMaxKey(allOne);
            ck_assert_str_eq(ans, args[i]);
        } else if (!strcmp(commands[i], "getMinKey")) {
            char *ans = allOneGetMinKey(allOne);
            ck_assert_str_eq(ans, args[i]);
        } else {
            fprintf(stderr, "error command: %s\n", commands[i]);
        }
    }

    allOneFree(allOne);
}

START_TEST(test_official) {
    char *commands[] = { "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey" };
    char *args[]     = { "hello", "hello", "hello", "hello", "leet", "hello", "leet" };

    all_one_check(commands, args, LEN(commands));
}

START_TEST(test_failed) {
    char *commands[] = { "inc", "inc", "inc",       "inc", "inc",       "inc",
                         "dec", "dec", "getMinKey", "dec", "getMaxKey", "getMinKey" };
    char *args[]     = { "a", "b", "b", "c", "c", "c", "b", "b", "a", "a", "c", "c" };

    all_one_check(commands, args, LEN(commands));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}