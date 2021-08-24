/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/24 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0787.c"

START_TEST(test_official_1) {
    int n = 3, *edges[] = { (int[]) { 0, 1, 100 }, (int[]) { 1, 2, 100 }, (int[]) { 0, 2, 500 } };
    int src = 0, dst = 2, k = 1;
    int target = 200, ans = findCheapestPrice(n, edges, LEN(edges), NULL, src, dst, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, *edges[] = { (int[]) { 0, 1, 100 }, (int[]) { 1, 2, 100 }, (int[]) { 0, 2, 500 } };
    int src = 0, dst = 2, k = 0;
    int target = 500, ans = findCheapestPrice(n, edges, LEN(edges), NULL, src, dst, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int n = 17, src = 13, dst = 4, k = 13;
    int *edges[] = { (int[]) { 0, 12, 28 },   (int[]) { 5, 6, 39 },   (int[]) { 8, 6, 59 },   (int[]) { 13, 15, 7 },
                     (int[]) { 13, 12, 38 },  (int[]) { 10, 12, 35 }, (int[]) { 15, 3, 23 },  (int[]) { 7, 11, 26 },
                     (int[]) { 9, 4, 65 },    (int[]) { 10, 2, 38 },  (int[]) { 4, 7, 7 },    (int[]) { 14, 15, 31 },
                     (int[]) { 2, 12, 44 },   (int[]) { 8, 10, 34 },  (int[]) { 13, 6, 29 },  (int[]) { 5, 14, 89 },
                     (int[]) { 11, 16, 13 },  (int[]) { 7, 3, 46 },   (int[]) { 10, 15, 19 }, (int[]) { 12, 4, 58 },
                     (int[]) { 13, 16, 11 },  (int[]) { 16, 4, 76 },  (int[]) { 2, 0, 12 },   (int[]) { 15, 0, 22 },
                     (int[]) { 16, 12, 13 },  (int[]) { 7, 1, 29 },   (int[]) { 7, 14, 100 }, (int[]) { 16, 1, 14 },
                     (int[]) { 9, 6, 74 },    (int[]) { 11, 1, 73 },  (int[]) { 2, 11, 60 },  (int[]) { 10, 11, 85 },
                     (int[]) { 2, 5, 49 },    (int[]) { 3, 4, 17 },   (int[]) { 4, 9, 77 },   (int[]) { 16, 3, 47 },
                     (int[]) { 15, 6, 78 },   (int[]) { 14, 1, 90 },  (int[]) { 10, 5, 95 },  (int[]) { 1, 11, 30 },
                     (int[]) { 11, 0, 37 },   (int[]) { 10, 4, 86 },  (int[]) { 0, 8, 57 },   (int[]) { 6, 14, 68 },
                     (int[]) { 16, 8, 3 },    (int[]) { 13, 0, 65 },  (int[]) { 2, 13, 6 },   (int[]) { 5, 13, 5 },
                     (int[]) { 8, 11, 31 },   (int[]) { 6, 10, 20 },  (int[]) { 6, 2, 33 },   (int[]) { 9, 1, 3 },
                     (int[]) { 14, 9, 58 },   (int[]) { 12, 3, 19 },  (int[]) { 11, 2, 74 },  (int[]) { 12, 14, 48 },
                     (int[]) { 16, 11, 100 }, (int[]) { 3, 12, 38 },  (int[]) { 12, 13, 77 }, (int[]) { 10, 9, 99 },
                     (int[]) { 15, 13, 98 },  (int[]) { 15, 12, 71 }, (int[]) { 1, 4, 28 },   (int[]) { 7, 0, 83 },
                     (int[]) { 3, 5, 100 },   (int[]) { 8, 9, 14 },   (int[]) { 15, 11, 57 }, (int[]) { 3, 6, 65 },
                     (int[]) { 1, 3, 45 },    (int[]) { 14, 7, 74 },  (int[]) { 2, 10, 39 },  (int[]) { 4, 8, 73 },
                     (int[]) { 13, 5, 77 },   (int[]) { 10, 0, 43 },  (int[]) { 12, 9, 92 },  (int[]) { 8, 2, 26 },
                     (int[]) { 1, 7, 7 },     (int[]) { 9, 12, 10 },  (int[]) { 13, 11, 64 }, (int[]) { 8, 13, 80 },
                     (int[]) { 6, 12, 74 },   (int[]) { 9, 7, 35 },   (int[]) { 0, 15, 48 },  (int[]) { 3, 7, 87 },
                     (int[]) { 16, 9, 42 },   (int[]) { 5, 16, 64 },  (int[]) { 4, 5, 65 },   (int[]) { 15, 14, 70 },
                     (int[]) { 12, 0, 13 },   (int[]) { 16, 14, 52 }, (int[]) { 3, 10, 80 },  (int[]) { 14, 11, 85 },
                     (int[]) { 15, 2, 77 },   (int[]) { 4, 11, 19 },  (int[]) { 2, 7, 49 },   (int[]) { 10, 7, 78 },
                     (int[]) { 14, 6, 84 },   (int[]) { 13, 7, 50 },  (int[]) { 11, 6, 75 },  (int[]) { 5, 10, 46 },
                     (int[]) { 13, 8, 43 },   (int[]) { 9, 10, 49 },  (int[]) { 7, 12, 64 },  (int[]) { 0, 10, 76 },
                     (int[]) { 5, 9, 77 },    (int[]) { 8, 3, 28 },   (int[]) { 11, 9, 28 },  (int[]) { 12, 16, 87 },
                     (int[]) { 12, 6, 24 },   (int[]) { 9, 15, 94 },  (int[]) { 5, 7, 77 },   (int[]) { 4, 10, 18 },
                     (int[]) { 7, 2, 11 },    (int[]) { 9, 5, 41 } };
    int target = 47, ans = findCheapestPrice(n, edges, LEN(edges), NULL, src, dst, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n = 5, src = 0, dst = 2, k = 2;
    int *edges[] = { (int[]) { 0, 1, 5 }, (int[]) { 1, 2, 5 }, (int[]) { 0, 3, 2 },
                     (int[]) { 3, 1, 2 }, (int[]) { 1, 4, 1 }, (int[]) { 4, 2, 1 } };
    int target = 7, ans = findCheapestPrice(n, edges, LEN(edges), NULL, src, dst, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}