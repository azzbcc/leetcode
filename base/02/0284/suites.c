/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/5 下午10:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

typedef struct Iterator {
    // Returns true if the iteration has more elements.
    bool (*hasNext)();
    // Returns the next element in the iteration.
    int (*next)();
} iterator_t;

#include "0284.c"

static int *data, current, size;
static bool iterator_has_next() {
    return current < size;
}
static int iterator_next() {
    return data[current++];
}

START_TEST(test_official) {
    int arr[]           = { 1, 2, 3 };
    iterator_t iterator = { iterator_has_next, iterator_next };

    data = arr, current = 0, size = LEN(arr);

    peeking_iterator_t *peekingIterator = Constructor(&iterator);
    ck_assert_ptr_nonnull(peekingIterator);

    ck_assert_int_eq(1, next(peekingIterator));
    ck_assert_int_eq(2, peek(peekingIterator));
    ck_assert_int_eq(2, next(peekingIterator));
    ck_assert_int_eq(3, next(peekingIterator));
    ck_assert_int_eq(false, hasNext(peekingIterator));

    free(peekingIterator);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}