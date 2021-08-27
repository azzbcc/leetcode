/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/27 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0295.c"

//#define DEBUG_PRINT

START_TEST(test_heap) {
    int size = 20, num[size];
    for (int i = 0; i < size; ++i) {
        num[i] = i + 1;
    }
    srand(( unsigned )time(NULL));
    for (int i = size - 1; i >= 0; --i) {
        swap(&num[rand() % (i + 1)], &num[i]);
    }
#ifdef DEBUG_PRINT
    for (int i = 0; i < size; ++i) {
        printf("%d%s", num[i], i + 1 < size ? ", " : "\n");
    }
#endif

    heap_t heap = heap_init(min);
    for (int i = 0; i < size; ++i) {
        heap_add(heap, num[i]);
#ifdef DEBUG_PRINT
        for (int j = heap->size / 2 - 1; j >= 0; --j) {
            if (2 * j + 2 < heap->size) {
                printf("(%d, %d, %d)", heap->data[j], heap->data[2 * j + 1], heap->data[2 * j + 2]);
            } else {
                printf("(%d, %d)", heap->data[j], heap->data[2 * j + 1]);
            }
            printf(j ? ", " : "\n");
        }
#endif
    }
    heap_destroy(heap);
}

START_TEST(test_official) {
    MedianFinder *medianFinder = medianFinderCreate();
    ck_assert_ptr_nonnull(medianFinder);

    medianFinderAddNum(medianFinder, 1);
    medianFinderAddNum(medianFinder, 2);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), 1.5, 0.0001);
    medianFinderAddNum(medianFinder, 3);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), 2.0, 0.0001);

    medianFinderFree(medianFinder);
}

START_TEST(test_failed) {
    MedianFinder *medianFinder = medianFinderCreate();
    ck_assert_ptr_nonnull(medianFinder);

    medianFinderAddNum(medianFinder, -1);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), -1, 0.0001);
    medianFinderAddNum(medianFinder, -2);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), -1.5, 0.0001);
    medianFinderAddNum(medianFinder, -3);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), -2.0, 0.0001);
    medianFinderAddNum(medianFinder, -4);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), -2.5, 0.0001);
    medianFinderAddNum(medianFinder, -5);
    ck_assert_double_eq_tol(medianFinderFindMedian(medianFinder), -3.0, 0.0001);

    medianFinderFree(medianFinder);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_heap);
    tcase_add_test(t, test_official);
}