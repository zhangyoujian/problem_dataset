#include "stack.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

StackT *StackCreate(unsigned int stackSize, unsigned int eleSize)
{
    if (stackSize < 1 || eleSize == 0) {
        return NULL;
    }
    StackT *stack = (StackT *)malloc(sizeof(StackT));
    if (stack == NULL) {
       return NULL;
    }
    stack->eleSize = eleSize;
    stack->stackSize = stackSize;
    stack->top = 0;
    stack->stack = malloc(eleSize * stackSize);
    if (stack->stack == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

inline void StackDestroy(StackT *stack)
{
    ASSERT(stack != NULL);
    free(stack->stack);
    stack->stack = NULL;
    free(stack);
}

inline int StackSize(const StackT *stack)
{
    ASSERT(stack != NULL);
    return stack->top;
}

inline bool StackIsEmpty(const StackT *stack)
{
    ASSERT(stack != NULL);
    return StackSize(stack) <= 0;
}

int StackTop(StackT *stack, void *value)
{
    ASSERT(stack != NULL);
    ASSERT(value != NULL);
    if (StackIsEmpty(stack)) {
        return STATUS_ERROR;
    }
    (void)memcpy(value, stack->stack + (stack->top - 1) * stack->eleSize, stack->eleSize);
    return STATUS_OK;
}

inline int StackPush(StackT *stack, const void *value)
{
    ASSERT(stack != NULL);
    ASSERT(value != NULL);
    if (value == NULL) {
        return STATUS_ERROR;
    }
    if (StackSize(stack) >= stack->stackSize) {
        return STATUS_ERROR;
    }
    (void)memcpy(stack->stack + stack->top * stack->eleSize, value, stack->eleSize);
    stack->top++;
    return STATUS_OK;
}

inline int StackPop(StackT *stack, void *value)
{
    ASSERT(stack != NULL);
    ASSERT(value != NULL);
    int ret = StackTop(stack, value);
    if (ret != STATUS_OK) {
        return ret;
    }
    stack->top--;
}


#ifdef __cplusplus
}
#endif