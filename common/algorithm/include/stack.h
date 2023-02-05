/*
Copyright (C), 2020-2050, Tech. Co., Ltd.
File name: stack.h
Author: Youjian zhang
Version: 1.0
Date: 2021.4.13
Description: heard file
*/
#ifndef STACK_H
#define STACK_H
#include "pub.h"
#include "type.h"
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void    *stack;
    int     top;
    int     stackSize;
    int     eleSize;
} StackT;

StackT *StackCreate(unsigned int stackSize, unsigned int eleSize);

void StackDestroy(StackT *stack);

int StackPush(StackT *stack, const void *value);

int StackPop(StackT *stack, void *value);

int StackTop(StackT *stack, void *value);

int StackSize(const StackT *stack);

bool StackIsEmpty(const StackT *stack);

#ifdef __cplusplus
}
#endif
#endif