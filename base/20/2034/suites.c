/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/8 10:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2034.c"

START_TEST(test_official) {
    StockPrice *stock = stockPriceCreate();
    ck_assert_ptr_nonnull(stock);

    stockPriceUpdate(stock, 1, 10);                 // 时间戳为 [1] ，对应的股票价格为 [10] 。
    stockPriceUpdate(stock, 2, 5);                  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
    ck_assert_int_eq(5, stockPriceCurrent(stock));  // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
    ck_assert_int_eq(10, stockPriceMaximum(stock)); // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
    stockPriceUpdate(stock, 1, 3);                  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                                                    // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
    ck_assert_int_eq(5, stockPriceMaximum(stock));  // 返回 5 ，更正后最高价格为 5 。
    stockPriceUpdate(stock, 4, 2);                  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
    ck_assert_int_eq(2, stockPriceMinimum(stock));  // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。

    stockPriceFree(stock);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}