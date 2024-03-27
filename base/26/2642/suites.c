/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/27 15:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2642.c"

START_TEST(test_official) {
    int n = 4, *edges[] = { (int[]) { 0, 2, 5 }, (int[]) { 0, 1, 2 }, (int[]) { 1, 2, 1 }, (int[]) { 3, 0, 3 } };

    Graph *graph = graphCreate(n, edges, LEN(edges), NULL);
    ck_assert_ptr_nonnull(graph);

    ck_assert_int_eq(6, graphShortestPath(graph, 3, 2));
    ck_assert_int_eq(-1, graphShortestPath(graph, 0, 3));

    graphAddEdge(graph, (int[]) { 1, 3, 4 }, 3);
    ck_assert_int_eq(6, graphShortestPath(graph, 0, 3));

    graphFree(graph);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}