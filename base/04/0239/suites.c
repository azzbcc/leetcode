/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/2 下午1:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "239.c"

#ifdef USE_QUEUE
int queue_length(queue_t *q) {
    return (q->rear + q->size - q->front) % q->size;
}

START_TEST(test_queue) {
    int arr[] = { 1, 1, 1, 1, 1 };
    int memory[sizeof(queue_t) / sizeof(int) + LEN(arr) + 1];
    queue_t *q = ( queue_t * )memory;

    queue_init(q, LEN(arr) + 1);
    for (int i = 0; i < LEN(arr); ++i) {
        queue_rpush(q, arr[i]);
        ck_assert_int_eq(queue_length(q), i + 1);
    }
}
#endif

START_TEST(test_official_1) {
    int nums[] = { 1, 3, -1, -3, 5, 3, 6, 7 }, k = 3;
    int target[] = { 3, 3, 5, 5, 6, 7 };
    int len, *ans = maxSlidingWindow(nums, LEN(nums), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1 }, k = 1;
    int target[] = { 1 };
    int len, *ans = maxSlidingWindow(nums, LEN(nums), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int nums[] = { 1, -1 }, k = 1;
    int target[] = { 1, -1 };
    int len, *ans = maxSlidingWindow(nums, LEN(nums), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_4) {
    int nums[] = { 9, 11 }, k = 2;
    int target[] = { 11 };
    int len, *ans = maxSlidingWindow(nums, LEN(nums), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_5) {
    int nums[] = { 4, -2 }, k = 2;
    int target[] = { 4 };
    int len, *ans = maxSlidingWindow(nums, LEN(nums), k, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
#ifdef USE_QUEUE
    tcase_add_test(t, test_queue);
#endif
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}