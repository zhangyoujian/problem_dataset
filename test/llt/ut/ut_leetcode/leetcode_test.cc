#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
using namespace std;
#include "04_media_of_two_sorted_arrays.h"

class Solution;

class test_leetcode : public testing::Test {
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

TEST_F(test_leetcode, 04_media_of_two_sorted_arrays)
{
    Solution A;
    vector<int> nums1 = {1,3,5};
    vector<int> nums2 = {2, 4, 6};
    double ret = A.findMedianSortedArrays(nums1, nums2);
    cout<<ret<<endl;
}