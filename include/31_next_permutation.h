#include <iostream>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int m = -1;
        int n = N-1;
        for (int i = N-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) {
                m = i;
                break;
            }
        }
        if (m >= 0) {
            for (int i = N-1; i >=0; --i) {
                if (nums[i] > nums[m]) {
                    n = i;
                    break;
                }
            }
            swap(nums[m], nums[n]);
        }
        reverse(nums.begin() + m + 1, nums.end());
    }
};