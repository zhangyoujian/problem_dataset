#include "leetcode_pub.h"

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

TEST_F(test_leetcode, 10_regular_expression_matching)
{
    Solution_10 A;
    EXPECT_EQ(A.isMatch("aa", "a"), false);
    EXPECT_EQ(A.isMatch("aa", "a*"), true);
    EXPECT_EQ(A.isMatch("ab", ".*"), true);
    EXPECT_EQ(A.isMatch("aab", "c*a*b"), true);
    EXPECT_EQ(A.isMatch("mississippi", "mis*is*p*."), false);
    EXPECT_EQ(A.isMatch("bbbba", ".*a*a"), true);
}


TEST_F(test_leetcode, 11_Container_With_Most_Water)
{
    Solution_11 A;
    vector<int> a = {1, 1};
    EXPECT_EQ(A.maxArea(a), 1);

    vector<int> b = {4,3,2,1,4};
    EXPECT_EQ(A.maxArea(b), 16);

    vector<int> c = {1, 2, 1};
    EXPECT_EQ(A.maxArea(c), 2);

    vector<int> e = {2,3,4,5,18,17,6};
    EXPECT_EQ(A.maxArea(e), 17);
}


TEST_F(test_leetcode, 16_3Sum_Closest)
{
    Solution_16 A;
    vector<int> nums = {0, 2, 1, -3};
    int target = 1;
    int ret = A.threeSumClosest(nums, target);
    EXPECT_EQ(ret, 0);
}

TEST_F(test_leetcode, 30_Substring_with_Concatenation_of_All_Words)
{
    Solution_30 A;

    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};

    vector<int> ret = A.findSubstring(s, words);
    EXPECT_EQ(ret.size(), 0);
}

TEST_F(test_leetcode, 76_Minimum_Window_Substring)
{
    Solution_76 A;
    string ret = A.minWindow("ADOBECODEBANC", "ABC");
    EXPECT_EQ(strcmp(ret.c_str(), "BANC"), 0);
}

TEST_F(test_leetcode, 410_Split_Array_Largest_Sum)
{
    Solution_410 A;
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    int ret = A.splitArray(nums, m);
    EXPECT_EQ(ret, 18);

    nums = {1, 4, 4};
    m = 3;
    ret = A.splitArray(nums, m);
    EXPECT_EQ(ret, 4);
}

TEST_F(test_leetcode, 93_CopyIpAddr)
{
    Solution_93 A;
    string args = "25525511135";
    vector<string> ret = A.restoreIpAddresses(args);
    EXPECT_EQ(2, ret.size());
    printf("[\n");
    for (int i = 0; i < ret.size(); ++i) {
        printf("%s", ret[i].c_str()); 
    }
    printf("]\n");
}

TEST_F(test_leetcode, 146_LRU_Cache)
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache->get(1)<<endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache->get(2)<<endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lRUCache->get(1)<<endl;    // return -1 (not found)
    cout<<lRUCache->get(3)<<endl;    // return 3
    cout<<lRUCache->get(4)<<endl;    // return 4
}
