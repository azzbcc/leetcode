/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/31 下午1:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#define MAXN 10000

#include "0381.c"

void test_random(RandomizedCollection *collection, int n, double rate) {
    int c = 0;
    for (int i = 0; i < MAXN; ++i) {
        c += n == randomizedCollectionGetRandom(collection);
    }

    ck_assert_double_eq_tol(c * 1.0 / MAXN, rate, 0.01);
}

START_TEST(test_official) {
    RandomizedCollection *collection = randomizedCollectionCreate();

    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), false);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), true);

    test_random(collection, 1, 2.0 / 3);
    test_random(collection, 2, 1.0 / 3);

    ck_assert_int_eq(randomizedCollectionRemove(collection, 1), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 3), false);

    test_random(collection, 1, 0.5);
    test_random(collection, 2, 0.5);

    ck_assert_int_eq(randomizedCollectionRemove(collection, 1), true);

    randomizedCollectionFree(collection);
}

START_TEST(test_failed_1) {
    RandomizedCollection *collection = randomizedCollectionCreate();

    ck_assert_int_eq(randomizedCollectionInsert(collection, 0), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 0), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 1), true);

    test_random(collection, 2, 1.0);

    randomizedCollectionFree(collection);
}

START_TEST(test_failed_2) {
    RandomizedCollection *collection = randomizedCollectionCreate();

    ck_assert_int_eq(randomizedCollectionInsert(collection, 4), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 3), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 4), false);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 4), false);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 4), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 3), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 4), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 4), true);

    randomizedCollectionFree(collection);
}

START_TEST(test_failed_3) {
    RandomizedCollection *collection = randomizedCollectionCreate();

    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), false);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), true);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 1), false);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), false);
    ck_assert_int_eq(randomizedCollectionInsert(collection, 2), false);

    ck_assert_int_eq(randomizedCollectionRemove(collection, 1), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 2), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 2), true);
    ck_assert_int_eq(randomizedCollectionRemove(collection, 2), true);

    test_random(collection, 1, 1.0);

    randomizedCollectionFree(collection);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}