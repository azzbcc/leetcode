/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/18 下午4:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

typedef struct Node {
    int val;
    struct Node *next;
} node_t, *list_t;

#include "029.c"

static list_t node_create(int *arr, int size) {
    if (!size) return NULL;
    node_t *nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = malloc(sizeof(struct Node)), nodes[i]->val = arr[i];
    }
    for (int i = 0; i < size; ++i) {
        nodes[i]->next = nodes[(i + 1) % size];
    }
    return nodes[0];
}
static void node_dump(list_t list, int arr[], int size) {
    for (int i = 0; i < size; arr[i++] = list->val, list = list->next) {}
}
static void node_destroy(list_t list) {
    for (list_t cur = list, next = NULL; next != list; cur = next) {
        next = cur->next;
        free(cur);
    }
}

START_TEST(test_official_1) {
    int arr[] = { 3, 4, 1 }, val = 1, res[LEN(arr) + 1];
    int target[] = { 3, 4, 1, 1 };
    list_t list  = node_create(arr, LEN(arr));
    list_t ans   = insert(list, val);
    node_dump(ans, res, LEN(res));

    ck_assert_mem_eq(res, target, sizeof(target));
    node_destroy(ans);
}

START_TEST(test_official_2) {
    int arr[] = {}, val = 1, res[LEN(arr) + 1];
    int target[] = { 1 };
    list_t list  = node_create(arr, LEN(arr));
    list_t ans   = insert(list, val);
    node_dump(ans, res, LEN(res));

    ck_assert_mem_eq(res, target, sizeof(target));
    node_destroy(ans);
}

START_TEST(test_official_3) {
    int arr[] = { 1 }, val = 0, res[LEN(arr) + 1];
    int target[] = { 1, 0 };
    list_t list  = node_create(arr, LEN(arr));
    list_t ans   = insert(list, val);
    node_dump(ans, res, LEN(res));

    ck_assert_mem_eq(res, target, sizeof(target));
    node_destroy(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}