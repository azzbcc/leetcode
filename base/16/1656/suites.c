/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/16 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1656.c"

START_TEST(test_official) {
    OrderedStream *stream = orderedStreamCreate(5);
    ck_assert_ptr_nonnull(stream);

#define ORDERED_STREAM_CHECK(id, val, ...)                                                                             \
    {                                                                                                                  \
        int len        = 0;                                                                                            \
        char *target[] = { __VA_ARGS__ };                                                                              \
        char **ans     = orderedStreamInsert(stream, id, val, &len);                                                   \
        ck_assert_int_eq(len, LEN(target));                                                                            \
        for (int i = 0; i < len; ++i) {                                                                                \
            ck_assert_str_eq(ans[i], target[i]);                                                                       \
        }                                                                                                              \
        free(ans);                                                                                                     \
    }
    ORDERED_STREAM_CHECK(3, "ccccc");
    ORDERED_STREAM_CHECK(1, "aaaaa", "aaaaa");
    ORDERED_STREAM_CHECK(2, "bbbbb", "bbbbb", "ccccc");
    ORDERED_STREAM_CHECK(5, "eeeee");
    ORDERED_STREAM_CHECK(4, "ddddd", "ddddd", "eeeee");

    orderedStreamFree(stream);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}