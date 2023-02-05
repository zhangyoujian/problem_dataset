#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
using namespace std;
#include "search.h"

class test_search : public testing::Test {
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

TEST_F(test_search, test1)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int target = 5;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 5);
}

TEST_F(test_search, test2)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int target = -10;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);
}

TEST_F(test_search, test3)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int target = 10;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);
}

TEST_F(test_search, test4)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int target = 0;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 0);
}

TEST_F(test_search, test5)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int target = 9;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 9);
}

TEST_F(test_search, test6)
{
    int arr[] = {0,1,2,3, 6,7,8,9};
    int target = 4;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);
}

TEST_F(test_search, test7)
{
    int arr[] = {0,1};
    int target = -1;
    int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);
}

TEST_F(test_search, test_left_bound)
{
    int arr[] = {0, 1, 1, 2, 2, 3};
    int target = 1;
    int ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 1);

    target = 2;
    ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 3);

    target = -1;
    ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);

    target = 4;
    ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);

    target = 0;
    ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 0);

    target = 3;
    ret = BinarySearchLeftBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 5);
}


TEST_F(test_search, test_right_bound)
{
    int arr[] = {0, 1, 1, 2, 2, 3};
    int target = 1;
    int ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 2);

    target = 2;
    ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 4);

    target = -1;
    ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);

    target = 4;
    ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, -1);

    target = 0;
    ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 0);

    target = 3;
    ret = BinarySearchRightBound(arr, sizeof(arr) / sizeof(arr[0]), target);
    ASSERT_EQ(ret, 5);
}