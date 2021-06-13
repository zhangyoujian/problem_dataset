#include <iostream>
using namespace std;
class Solution_10 {
public:
    bool MatchInner(const char *s, const char *p)
    {
        if ((*s=='\0') && (*p=='\0')) {
            return true;
        }
        if (*p == '\0') {
            return false;
        }
        if (*(p + 1) == '*') {
            if(*s == '\0') {
                return MatchInner(s, p + 2);
            } else {
                if (*s == *p || *p == '.') {
                    return MatchInner(s, p + 2) || MatchInner(s + 1, p + 2) || MatchInner(s + 1, p);
                }
                return MatchInner(s, p + 2);
            }
        } else {
            if ((*s !='\0') && (*s == *p || *p == '.')) {
                return MatchInner(s + 1, p + 1);
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return MatchInner(s.c_str(), p.c_str());
    }
};