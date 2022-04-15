/**
 * nested_integer.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/15 上午8:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include "nested_integer.h"

#define MAXN 0x1000

struct NestedInteger {
    int count;
    bool isDigit;
    struct NestedInteger **data;
};

static void nested_dump_real(nested_int_t *list, char **const out) {
    if (list->isDigit) {
        *out += sprintf(*out, "%d", list->count);
        return;
    }
    *(*out)++ = '[';
    for (int i = 0; i < list->count; ++i) {
        nested_dump_real(list->data[i], out);
        if (i + 1 < list->count) *(*out)++ = ',';
    }
    *(*out)++ = ']', **out = '\0';
}

char *nested_dump(nested_int_t *list) {
    static char str[MAXN];
    char *p = str;

    nested_dump_real(list, &p);
    return str;
}

void nested_free(nested_int_t *list) {
    if (!list) return;
    for (int i = 0; !list->isDigit && i < list->count; nested_free(list->data[i++])) {}
    if (!list->isDigit) free(list->data);
    free(list);
}

/////////////////////////////////////////////////////////////
nested_int_t *NestedIntegerInit() {
    return calloc(1, sizeof(nested_int_t));
}
bool NestedIntegerIsInteger(nested_int_t *list) {
    return list->isDigit;
}
int NestedIntegerGetInteger(nested_int_t *list) {
    if (!list->isDigit) return 0;
    return list->count;
}
void NestedIntegerSetInteger(nested_int_t *list, int value) {
    list->isDigit = true, list->count = value;
}
void NestedIntegerAdd(nested_int_t *list, nested_int_t *elem) {
    list->data    = realloc(list->data, (list->count + 1) * sizeof(nested_int_t));
    list->isDigit = false, list->data[list->count++] = elem;
}
struct NestedInteger **NestedIntegerGetList(nested_int_t *list) {
    if (list->isDigit) return NULL;
    return list->data;
}
int NestedIntegerGetListSize(nested_int_t *list) {
    if (list->isDigit) return 0;
    return list->count;
}