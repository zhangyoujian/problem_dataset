#include<iostream>
using namespace std;

class Solution_44 {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        int pos = 0;
        while (pos < n && pos < m && (p[pos] == s[pos] || p[pos] == '?')) {
            pos++;
        }

        if (pos == m) {
            return pos == n;
        }

        if (p[pos] == '*') {
            for (int step = pos; step <= n; ++step) {
                if (isMatch(s.substr(step), p.substr(pos + 1))) {
                    return true;
                }
            }
        }
        return false;
    }
};