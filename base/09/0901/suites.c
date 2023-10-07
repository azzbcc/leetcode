/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/7 09:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0901.c"

START_TEST(test_official) {
    StockSpanner *spanner = stockSpannerCreate();
    ck_assert_ptr_nonnull(spanner);

    ck_assert_int_eq(1, stockSpannerNext(spanner, 100));
    ck_assert_int_eq(1, stockSpannerNext(spanner, 80));
    ck_assert_int_eq(1, stockSpannerNext(spanner, 60));
    ck_assert_int_eq(2, stockSpannerNext(spanner, 70));
    ck_assert_int_eq(1, stockSpannerNext(spanner, 60));
    ck_assert_int_eq(4, stockSpannerNext(spanner, 75));
    ck_assert_int_eq(6, stockSpannerNext(spanner, 85));

    stockSpannerFree(spanner);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}