/**
 * 0336.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/6 下午5:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0336.c"

START_TEST(test_trie) {
    int len[5];
    char *arr[] = { "abcd", "dcba", "lls", "s", "sssll" };
    trie_t trie = trie_create();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        trie_insert(trie, arr[i], i, &len[i]);
    }
    trie_free(trie);
}

int array_comp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;

    if (pa[0] == pb[0]) { return pa[1] - pb[1]; }
    return pa[0] - pb[0];
}
int point_comp(const void *a, const void *b) {
    int **pa = ( int ** )a, **pb = ( int ** )b;

    if (pa[0][0] == pb[0][0]) { return pa[0][1] - pb[0][1]; }
    return pa[0][0] - pb[0][0];
}

START_TEST(test_official_1) {
    char *arr[]     = { "abcd", "dcba", "lls", "s", "sssll" };
    int target[][2] = { { 1, 0 }, { 0, 1 }, { 3, 2 }, { 2, 4 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = palindromePairs(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(target[0]), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    char *arr[]     = { "bat", "tab", "cat" };
    int target[][2] = { { 1, 0 }, { 0, 1 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = palindromePairs(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(target[0]), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed_1) {
    char *arr[]     = { "a", "b", "c", "ab", "ac", "aa" };
    int target[][2] = { { 5, 0 }, { 3, 0 }, { 4, 0 }, { 1, 3 }, { 2, 4 }, { 0, 5 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = palindromePairs(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(target[0]), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed_2) {
    char *arr[]     = { "abcd", "dcba", "lls", "s", "sssll", "" };
    int target[][2] = { { 1, 0 }, { 0, 1 }, { 3, 2 }, { 5, 3 }, { 2, 4 }, { 3, 5 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = palindromePairs(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(target[0]), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed_3) {
    char *arr[]     = { "a", "aa", "aaa" };
    int target[][2] = { { 1, 0 }, { 2, 0 }, { 0, 1 }, { 2, 1 }, { 0, 2 }, { 1, 2 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = palindromePairs(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(target[0]), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_trie);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}