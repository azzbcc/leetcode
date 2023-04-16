/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/16 上午11:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1157.c"

START_TEST(test_count) {
    int memory[] = { 6, 1, 3, 5, 7, 9, 11 };
    for (int i = 1; i < memory[0] * 2 + 1; ++i) {
        for (int j = i + 1; j < memory[0] * 2 + 1; ++j) {
            int real = 0;
            for (int k = i; k <= j; real += k++ % 2) {}
            ck_assert_int_eq(count(( array_t )memory, i, j), real);
        }
    }
}

START_TEST(test_official) {
    int arr[]                = { 1, 1, 2, 2, 1, 1 };
    MajorityChecker *checker = majorityCheckerCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(checker);

    struct query_t {
        int left, right, threshold, target;
    } queries[] = { { 0, 5, 4, 1 }, { 0, 3, 3, -1 }, { 2, 3, 2, 2 } };
    for (int i = 0; i < LEN(queries); ++i) {
        ck_assert_int_eq(majorityCheckerQuery(checker, queries[i].left, queries[i].right, queries[i].threshold),
                         queries[i].target);
    }
    majorityCheckerFree(checker);
}

START_TEST(test_tle) {
#include "tle.c"
    MajorityChecker *checker = majorityCheckerCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(checker);
    for (int i = 0; i < 10000; ++i) {
        ck_assert_int_eq(majorityCheckerQuery(checker, 0, 19990, 9999), -1);
    }
    majorityCheckerFree(checker);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_count);
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official);
}