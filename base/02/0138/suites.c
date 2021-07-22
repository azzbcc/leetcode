/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/22 下午5:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#define null INT32_MIN

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

#include "0138.c"

typedef struct Node *node_t;
static node_t list_create(int **arr, size_t len) {
    if (len == 0) return NULL;
    node_t nodes[len];

    for (int i = 0; i < len; ++i) {
        nodes[i] = malloc(sizeof(struct Node));
    }
    for (int i = 0; i < len; ++i) {
        nodes[i]->val    = arr[i][0];
        nodes[i]->next   = i + 1 == len ? NULL : nodes[i + 1];
        nodes[i]->random = arr[i][1] == null ? NULL : nodes[arr[i][1]];
    }

    return nodes[0];
}
static bool node_equal(node_t l1, node_t l2) {
    bool ans  = true;
    node_t p1 = l1, p2 = l2;
    hash_t hash = NULL, cur, next;
    while (ans && p1 && p2) {
        ans = p1->val == p2->val;
        cur = malloc(sizeof(*cur)), cur->from = p1, cur->to = p2;
        HASH_ADD_PTR(hash, from, cur);
        p1 = p1->next, p2 = p2->next;
    }
    ans = ans && !p1 && !p2;
    if (ans) {
        HASH_ITER(hh, hash, cur, next) {
            ans = ans && cur->to->next == node_find(hash, cur->from->next);
            ans = ans && cur->to->random == node_find(hash, cur->from->random);
        }
    }

    HASH_ITER(hh, hash, cur, next) {
        HASH_DEL(hash, cur);
        free(cur);
    }
    return ans;
}
static void node_free(node_t l) {
    if (!l) return;
    node_free(l->next);
    free(l);
}

START_TEST(test_official_1) {
    int *arr[] = { (int[]) { 7, null }, (int[]) { 13, 0 }, (int[]) { 11, 4 }, (int[]) { 10, 2 }, (int[]) { 1, 0 } };
    node_t la = list_create(arr, LEN(arr)), lt = copyRandomList(la);
    ck_assert(node_equal(la, lt));
    node_free(la), node_free(lt);
}

START_TEST(test_official_2) {
    int *arr[] = { (int[]) { 1, 1 }, (int[]) { 2, 1 } };
    node_t la = list_create(arr, LEN(arr)), lt = copyRandomList(la);
    ck_assert(node_equal(la, lt));
    node_free(la), node_free(lt);
}

START_TEST(test_official_3) {
    int *arr[] = { (int[]) { 3, null }, (int[]) { 3, 0 }, (int[]) { 3, null } };
    node_t la = list_create(arr, LEN(arr)), lt = copyRandomList(la);
    ck_assert(node_equal(la, lt));
    node_free(la), node_free(lt);
}

START_TEST(test_official_4) {
    int *arr[] = {};
    node_t la = list_create(arr, LEN(arr)), lt = copyRandomList(la);
    ck_assert(node_equal(la, lt));
    node_free(la), node_free(lt);
}

START_TEST(test_own) {
    int *arr[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 } };
    node_t la = list_create(arr, LEN(arr)), lt = copyRandomList(la);
    ck_assert(node_equal(la, lt));
    node_free(la), node_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}