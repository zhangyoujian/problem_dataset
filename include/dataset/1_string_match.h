#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
问题概述: 字符串正则表达式匹配
问题详细描述: W是个模式，校验P是否匹配
解法:
状态: pass
*/
class Problem_1 {
public:
    bool isMatch_simple(const char *w, const char *p)
    {
        int pos = 0;
        int W = strlen(w);
        int P = strlen(p);
        for (;pos < W && pos < P; ++pos) {
            if (w[pos] == p[pos] || w[pos] == '?') {
                pos++;
            }
        }
        if (pos == W) {
            return pos == P;
        }

        if (w[pos] == '*') {
            for (int skip = 0; skip + pos < P; ++pos) {
                if (isMatch_simple(w + pos + 1, p + pos + skip)) {
                    return true;
                }
            }
        }
        return false;
    }
};