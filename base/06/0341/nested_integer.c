/**
 * nested_integer.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/23 下午2:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include "nested_integer.h"

#define MAXN 0x100

struct NestedInteger {
    bool isDigit;
    int count;
    struct NestedInteger *data[];
};

static nested_int_t *nested_create_digit(int digit) {
    nested_int_t *ans = malloc(sizeof(nested_int_t));
    ans->isDigit = true, ans->count = digit;
    return ans;
}
static nested_int_t *nested_create_real(const char **const s) {
    int count                  = 0;
    nested_int_t *memory[MAXN] = { NULL };

    for ((*s)++; **s;) {
        if (isdigit(**s) || **s == '-') {
            int digit = 0, sign = 1;
            if (**s == '-') sign = -1, (*s)++;
            while (isdigit(**s)) {
                digit *= 10, digit += *(*s)++ - '0';
            }
            memory[count++] = nested_create_digit(digit * sign);
        } else if (**s == '[') {
            memory[count++] = nested_create_real(s);
        } else if (*(*s)++ == ']') {
            break;
        }
    }

    nested_int_t *ans = malloc(sizeof(nested_int_t) + count * sizeof(nested_int_t *));
    ans->isDigit = false, ans->count = count;
    memcpy(ans + 1, memory, count * sizeof(nested_int_t *));

    return ans;
}
nested_int_t *nested_create(const char *s) {
    return nested_create_real(&s);
}
void nested_free(nested_int_t *list) {
    if (!list) return;
    for (int i = 0; !list->isDigit && i < list->count; nested_free(list->data[i++])) {}
    free(list);
}

/////////////////////////////////////////////////////////////
bool NestedIntegerIsInteger(nested_int_t *list) {
    return list->isDigit;
}
int NestedIntegerGetInteger(nested_int_t *list) {
    if (!list->isDigit) return 0;
    return list->count;
}
struct NestedInteger **NestedIntegerGetList(nested_int_t *list) {
    if (list->isDigit) return NULL;
    return list->data;
}
int NestedIntegerGetListSize(nested_int_t *list) {
    if (list->isDigit) return 0;
    return list->count;
}