/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-24 下午17:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <list.h>

#include "0002.c"

static int *split(int n) {
    static int arr[0xf] = { 0 };

    arr[0] = 0;
    for (int i = 0; n; ++i, n /= 10) {
        arr[i] = n % 10;
    }

    return arr;
}

START_TEST(test_official) {
    list_t l1  = list_create_size(split(342), 3);
    list_t l2  = list_create_size(split(465), 3);
    list_t sum = list_create_size(split(342 + 465), 3);

    list_t l3 = addTwoNumbers(l1, l2);

    ck_assert(list_equal(sum, l3));

    list_free(l1);
    list_free(l2);
    list_free(l3);
    list_free(sum);
}

START_TEST(test_own) {
    list_t l1 = list_create_size(split(9543), 4);
    list_t l2 = list_create_size(split(564), 3);
    list_t sum = list_create_size(split(9543 + 564), 5);

	list_t l3 = addTwoNumbers(l1, l2);

	ck_assert(list_equal(sum, l3));

	list_free(l1);
	list_free(l2);
	list_free(l3);
    list_free(sum);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
    tcase_add_test(t, test_own);
}