#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
using namespace std;
#include "stack.h"

class test_stack : public testing::Test {
protected:

    static void SetUpTestCase() {
    }

    static void TearDownTestCase() {
    }

    virtual void SetUp() {}
    virtual void TearDown() {
    }
private:

};

TEST_F(test_stack, CreateAndDestroy)
{
    uint32 stackSize = 10;
    StackT *stack = StackCreate(stackSize, sizeof(double));

    StackDestroy(stack);
}

TEST_F(test_stack, test2)
{
    uint32 stackSize = 10;
    StackT *stack = StackCreate(stackSize, sizeof(double));

    double value = 1.5;
    StackPush(stack, &value);

    value = 2.3;
    StackPush(stack, &value);

    value = 5.7;
    StackPush(stack, &value);

    value = 3.9;
    StackPush(stack, &value);

    value = 11.23;
    StackPush(stack, &value);

    EXPECT_EQ(5, StackSize(stack));

    double topVal;
    EXPECT_EQ(STATUS_OK, StackTop(stack, &topVal));
    EXPECT_EQ(value, topVal);


    StackDestroy(stack);
}

