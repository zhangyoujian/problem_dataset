#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution_16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = abs(nums[0] + nums[1] + nums[2] - target);
        int ret = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int a = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int b = nums[left];
                int c = nums[right];
                int sum = target - a - b -c;
                if (abs(sum) < closestSum) {
                    ret = a + b + c;
                    closestSum = abs(sum);
                }
                if (sum == 0) {
                    return ret;
                } else if (sum < 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ret;
    }
};