#include <iostream>
#include<string>
#include<unordered_map.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> recoder;
        int curSubstrLen = 0;
        int maxSubStrLen = 0;
        for(size_t i = 0; i < s.length(); ++i) {
            int index = recoder.count(s[i]) == 0 ? -1 : recoder[s[i]];
            if (index == -1 || (i - index) > curSubstrLen) {
                curSubstrLen++;
                if (curSubstrLen > maxSubStrLen) {
                    maxSubStrLen = curSubstrLen;
                }
            } else {
                curSubstrLen = i - index;
            }
            recoder[s[i]] = i;
        }
        return maxSubStrLen;
    }
};