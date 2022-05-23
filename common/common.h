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
#include <time.h>
#ifdef __APPLE__
#include <uthash/uthash.h>
#else
#include <uthash.h>
#endif

#define LEN(array) (sizeof(array) / sizeof(array[0]))

void set_execute_timeout(TCase *, double);

#ifdef PROGRAM
const char *program = PROGRAM;
#else
const char *program = "";
#endif

#endif // LEETCODE_COMMON_H
