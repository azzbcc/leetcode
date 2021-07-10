/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/10 下午4:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0981.c"

typedef struct {
    char *key;
    int timestamp;
    char *value;
} argv_t;

static void test(char *commands[], argv_t argv[], char *target[], int size) {
    TimeMap *timeMap = timeMapCreate();
    for (int i = 0; i < size; ++i) {
        if (!strcmp(commands[i], "get")) {
            char *ans = timeMapGet(timeMap, argv[i].key, argv[i].timestamp);
            ck_assert_str_eq(ans, target[i]);
        } else if (!strcmp(commands[i], "set")) {
            timeMapSet(timeMap, argv[i].key, argv[i].value, argv[i].timestamp);
        }
    }
    timeMapFree(timeMap);
}

START_TEST(test_official_1) {
    char *commands[] = { "set", "get", "get", "set", "get", "get" };
    argv_t argv[]    = {
        { "foo", 1, "bar" }, { "foo", 1 }, { "foo", 3 }, { "foo", 4, "bar2" }, { "foo", 4 }, { "foo", 5 }
    };
    char *target[] = { NULL, "bar", "bar", NULL, "bar2", "bar2" };
    test(commands, argv, target, LEN(commands));
}

START_TEST(test_official_2) {
    char *commands[] = { "set", "set", "get", "get", "get", "get", "get" };
    argv_t argv[]    = {
        { "love", 10, "high" }, { "love", 20, "low" }, { "love", 5 },  { "love", 10 },
        { "love", 15 },         { "love", 20 },        { "love", 25 },

    };
    char *target[] = { NULL, NULL, "", "high", "high", "low", "low" };
    test(commands, argv, target, LEN(commands));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}