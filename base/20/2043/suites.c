/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/18 下午2:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2043.c"

START_TEST(test_official) {
    long long balance[] = { 10, 100, 20, 50, 30 };

    Bank *bank = bankCreate(balance, LEN(balance));
    ck_assert_ptr_nonnull(bank);

    ck_assert_int_eq(true, bankWithdraw(bank, 3, 10));
    ck_assert_int_eq(true, bankTransfer(bank, 5, 1, 20));
    ck_assert_int_eq(true, bankDeposit(bank, 5, 20));
    ck_assert_int_eq(false, bankTransfer(bank, 3, 4, 15));
    ck_assert_int_eq(false, bankWithdraw(bank, 10, 50));

    bankFree(bank);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}