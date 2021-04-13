#include <iostream>
#include <string.h>
using namespace std;

class Solution_32 {
public:
    int longestValidParentheses(string s) {
        int maxMatch = 0;
        int len = s.length();
        if (len <= 1) {
            return maxMatch;
        }
        int *cache = new int[len];
        memset(cache, 0, sizeof(int) * len);
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    cache[i] = (i >= 2 ? cache[i - 2] : 0) + 2;
                } else if ((i - cache[i - 1]) > 0 && s[i - cache[i - 1] - 1] == '(') {
                    cache[i] = cache[i - 1] + 2 + ((i - cache[i - 1]) >= 2 ? cache[i - cache[i - 1] - 2] : 0);
                }
                maxMatch = max(cache[i], maxMatch);
            }
        }
        delete []cache;
        return maxMatch;
    }
};