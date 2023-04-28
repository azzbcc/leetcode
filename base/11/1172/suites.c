/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/28 15:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1172.c"

START_TEST(test_official) {
    DinnerPlates *plates = dinnerPlatesCreate(2);
    ck_assert_ptr_nonnull(plates);

    for (int i = 1; i <= 5; ++i) {
        dinnerPlatesPush(plates, i);
    }
    ck_assert_int_eq(2, dinnerPlatesPopAtStack(plates, 0));
    dinnerPlatesPush(plates, 20);
    dinnerPlatesPush(plates, 21);
    ck_assert_int_eq(20, dinnerPlatesPopAtStack(plates, 0));
    ck_assert_int_eq(21, dinnerPlatesPopAtStack(plates, 2));
    ck_assert_int_eq(5, dinnerPlatesPop(plates));
    ck_assert_int_eq(4, dinnerPlatesPop(plates));
    ck_assert_int_eq(3, dinnerPlatesPop(plates));
    ck_assert_int_eq(1, dinnerPlatesPop(plates));
    ck_assert_int_eq(-1, dinnerPlatesPop(plates));

    dinnerPlatesFree(plates);
}

START_TEST(test_failed_1) {
    DinnerPlates *plates = dinnerPlatesCreate(1);
    ck_assert_ptr_nonnull(plates);

    for (int i = 1; i <= 3; ++i) {
        dinnerPlatesPush(plates, i);
    }
    ck_assert_int_eq(2, dinnerPlatesPopAtStack(plates, 1));
    ck_assert_int_eq(3, dinnerPlatesPop(plates));
    ck_assert_int_eq(1, dinnerPlatesPop(plates));

    dinnerPlatesFree(plates);
}

START_TEST(test_failed_2) {
    DinnerPlates *plates = dinnerPlatesCreate(2);
    ck_assert_ptr_nonnull(plates);

    char *commands[] = { "push",       "push",       "push",       "push",       "push",       "push",
                         "push",       "push",       "popAtStack", "popAtStack", "popAtStack", "popAtStack",
                         "popAtStack", "popAtStack", "popAtStack", "popAtStack", "popAtStack", "popAtStack",
                         "push",       "push",       "push",       "push",       "push",       "push",
                         "push",       "push",       "pop",        "pop",        "pop",        "pop",
                         "pop",        "pop",        "pop",        "pop",        "pop",        "pop" };
    int args[]   = { 472, 106, 497, 498, 73,  115, 437, 461, 3,    3,    1,    3,    0,    2,    2,    1,    1,    3,
                     197, 239, 129, 449, 460, 240, 386, 343, null, null, null, null, null, null, null, null, null, null };
    int target[] = { null, null, null, null, null, null, null, null, 461, 437, 498, -1,  106, 115, 73,  497, -1,  -1,
                     null, null, null, null, null, null, null, null, 343, 386, 240, 460, 449, 129, 239, 197, 472, -1 };
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp("push", commands[i])) {
            dinnerPlatesPush(plates, args[i]);
        } else if (!strcmp("pop", commands[i])) {
            ck_assert_int_eq(target[i], dinnerPlatesPop(plates));
        } else {
            ck_assert_int_eq(target[i], dinnerPlatesPopAtStack(plates, args[i]));
        }
    }

    dinnerPlatesFree(plates);
}

START_TEST(test_failed_3) {
    DinnerPlates *plates = dinnerPlatesCreate(1);
    ck_assert_ptr_nonnull(plates);

    for (int i = 1; i <= 2; ++i) {
        dinnerPlatesPush(plates, i);
    }
    ck_assert_int_eq(2, dinnerPlatesPopAtStack(plates, 1));
    ck_assert_int_eq(1, dinnerPlatesPop(plates));
    dinnerPlatesPush(plates, 1);
    dinnerPlatesPush(plates, 2);
    ck_assert_int_eq(2, dinnerPlatesPop(plates));
    ck_assert_int_eq(1, dinnerPlatesPop(plates));

    dinnerPlatesFree(plates);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}