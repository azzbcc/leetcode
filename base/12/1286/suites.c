/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午7:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1286.c"

START_TEST(test_official) {
    CombinationIterator *iterator = combinationIteratorCreate("abc", 2);

    ck_assert_str_eq("ab", combinationIteratorNext(iterator));
    ck_assert_int_eq(true, combinationIteratorHasNext(iterator));
    ck_assert_str_eq("ac", combinationIteratorNext(iterator));
    ck_assert_int_eq(true, combinationIteratorHasNext(iterator));
    ck_assert_str_eq("bc", combinationIteratorNext(iterator));
    ck_assert_int_eq(false, combinationIteratorHasNext(iterator));

    combinationIteratorFree(iterator);
}

void tcase_complete(TCase *t) {
//    for (int i= 0; i < 100; ++i) {
//        for (int k = i, n = 2, m; n; k -= C(m, n--)) {
//            m = k ? Cm(n, k) : n - 1;
//            printf("%d, ", m);
//        }
//        printf("\n");
//    }
    tcase_add_test(t, test_official);
}