/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/21 14:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2671.c"

#define null -1
static void all_one_check(char *commands[], int args[], bool target[], size_t size) {
    FrequencyTracker *tracker = frequencyTrackerCreate();
    ck_assert_ptr_nonnull(tracker);

    for (int i = 0; i < size; ++i) {
        if (!strcmp(commands[i], "add")) {
            frequencyTrackerAdd(tracker, args[i]);
        } else if (!strcmp(commands[i], "deleteOne")) {
            frequencyTrackerDeleteOne(tracker, args[i]);
        } else if (!strcmp(commands[i], "hasFrequency")) {
            bool ans = frequencyTrackerHasFrequency(tracker, args[i]);
            ck_assert_int_eq(ans, target[i]);
        } else {
            fprintf(stderr, "error command: %s\n", commands[i]);
        }
    }

    frequencyTrackerFree(tracker);
}

START_TEST(test_official_1) {
    char *commands[] = { "add", "add", "hasFrequency" };
    int args[]       = { 3, 3, 2 };
    bool target[]    = { null, null, true };

    all_one_check(commands, args, target, LEN(commands));
}

START_TEST(test_official_2) {
    char *commands[] = { "add", "deleteOne", "hasFrequency" };
    int args[]       = { 1, 1, 1 };
    bool target[]    = { null, null, false };

    all_one_check(commands, args, target, LEN(commands));
}

START_TEST(test_official_3) {
    char *commands[] = { "hasFrequency", "add", "hasFrequency" };
    int args[]       = { 2, 3, 1 };
    bool target[]    = { false, null, true };

    all_one_check(commands, args, target, LEN(commands));
}

START_TEST(test_failed_01) {
    char *commands[] = { "deleteOne", "deleteOne", "add", "hasFrequency", "hasFrequency", "hasFrequency" };
    int args[]       = { 2, 1, 1, 1, 1, 1 };
    bool target[]    = { null, null, null, true, true, true };

    all_one_check(commands, args, target, LEN(commands));
}

START_TEST(test_failed_02) {
    char *commands[] = { "deleteOne",    "deleteOne",    "deleteOne", "deleteOne",    "hasFrequency", "add",
                         "deleteOne",    "hasFrequency", "deleteOne", "deleteOne",    "deleteOne",    "hasFrequency",
                         "add",          "hasFrequency", "deleteOne", "hasFrequency", "hasFrequency", "add",
                         "hasFrequency", "add",          "deleteOne", "hasFrequency", "add",          "hasFrequency",
                         "hasFrequency", "add" };
    int args[]       = { 9, 8, 1, 4, 1, 10, 5, 1, 10, 9, 10, 1, 4, 1, 4, 1, 1, 10, 1, 2, 1, 2, 7, 1, 1, 6 };
    bool target[]    = { null, null, null,  null,  false, null, null, true, null,  null, null, false, null,
                         true, null, false, false, null,  true, null, null, false, null, true, true,  null };

    all_one_check(commands, args, target, LEN(commands));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}