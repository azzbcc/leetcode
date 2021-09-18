/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/18 下午3:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0900.c"

START_TEST(test_official) {
    int arr[]         = { 3, 8, 0, 9, 2, 5 };
    RLEIterator *iter = rLEIteratorCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(iter);

    ck_assert_int_eq(8, rLEIteratorNext(iter, 2));
    ck_assert_int_eq(8, rLEIteratorNext(iter, 1));
    ck_assert_int_eq(5, rLEIteratorNext(iter, 1));
    ck_assert_int_eq(-1, rLEIteratorNext(iter, 2));

    rLEIteratorFree(iter);
}

START_TEST(test_limit) {
    int arr[]         = { 923381016, 843, 898173122, 924, 540599925, 391, 705283400, 275, 811628709, 850,
                  895038968, 590, 949764874, 580, 450563107, 660, 996257840, 917, 793325084, 82 };
    RLEIterator *iter = rLEIteratorCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(iter);

    int argv[]   = { 612783106, 486444202, 630147341, 845077576, 243035623, 731489221, 117134294,
                   220460537, 794582972, 332536150, 815913097, 100607521, 146358489, 697670641,
                   45234068,  573866037, 519323635, 27431940,  16279485,  203970 };
    int target[] = { 843, 924, 924, 275, 275, 850, 850, 590, 590, 580, 660, 660, 660, 917, 917, 82, 82, 82, 82, 82 };

    for (int i = 0; i < LEN(argv); ++i) {
        ck_assert_int_eq(target[i], rLEIteratorNext(iter, argv[i]));
    }

    rLEIteratorFree(iter);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official);
}