/**
 * common.h
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午4:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <assert.h>
#include <check.h>
#include <check_stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

void set_execute_timeout(TCase *, double);

#endif // LEETCODE_COMMON_H
