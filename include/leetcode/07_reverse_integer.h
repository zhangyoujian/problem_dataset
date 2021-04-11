#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_INT_VALUE  0x7FFFFFFF
#define MIN_INT_VALUE  0x80000000
#define MAX_BUFF_SIZE  16

class Solution_07 {
public:
    int reverse(int x) {
        char digit[MAX_BUFF_SIZE] = {0};
        long long num = x;
        int cnt = 0;
        int symbol = (num < 0) ? -1 : 1;
        num = num * symbol;
        while (num != 0) {
            digit[cnt++] = num % 10 + '0';
            num /= 10;
        }
        long long tmp = atoll(digit) * symbol;
        if (tmp < (int)MIN_INT_VALUE || tmp > (int)MAX_INT_VALUE) {
            return 0;
        }
        return (int)tmp;
    }
};