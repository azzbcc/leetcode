/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/26 14:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1146.c"

START_TEST(test_official) {
    SnapshotArray *array = snapshotArrayCreate(3);
    ck_assert_ptr_nonnull(array);

    snapshotArraySet(array, 0, 5);
    ck_assert_int_eq(0, snapshotArraySnap(array));
    snapshotArraySet(array, 0, 6);
    ck_assert_int_eq(5, snapshotArrayGet(array, 0, 0));

    snapshotArrayFree(array);
}

START_TEST(test_failed) {
    SnapshotArray *array = snapshotArrayCreate(1);
    ck_assert_ptr_nonnull(array);

    snapshotArraySet(array, 0, 15);
    ck_assert_int_eq(0, snapshotArraySnap(array));
    ck_assert_int_eq(1, snapshotArraySnap(array));
    ck_assert_int_eq(2, snapshotArraySnap(array));
    ck_assert_int_eq(15, snapshotArrayGet(array, 0, 2));
    ck_assert_int_eq(3, snapshotArraySnap(array));
    ck_assert_int_eq(4, snapshotArraySnap(array));
    ck_assert_int_eq(15, snapshotArrayGet(array, 0, 0));

    snapshotArrayFree(array);
}

START_TEST(test_overflow_01) {
    SnapshotArray *array = snapshotArrayCreate(100);
    ck_assert_ptr_nonnull(array);

#include "overflow_01.c"
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp("snap", commands[i])) {
            ck_assert_int_eq(target[i], snapshotArraySnap(array));
        } else if (!strcmp("set", commands[i])) {
            snapshotArraySet(array, args[i][0], args[i][1]);
        } else if (!strcmp("get", commands[i])) {
            ck_assert_int_eq(target[i], snapshotArrayGet(array, args[i][0], args[i][1]));
        } else {
            ck_assert_int_eq(0, 1);
        }
    }
    snapshotArrayFree(array);
}

START_TEST(test_overflow_02) {
    SnapshotArray *array = snapshotArrayCreate(10000);
    ck_assert_ptr_nonnull(array);

#include "overflow_02.c"
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp("snap", commands[i])) {
            ck_assert_int_eq(target[i], snapshotArraySnap(array));
        } else if (!strcmp("set", commands[i])) {
            snapshotArraySet(array, args[i][0], args[i][1]);
        } else if (!strcmp("get", commands[i])) {
            ck_assert_int_eq(target[i], snapshotArrayGet(array, args[i][0], args[i][1]));
        } else {
            ck_assert_int_eq(0, 1);
        }
    }
    snapshotArrayFree(array);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow_02);
    tcase_add_test(t, test_overflow_01);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}