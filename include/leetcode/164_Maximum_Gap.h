#include <iostream>
#include <vector>
using namespace std;
#define MAX_BUF_SIZE    1000000000
class Solution_164 {
public:
    int maximumGap(vector<int>& nums) {
        unsigned char count[MAX_BUF_SIZE] = {0};
        unsigned int maxVal = 0;
        unsigned int minVal = 0x7FFFFFFF;
        for (auto i : nums) {
            if (i > maxVal) {
                maxVal = i;
            }
            if (i < minVal) {
                minVal = i;
            }
        }
        
        int ret = 0;
        unsigned int low = 0;
        unsigned int high = 0;
        while (high <= maxVal) {
            if (count[high] != 0) {
                if (count[low] != 0) {
                    if (high - low > ret) {
                        ret = high - low;
                    }
                }
                low = high;
            }
            high++;
        }
        return ret;
    }
};