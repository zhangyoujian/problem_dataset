#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
using namespace std;

class test_book : public testing::Test {
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

TEST_F(test_book, 01_problem)
{
    
}