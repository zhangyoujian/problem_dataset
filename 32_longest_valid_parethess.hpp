#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxMatch = 0;
        int len = s.length();
        if (len <= 1) {
            return maxMatch;
        }
        int *cache = new int[len];
        memset(cache, 0, sizeof(int)*len);
        for(int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                cache[i] = 0;
            } else {
                if (i > 0 && s[i-1] == '(') {
                    cache[i] = ((i-1)>0 ? cache[i-2]: 0) + 2;
                } else if (i > 0 && (i - cache[i-1]) >= 0) {
                    if (s[i - cache[i - 1]] == '(') {
                        cache[i] = cache[i-1] + 2;
                        if (i - cache[i-1] > 0) {
                            cache[i] = cache[i] + cache[i - cache[i-1] - 1];
                        }
                    }
                }
            }
            maxMatch = max(maxMatch, cache[i]);
        }
        return maxMatch;
    }
};