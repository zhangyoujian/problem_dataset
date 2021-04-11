#include <iostream>
using namespace std;
#define MAX_INT_VALUE   0x7FFFFFFF
#define MIN_INT_VALUE   0x80000000

inline bool IsDigit(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

class Solution_08 {
public:
    int myAtoi(string s) {
        int symbol = 1;
        const char *ptr = s.data();
        long long num = 0;

        while (*ptr == ' ') {
            ptr++;
        }

        if (*ptr == '-') {
            symbol = -1;
            ptr++;
        } else if (*ptr == '+') {
            ptr++;
        }

        if (*ptr == '\0') {
            return 0;
        }

        while (*ptr != '\0' && IsDigit(*ptr)) {
            num = num * 10 + (*ptr - '0');
            long long tmp = num * symbol;
            if (tmp < (int)MIN_INT_VALUE) {
                return MIN_INT_VALUE;
            } else if (tmp > (int)MAX_INT_VALUE) {
                return MAX_INT_VALUE;
            }
            ptr++;
        }
        return (int)(num * symbol);
    }
};