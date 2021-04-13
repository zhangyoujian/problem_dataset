#include "leetcode_pub.h"

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

TEST_F(test_leetcode, 01_TwoSum)
{
    Solution_01 A;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ret = A.twoSum(nums, target);
    EXPECT_EQ(2, ret.size());
    EXPECT_EQ(0, ret[0]);
    EXPECT_EQ(1, ret[1]);
}

TEST_F(test_leetcode, 04_media_of_two_sorted_arrays)
{
    Solution_04 A;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double ret = A.findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(ret, 2.5000);
}

TEST_F(test_leetcode, 07_reverse_integer)
{
    Solution_07 A;
    int data1 = -123;
    int ret = A.reverse(data1);
    EXPECT_EQ(ret, -321);

    int data2 = 1534236469;
    ret = A.reverse(data2);
    EXPECT_EQ(ret, 0);
    
}

TEST_F(test_leetcode, 08_string_to_integer)
{
    Solution_08 A;
    int ret = A.myAtoi("123");
    EXPECT_EQ(ret, 123);

    ret = A.myAtoi("-456");
    EXPECT_EQ(ret, -456);

    ret = A.myAtoi("    -42");
    EXPECT_EQ(ret, -42);

    ret = A.myAtoi("4193 with words");
    EXPECT_EQ(ret, 4193);

    ret = A.myAtoi("words and 987");
    EXPECT_EQ(ret, 0);

    ret = A.myAtoi("-91283472332");
    EXPECT_EQ(ret, -2147483648);
}