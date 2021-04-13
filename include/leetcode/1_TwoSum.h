#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution_01 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> dataIndex;
        for (int i = 0; i < nums.size(); ++i) {
            if (dataIndex.find(target - nums[i]) != dataIndex.end()) {
                ret = {dataIndex[target - nums[i]], i};
                return ret;
            } else {
                dataIndex[nums[i]] = i;
            }
        }
        return ret;
    }
};