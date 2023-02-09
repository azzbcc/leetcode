/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/9 下午2:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1797.c"

START_TEST(test_official) {
    AuthenticationManager *manager = authenticationManagerCreate(5);
    ck_assert_ptr_nonnull(manager);

    authenticationManagerRenew(manager, "aaa", 1);
    authenticationManagerGenerate(manager, "aaa", 2);
    ck_assert_int_eq(1, authenticationManagerCountUnexpiredTokens(manager, 6));
    authenticationManagerGenerate(manager, "bbb", 7);
    authenticationManagerRenew(manager, "aaa", 8);
    authenticationManagerRenew(manager, "bbb", 10);
    ck_assert_int_eq(0, authenticationManagerCountUnexpiredTokens(manager, 15));

    authenticationManagerFree(manager);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}