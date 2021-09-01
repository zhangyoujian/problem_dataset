/*
Copyright (C), 2020-2050, Tech. Co., Ltd.
File name: pub.h
Author: Youjian zhang
Version: 1.0
Date: 2021.4.13
Description: heard file
*/

#ifndef PUB_H
#define PUB_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STATUS_OK       0
#define STATUS_ERROR    -1

#ifndef DEBUG
    #define ASSERT(p)       (void)(p)
#else
    #define ASSERT(p)       assert(p)
#endif

typedef unsigned int uint32;
typedef int int32;

#ifdef __cplusplus
}
#endif
#endif