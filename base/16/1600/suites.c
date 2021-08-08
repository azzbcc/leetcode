/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/20 下午9:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1600.c"

START_TEST(test_official) {
    char *king       = "king";
    char *commands[] = {
        "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"
    };
    char *args[][7] = { { "king", "andy" },
                        { "king", "bob" },
                        { "king", "catherine" },
                        { "andy", "matthew" },
                        { "bob", "alex" },
                        { "bob", "asha" },
                        { "king", "andy", "matthew", "bob", "alex", "asha", "catherine" },
                        { "bob" },
                        { "king", "andy", "matthew", "alex", "asha", "catherine" } };
    int len, col[] = { 2, 2, 2, 2, 2, 2, 7, 1, 6 };

    ThroneInheritance *inheritance = throneInheritanceCreate(king);
    ck_assert_ptr_nonnull(inheritance);
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp("birth", commands[i])) {
            throneInheritanceBirth(inheritance, args[i][0], args[i][1]);
        } else if (!strcmp("death", commands[i])) {
            throneInheritanceDeath(inheritance, args[i][0]);
        } else {
            char **ans = throneInheritanceGetInheritanceOrder(inheritance, &len);
            ck_assert_int_eq(len, col[i]);
            for (int j = 0; j < len; ++j) {
                ck_assert_str_eq(ans[j], args[i][j]);
            }
            free(ans);
        }
    }
    throneInheritanceFree(inheritance);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}