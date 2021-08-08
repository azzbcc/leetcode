/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/13 下午1:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1825.c"

heap_t heap_copy(heap_t heap) {
    heap_t ans = malloc(sizeof(*ans));
    memcpy(ans, heap, sizeof(*ans));

    ans->data = malloc(ans->size * sizeof(int));
    memcpy(ans->data, heap->data, ans->size * sizeof(int));

    return ans;
}
void heap_print(heap_t heap) {
    heap_t heap_new = heap_copy(heap);

    for (int i = 0; i < heap_new->size; ++i) {
        if (heap_new->del_map[heap_new->data[i]]) {
            heap_new->del_map[heap_new->data[i]] -= 1, heap_new->del_count -= 1;
            swap(&heap_new->data[i], &heap_new->data[--heap_new->size]);
            heap_adjust(heap_new, i--);
        } else {
            printf("%d%s", heap_new->data[i], i + 1 < heap_new->size ? ", " : "; ");
        }
    }
    printf("\n");

    heap_destroy(heap_new);
}
void mk_print(const MKAverage *avg) {
#if DEBUG
    printf("m = %d, k = %d, sum = %ld\n", avg->m, avg->k, avg->sum);
    printf("bot: ");
    heap_print(avg->bot);
    printf("top: ");
    heap_print(avg->top);
    printf("mid: ");
    heap_print(avg->mid0);
    printf("mid: ");
    heap_print(avg->mid1);
    printf("\n");
#endif
}
static void run_test(const int create[2], size_t len, char *commands[len], const int argv[]) {
    MKAverage *avg = mKAverageCreate(create[0], create[1]);
    for (int i = 0; i < len; ++i) {
        if (!strcmp("addElement", commands[i])) {
            mKAverageAddElement(avg, argv[i]);
            mk_print(avg);
        } else {
            int target = argv[i], ans = mKAverageCalculateMKAverage(avg);
            ck_assert_int_eq(ans, target);
        }
    }
    mKAverageFree(avg);
}

START_TEST(test_official) {
    int create[]     = { 3, 1 };
    char *commands[] = { "addElement", "addElement", "calculateMKAverage", "addElement",        "calculateMKAverage",
                         "addElement", "addElement", "addElement",         "calculateMKAverage" };
    int argv[]       = { 3, 1, -1, 10, 3, 5, 5, 5, 5 };

    run_test(create, LEN(commands), commands, argv);
}

START_TEST(test_failed_1) {
    int create[]     = { 6, 1 };
    char *commands[] = { "addElement", "addElement", "addElement",        "addElement",
                         "addElement", "addElement", "calculateMKAverage" };
    int argv[]       = { 3, 1, 12, 5, 3, 4, 3 };

    run_test(create, LEN(commands), commands, argv);
}

START_TEST(test_failed_2) {
    int create[]     = { 30, 10 };
    char *commands[] = {
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement", "addElement", "calculateMKAverage",
        "addElement", "addElement", "calculateMKAverage", "addElement"
    };
    int argv[] = { 87859, 24884, -1,    39764, 37246, -1,    77016, 65453, -1,    66229, 51558, -1,    77202,
                   4526,  -1,    62945, 31817, -1,    97483, 52991, -1,    54305, 87130, -1,    22677, 48120,
                   -1,    71933, 92149, -1,    88407, 96760, -1,    49114, 11334, -1,    57536, 87001, -1,
                   66641, 14147, -1,    21457, 68281, 59505, 51545, 48566, 57831, 64186, 96046, 61012, 3877,
                   61515, 58945, 5700,  40440, 56934, 92194, 80585, 58905, 77750, 75783, 62471, 51590, 84825,
                   62331, 22329, 22098, 59090, 65830, 29746, 60817, 1613,  26152, 55696, 70729, 71872, 55696,
                   30432, 53013, 56086, 67342, 45066, 54839, 75733, 46305, 55495, 60180, 35295, 54779, 86405,
                   71827, 58575, 79816, 95604, 59339, 749,   50291, 58217, 97060 };

    run_test(create, LEN(commands), commands, argv);
}

START_TEST(test_random_tle) {
    int create[] = { 50000, 1000 };
#include "tle.c"

    run_test(create, LEN(commands), commands, argv);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_random_tle);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}