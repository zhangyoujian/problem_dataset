#include <iostream>
using namespace std;
class Solution_11 {
public:
int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;
        
        while (left <= right) {
            int max = height[left] < height[right] ? height[left] : height[right];
            int ans = max * (right - left);
            ret = ret >= ans ? ret : ans;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
    }
};